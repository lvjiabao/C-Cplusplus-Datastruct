#include<iostream>
using namespace std;

//对称矩阵的实现
template<typename T>
class SymmetricMatrix
{
public:
	
	SymmetricMatrix(T*arr, size_t size)
		:_size(size)
	{
		matrix = new T[size*(size + 1) / 2];
		int index = 0;
		for (size_t i = 0; i < size;++i)
		for (size_t j = 0; j < size; ++j)
		{
			if (i >= j)
			{
				matrix[index++] = arr[i*size + j];
			}
		}
	}
	void Print()
	{
		for (int i = 0; i < _size; i++)
		{
			for (int j = 0; j < _size; j++)
			{
				if (i >= j)
					cout << matrix[(1 + i)*i / 2 + j] << " ";
				else
					cout << matrix[(1 + j)*j / 2 + i] << " ";
			}
			cout << endl;
		}
	}
private:
	T*matrix;
	size_t _size;
};


//稀疏矩阵的存储
#include<vector>
template<typename T>
struct message
{
	message(int row, int col, int value)
	:_row(row)
	, _col(col)
	, _value(value)
	{}
	int _row;
	int _col;
	T _value;
};


template<typename T>
class SparseMatrix
{
public:
	SparseMatrix()
	{}
	SparseMatrix(T*arr,T invaild, int row, int col)
		:_arr(arr)
		,_invaild(invaild)
		,_row(row)
		, _col(col)
	{
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (arr[i*col + j] != invaild)
				{
					message<T>m(i, j, arr[i*col + j]);
					s.push_back(m);
				}
			}
		}
	}

	//拷贝构造
	SparseMatrix(const SparseMatrix<T>&copy)
	{
		s = copy.s;
		_arr=copy._arr;
		_invaild=copy._invaild;
		_row=copy._row;
		_col=copy._col;
	}

	//输出运算符的重载
	template<typename T>
	friend ostream&operator<<(ostream&_out, SparseMatrix<T>&sm);

	//非快速逆置
	SparseMatrix<T> Translate()
	{
		SparseMatrix<T>tmp(*this);
		int index = 0;
		tmp.s.clear();
		for (int i = 0; i < tmp._col; ++i)
		for (int j = 0; j < tmp._row; ++j)
		{
			if (tmp._arr[j*tmp._col + i] != tmp._invaild)
			{
				message<T>m(i, j, tmp._arr[j*tmp._col + i]);
				tmp.s.push_back(m);
			}
		}
		swap(tmp._row, tmp._col);
		return tmp;
	}

	//快速逆置
	SparseMatrix<T> FastTrans()
	{
		SparseMatrix<T>tmp(*this);
		vector<int>RowCounts(_col,0);
		vector<int>RowStart(_col,0);
		for (int i = 0; i <tmp.s.size();i++)
			RowCounts[tmp.s[i]._col]++;
		for (int i = 1; i <tmp._col; i++)
			RowStart[i] = RowStart[i -1]+RowCounts[i-1];
		for (int i = 0; i < tmp.s.size(); ++i)
		{
			swap(s[i]._row, s[i]._col);
			tmp.s[RowStart[s[i]._row]] = s[i];
			RowStart[s[i]._row]++;
		}
		swap(tmp._col, tmp._row);
		return tmp;
	}

	template<typename T>
	friend SparseMatrix<T> operator+(SparseMatrix<T>&left, SparseMatrix<T>&right);
private:
	vector<message<T> >s;
	T*_arr;
	T _invaild;
	int _row;
	int _col;
};

template<typename T>
ostream&operator<<(ostream&_out, SparseMatrix<T>&sm)
{
	int index = 0;
	for (int i = 0; i < sm._row; ++i)
	{
		for (int j = 0; j < sm._col; ++j)
		{
			if (index < sm.s.size() && sm.s[index]._row == i&&sm.s[index]._col == j)
			{
				_out << sm.s[index++]._value << " ";
			}
			else
				_out << sm._invaild << " ";
		}
		_out << endl;
	}
	return _out;
}

template<typename T>
SparseMatrix<T> operator+(SparseMatrix<T>&left, SparseMatrix<T>&right)
{
	SparseMatrix<T>tmp(left);
	tmp.s.clear();
	int indexleft = 0;
	int indexright = 0;
	while (indexleft<left.s.size()||indexright<right.s.size())
	{
		if (left.s[indexleft]._value + right.s[indexleft]._value == tmp._invaild)
		{
			indexleft++;
			indexright++;
			continue;
		}
		if (left.s[indexleft]._row > right.s[indexright]._row)
		{
			message<T>m(right.s[indexright]._row, right.s[indexright]._col, right.s[indexright]._value);
				tmp.s.push_back(m);
			indexright++;
		}
		else if (left.s[indexleft]._row < right.s[indexleft]._row )
		{
			message<T>m(left.s[indexleft]._row, left.s[indexleft]._col, left.s[indexleft]._value);
				tmp.s.push_back(m);
			indexleft++;
		}
		else
		{
			if (left.s[indexleft]._col > right.s[indexright]._col)
			{
				message<T>m(right.s[indexright]._row, right.s[indexright]._col, right.s[indexright]._value);
					tmp.s.push_back(m);
				indexright++;
			}
			else if (left.s[indexleft]._col < right.s[indexright]._col)
			{
				message<T>m(left.s[indexleft]._row, left.s[indexleft]._col, left.s[indexleft]._value);
					tmp.s.push_back(m);
				indexleft++;
			}
			else
			{
				message<T>m(left.s[indexleft]._row, left.s[indexleft]._col, left.s[indexleft]._value + right.s[indexleft]._value);
					tmp.s.push_back(m);
				indexleft++;
				indexright++;
			}
		}	
	}
	return tmp;
}


void test1()
{

	int arr[5][5] =
	{
		{ 0, 1, 2, 3, 4 },
		{ 1, 0, 1, 2, 3 },
		{ 2, 1, 0, 1, 2 },
		{ 3, 2, 1, 0, 1 },
		{ 4, 3, 2, 1, 0 }
	};
	SymmetricMatrix<int>m(arr[0], 5);
	m.Print();
}

void test2()
{
	int array[6][5] = {
		{ 1, 0, 3, 0, 5 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 1, 0, 3, 0, 5 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 } };
	SparseMatrix<int> s(array[0], 0, 6, 5);
	cout << s << endl;
	cout << s.FastTrans() << endl;
	//cout << s.Translate() << endl;
}

void test3()
{
	int array1[6][5] = {
		{ 1, 0, 3, 0, 5 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 1, 0, 3, 0, 5 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 } };
	int array2[6][5] = {
		{ 1, 0, 3, 0, 5 },
		{ 1, 0, 3, 0, 5 },
		{ 0, 0, 0, 0, 0 },
		{ 1, 0, 3, 0, 5 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 } };
	SparseMatrix<int> s1(array1[0], 0, 6, 5);
	SparseMatrix<int> s2(array2[0], 0, 6, 5);
	cout << s1 + s2;
}

int main()
{
	test3();
	return 0;
}