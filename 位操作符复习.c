#include<stdio.h>

//统计二进制数中1的个数
int count_one_num(int num)
{
	int i = 0, ret = 0;
	while (num)
	{
		num = num&(num - 1);
		ret++;
	}
	return ret;
}

//整数M,N中有多少个比特位不同
int count_diff_num(int m, int n)
{
	int num = m^n;
	return count_one_num(num);
}


//判断一个数是不是2的n次方
int judge(int num)
{
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (1 << i == num)
			return 1;
	}
	return 0;
}

//宏定义，实现一个数奇数偶数位的交换
#define FUN(x) ((x&0x55555555)<<1|(x&0xaaaaaaaa)>>1)


//将一个数的二进制逆序，然后输出逆序之后的数
int reversenum(int num)
{
	int i = 0;
	int ret = 0;
	for (i = 0; i < 32; i++)
	{
		ret <<= 1;
		ret |= (num >> i)&1;
	}
	return ret;
}

//将一个数的指定位置0或置1
int set_pos_bit(int num, int pos, int bit)
{
	int Bitnum = 1 << (pos - 1);
	if (bit == 0)
	{
		num &= ~Bitnum;
	}
	else
	{
		num |= Bitnum;
	}
	return num;
}

//一组数中只有一个数只出现一次，其余都是成对出现，找出这个数
int find_single_num(int*arr, int len)
{
	int i = 0;
	int ret = 0;
	for (i = 0; i < len; i++)
	{
		ret ^= arr[i];
	}
	return ret;
}

//一组数中只有两个数只出现一次，其余都是成对出现，找出这个数
void find_two_num(int*arr, int len,int*num1,int*num2)
{
	int xor = 0;
	int i = 0;
	int pos = 0;
	for (i = 0; i < len; i++)
		xor ^= arr[i];
	for (i = 0; i < len;i++)
	if (xor >> i == 1)
	{
		pos = i;
		break;
	}
	for (i = 0; i < len; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
			(*num1) ^= arr[i];
	}
	(*num2) = (*num1) ^ xor;
}


int main()
{
	int arr[10] = { 1, 2, 3, 4, 5,7, 5, 4, 3, 2 };
	int num1 = 0, num2 = 0;
	find_two_num(arr, 10, &num1, &num2);
	printf("%d  %d\n", num1, num2);
	printf("%d\n", find_single_num(arr, 9));
	printf("%d\n", set_pos_bit(10, 3, 1));
	printf("%d\n", reversenum(10));
	printf("%d\n", FUN(10));
	printf("%d\n", count_one_num(14));
	printf("%d\n", count_diff_num(1999,2299));
	return 0;
}