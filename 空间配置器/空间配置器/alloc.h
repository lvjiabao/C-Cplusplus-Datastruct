template<bool threads, int inst>//////inst ��Ԥ���Ĳ������Ժ���
class__DefaultAllocTemplate
{
public:
	enum{ __ALIGN = 8 }; //���л�׼ֵ��Ҳ�����м����
	enum{ __MAX_BYTES = 128 }; //���ֵ
	enum{ __NFREELISTS = __MAX_BYTES / __ALIGN }; //��������С
	static size_t ROUND_UP(size_t bytes)
	{
		//����
		return((bytes + __ALIGN - 1) & ~(__ALIGN - 1));
	}
	static size_t FREELIST_INDEX(size_t bytes)
	{
		// bytes == 9
		// bytes == 8
		// bytes == 7
		return((bytes + __ALIGN - 1) / __ALIGN - 1);
	}
	union Obj
	{
		union Obj*_freeListLink; //ָ����һ���ڴ���ָ��
		char _clientData[1]; /* The client sees this.*/
	};
	static Obj*volatile_freeList[__NFREELISTS]; //��������
	static char*_startFree; //�ڴ��ˮλ�߿�ʼ
	static char*_endFree; //�ڴ��ˮλ�߽���
	static size_t _heapSize; //��ϵͳ�ѷ�����ܴ�С
	//��ȡ����ڴ���뵽����������
	static void*Refill(size_t n);
	//���ڴ���з������ڴ�
	static char*ChunkAlloc(size_t size, int&nobjs);
	static void*Allocate(size_t n);
	static void Deallocate(void*p, size_t n);
	static void*Reallocate(void*p, size_t old_sz, size_t new_sz);
};
//��ʼ��ȫ�־�̬����
template<bool threads, int inst>
//��һ��typename ʹ��������������һ�����õı�����������Ҫ��ʼ�������Ժ������
typename __DefaultAllocTemplate<threads, inst>::Obj*volatile __DefaultAllocTemplate<threads, inst>::_freeList[__DefaultAllocTemplate<threads, inst>::__NFREELISTS];
template<bool threads, int inst>
char*__DefaultAllocTemplate<threads, inst>::_startFree = 0;
template<bool threads, int inst>
char*__DefaultAllocTemplate<threads, inst>::_endFree = 0;
template<bool threads, int inst>
size_t __DefaultAllocTemplate<threads, inst>::_heapSize = 0;;


template<bool threads, int inst>
void*__DefaultAllocTemplate<threads, inst>::Refill(size_t n)
{
	__TRACE_DEBUG("(n:%u)\n", n);
	//
	//�����n bytes���ڴ�
	//����������ܷ�����ٷ������
	//
	int nobjs = 20;
	char*chunk = ChunkAlloc(n, nobjs);
	//���ֻ���䵽һ�飬��ֱ������ڴ档
	if (nobjs == 1)
		return chunk;
	Obj*result, *cur;
	size_t index = FREELIST_INDEX(n);
	result = (Obj*)chunk;
	//��ʣ��Ŀ����ӵ�������������
	cur = (Obj*)(chunk + n);
	_freeList[index] = cur
	//֮���Դ�2��ʼ��0���������ˣ�1�Ѿ�������������
	for (int i = 2; i < nobjs; ++i)
	{
		cur->_freeListLink = (Obj*)(chunk + n*i);
		cur = cur->_freeListLink;
	}
	cur->_freeListLink = NULL;
	return result;
}


template<bool threads, int inst>
char*__DefaultAllocTemplate<threads, inst>::ChunkAlloc(size_t size, int&nobjs)
{
	__TRACE_DEBUG("(size: %u, nobjs: %d)\n", size, nobjs);
	char*result;
	size_t bytesNeed = size*nobjs;
	size_t bytesLeft = _endFree - _startFree;
	//
	// 1.�ڴ���е��ڴ��㹻��bytesLeft>=bytesNeed����ֱ�Ӵ��ڴ����ȡ��
	// 2.�ڴ���е��ڴ治�㣬���ǹ�һ��bytesLeft >= size����ֱ��ȡ�ܹ�ȡ������
	// 3.�ڴ���е��ڴ治�㣬���ϵͳ�ѷ������ڴ浽�ڴ���С�
	//
	if (bytesLeft >= bytesNeed)
	{
		__TRACE_DEBUG("�ڴ�����ڴ��㹻����%d������\n", nobjs);
		result = _startFree;
		_startFree += bytesNeed;
	}
	else if(bytesLeft >= size)
	{
		__TRACE_DEBUG("�ڴ�����ڴ治������%d������ֻ�ܷ���%d������\n", nobjs, bytesLeft / size);
		result = _startFree;
		nobjs = bytesLeft / size;
		_startFree += nobjs*size;
	}
	else
	{
		//���ڴ���л���С��ʣ���ڴ棬����ͷ�嵽���ʵ���������
		if (bytesLeft > 0)
		{
			size_t index = FREELIST_INDEX(bytesLeft);
			((Obj*)_startFree)->_freeListLink = _freeList[index];
			_freeList[index] = (Obj*)_startFree;
			_startFree = NULL;
			__TRACE_DEBUG("���ڴ����ʣ��Ŀռ䣬�����freeList[%d]\n", index);
		}
		//��ϵͳ�ѷ�������+�ѷ����heapSize/8���ڴ浽�ڴ����
		size_t bytesToGet = 2 * bytesNeed + ROUND_UP(_heapSize >> 4);
		_startFree = (char*)malloc(bytesToGet);
		__TRACE_DEBUG("�ڴ�ؿռ䲻�㣬ϵͳ�ѷ���%u bytes�ڴ�\n", bytesToGet);
		//
		//������֮�١�
		//�����ϵͳ�����ڴ����ʧ�ܣ����Ե����������и���Ľڵ��з���
		//
		if (_startFree == NULL)
		{
			/////������һ�����ʣ�Ϊ�δ�size��ʼ��������size+1��ʼ
			__TRACE_DEBUG("ϵͳ�������㹻������֮�£����ܵ����������п���\n");
			for (int i = size; i <= __MAX_BYTES; i += __ALIGN)
			{
				Obj*head = _freeList[FREELIST_INDEX(size)];
				if (head)
				{
					_startFree = (char*)head;
					head = head->_freeListLink;
					_endFree = _startFree + i;
					return ChunkAlloc(size, nobjs);
				}
			}
			//
			//��ɽ��ˮ�������һ�����ݡ�
			//����������Ҳû�з��䵽�ڴ棬���ٵ�һ���������з����ڴ棬
			//һ���������п��������õĴ����ڴ棬�����ܷ��䵽�ڴ档
			//

			//Ϊʲô��ô˵���Լ��ռ��������������˾��
			__TRACE_DEBUG("ϵͳ�Ѻ��������������ڴ棬һ�������������һ������\n");
			_startFree = (char*)MallocAlloc::Allocate(bytesToGet);
		}
		//��ϵͳ�ѷ�������ֽ��������������´η���ʱ���е��ڣ�
		_heapSize += bytesToGet;
		_endFree = _startFree + bytesToGet;
		//�ݹ���û�ȡ�ڴ�
		return ChunkAlloc(size, nobjs);
	}
	return result;
}


template<bool threads, int inst>
void*__DefaultAllocTemplate<threads, inst>::Allocate(size_t n)
{
	__TRACE_DEBUG("(n: %u)\n", n);
	//
	//��n > __MAX_BYTES��ֱ����һ���������л�ȡ
	//�����ڶ����������л�ȡ
	//
	if (n > __MAX_BYTES)
	{
		return MallocAlloc::Allocate(n);
	}
	size_t index = FREELIST_INDEX(n);
	void*ret = NULL;
	//
	// 1.�������������û���ڴ���ͨ��Refill�������
	// 2.�����������������ֱ�ӷ���һ���ڵ���ڴ�
	// ps:���̻߳�����Ҫ���Ǽ���
	//
	Obj*head = _freeList[index];
	if (head == NULL)
	{
		return Refill(ROUND_UP(n));
	}
	else
	{
		__TRACE_DEBUG("��������ȡ�ڴ�:_freeList[%d]\n", index);
		_freeList[index] = head->_freeListLink;
		return head;
	}
}
template<bool threads, int inst>
void __DefaultAllocTemplate<threads, inst>::Deallocate(void*p, size_t n)
{
	__TRACE_DEBUG("(p:%p, n: %u)\n", p, n);
	//
	//��n > __MAX_BYTES��ֱ�ӹ黹��һ��������
	//�����ڷŻض�������������������
	//
	if (n > __MAX_BYTES)
	{
		MallocAlloc::Deallocate(p, n);
	}
	else
	{
		// ps:���̻߳�����Ҫ���Ǽ���
		size_t index = FREELIST_INDEX(n);
		//ͷ�����������
		Obj*tmp = (Obj*)p;
		tmp->_freeListLink = _freeList[index];
		_freeList[index] = tmp;
	}
}
template<bool threads, int inst>
void*__DefaultAllocTemplate<threads, inst>::Reallocate(void*p, size_t old_sz, size_t new_sz)
{
	void*result;
	size_t copy_sz;
	if (old_sz > (size_t)__MAX_BYTES&&new_sz > (size_t)__MAX_BYTES) {
		return(realloc(p, new_sz));
	}
	if (ROUND_UP(old_sz) == ROUND_UP(new_sz))
		return p;
	result = Allocate(new_sz);
	copy_sz = new_sz > old_sz ? old_sz : new_sz;
	memcpy(result, p, copy_sz);
	Deallocate(p, old_sz);
	return result;
}
// ͨ��__TRACE_DEBUG ���׺в���
// �����ڴ�ص�һ������������������
void Test1()
{
	// ���Ե���һ�������������ڴ�
	cout << " ���Ե���һ�������������ڴ� " << endl;
	char*p1 = SimpleAlloc< char, Alloc>::Allocate(129);
	SimpleAlloc<char, Alloc>::Deallocate(p1, 129);
	// ���Ե��ö��������������ڴ�
	cout << " ���Ե��ö��������������ڴ� " << endl;
	char*p2 = SimpleAlloc< char, Alloc>::Allocate(128);
	char*p3 = SimpleAlloc< char, Alloc>::Allocate(128);
	char*p4 = SimpleAlloc< char, Alloc>::Allocate(128);
	char*p5 = SimpleAlloc< char, Alloc>::Allocate(128);
	SimpleAlloc<char, Alloc>::Deallocate(p2, 128);
	SimpleAlloc<char, Alloc>::Deallocate(p3, 128);
	SimpleAlloc<char, Alloc>::Deallocate(p4, 128);
	SimpleAlloc<char, Alloc>::Deallocate(p5, 128);
	for (int i = 0; i < 21; ++i)
	{
		printf(" ���Ե�%d�η��� \n", i + 1);
		char*p = SimpleAlloc< char, Alloc>::Allocate(128);
	}
}
// �������ⳡ��
void Test2()
{
	cout << " �����ڴ�ؿռ䲻������ " << endl;
	// 8*20->8*2->320
	char*p1 = SimpleAlloc< char, Alloc>::Allocate(8);
	char*p2 = SimpleAlloc< char, Alloc>::Allocate(8);
	cout << " �����ڴ�ؿռ䲻�㣬ϵͳ�ѽ��з��� " << endl;
	char*p3 = SimpleAlloc< char, Alloc>::Allocate(12);
}
// ����ϵͳ���ڴ�ľ��ĳ���
void Test3()
{
	cout << " ����ϵͳ���ڴ�ľ� " << endl;
	SimpleAlloc<char, Alloc>::Allocate(1024 * 1024 * 1024);
	//SimpleAlloc<char, Alloc>::Allocate(1024*1024*1024);
	SimpleAlloc<char, Alloc>::Allocate(1024 * 1024);
	// ���ò��ԣ�˵��ϵͳ����С���ڴ���������Ǻ�ǿ�ġ�
	for (int i = 0; i < 100000; ++i)
	{
		char*p1 = SimpleAlloc< char, Alloc>::Allocate(128);
	}
}