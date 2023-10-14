#include <iostream>
#include<ctime>
using namespace std;

/*
* 函数作用：使用迭代算法对数组进行冒泡排序
* 返回值：空
* 函数参数：num为需要排序的数组，
		   length为数组的长度
*/
void sort(int* num, int length)//使用迭代算法
{
	int flag = 0;
	for (int i = 1; i < length; i++)
	{
		for (int j = 1; j <= length - i; j++)
		{
			if (*(num + j - 1) > *(num + j))
			{
				int temp = *(num + j - 1);
				*(num + j - 1) = *(num + j);
				*(num + j) = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			return;
	}
}

/*
* 函数作用：使用递归算法对数组进行冒泡排序
* 返回值：空
* 函数参数：num为需要排序的数组，
		   length为数组的长度
*/
void recursion(int* num, int length)
{
	if (length == 0)
		return;
	int flag = 0;
	for (int j = 1; j < length; j++)
	{
		if (*(num + j - 1) > *(num + j))
		{
			int temp = *(num + j - 1);
			*(num + j - 1) = *(num + j);
			*(num + j) = temp;
			flag = 1;
		}
	}
	if (flag == 0)
		return;
	return recursion(num, length - 1);
}
int main()
{
	int length = 1000;
	int* num1 = new int[1000];
	for (int i = 0; i < length; i++)
	{
		num1[i] = rand();
	}
	clock_t start, end;
	start = clock();//返回单位是毫秒
	sort(&num1[0], length);
	end = clock();
	start = end - start;
	cout << "1000个随机排序数使用迭代算法运行时间为：" << start << "毫秒" << endl;

	for (int i = 0; i < length; i++)
	{
		num1[i] = length - i;
	}
	start = clock();
	sort(&num1[0], length);
	end = clock();
	start = end - start;
	cout << "1000个逆序排序数使用迭代算法运行时间为：" << start << "毫秒" << endl;

	delete[] num1;

	length = 10000;
	int* num2 = new int[10000];
	for (int i = 0; i < length; i++)
	{
		num2[i] = rand();
	}
	start = clock();
	sort(&num2[0], length);
	end = clock();
	start = end - start;
	cout << "10000个随机排序数使用迭代算法运行时间为：" << start << "毫秒" << endl;

	for (int i = 0; i < length; i++)
	{
		num2[i] = length - i;
	}
	start = clock();
	sort(&num2[0], length);
	end = clock();
	start = end - start;
	cout << "10000个逆序排序数使用迭代算法运行时间为：" << start << "毫秒" << endl;

	delete[] num2;
	int* num3 = new int[1000];
	length = 1000;
	for (int i = 0; i < length; i++)
	{
		num3[i] = rand();
	}
	start = clock();
	recursion(&num3[0], length);
	end = clock();
	start = end - start;
	cout << "1000个随机排序数使用递归算法运行时间为：" << start << "毫秒" << endl;

	for (int i = 0; i < length; i++)
	{
		num3[i] = length - i;
	}
	start = clock();
	recursion(&num3[0], length);
	end = clock();
	start = end - start;
	cout << "1000个逆序排序数使用递归算法运行时间为：" << start << "毫秒" << endl;

	delete[] num3;

	length = 10000;
	int* num4 = new int[10000];
	for (int i = 0; i < length; i++)
	{
		num4[i] = rand();
	}
	start = clock();
	recursion(&num4[0], length);
	end = clock();
	start = end - start;
	cout << "10000个随机排序数使用递归算法运行时间为：" << start << "毫秒" << endl;
	delete[] num4;

	int* num5 = new int[10000];
	for (int i = 0; i < length; i++)
	{
		num5[i] = length - i;
	}
	start = clock();
	recursion(&num5[0], length);
	end = clock();
	start = end - start;
	cout << "10000个逆序排序数使用递归算法运行时间为：" << start << "毫秒" << endl;
	delete[] num5;
	return 0;
}