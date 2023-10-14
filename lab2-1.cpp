#include <iostream>
using namespace std;

/*
* 函数作用：打印数组中的向量
* 返回值：空
* 函数参数：arr为需要排序的数组，
		   arr_size为数组的长度
*/
void printList(int* arr, int arr_size);

/*
* 函数作用：向无序向量中的位置p（输入应有合法判断）插入元素 e。，第1个数p表示待插入位置的秩，第2个数e表示待插入的数据元素。
* 返回值：空
* 函数参数：arr为需要插入的数组，
*		   arr_new为用于过渡的数组
*		   p表示待插入位置的秩
*		   e表示待插入的数据元素
*		   arr_size为arr数组的长度
*/
void insert(int* arr, int* arr_new, int p, int e, int* arr_size);

/*
* 函数作用：删除无序向量中位置p（输入应有合法判断）起的n个数据元素，并返回被删除的第一个数据元素的值
* 返回值：空
* 函数参数：arr为需要删除的数组，
*		   arr_new为用于过渡的数组
*		   p为要删除的起始位置的秩
*		   n为要删除的元素个数
*		   arr_size为arr数组的长度
*/
int remove(int* arr, int* arr_new, int p, int n, int* arr_size);

/*
* 函数作用：从键盘输入1个数（e），在无序向量中查找该数的位置。
* 返回值：int 输出该结点的秩
* 函数参数：arr为需要删除的数组，
*		   e为需要查找的值
*		   arr_size为arr数组的长度
*/
int find(int* arr, int e, int* arr_size);
int main()
{
	int* arr = new int[10];
	int arr_size = 10;//代表向量空间中的元素数量
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand();
	}
	printList(&arr[0], arr_size);

	string judge = "1";
	while (judge == "1" || judge == "2" || judge == "3")
	{
		cout << endl << "插入参数测试请输入1，删除参数测试请输入2，查找操作请输入3，若想退出操作请随意输入" << endl;
		cin >> judge;
		if (judge == "1")
		{
			cout << "从键盘输入2个数（p，e），第1个数p表示待插入位置的秩，第2个数e表示待插入的数据元素" << endl;
			int p = 0, e = 0;
			cin >> p;
			cin >> e;
			int* arr_new = new int[arr_size + 1];
			insert(&arr[0], &arr_new[0], p, e, &arr_size);
			printList(&arr_new[0], arr_size);
			arr = new int[arr_size];
			for (int i = 0; i < arr_size; i++)
			{
				arr[i] = arr_new[i];
			}
			delete[] arr_new;
		}
		if (judge == "2")
		{
			cout << "从键盘输入2个数（p，n），第1个数p为要删除的起始位置的秩，第2个数n为要删除的元素个数" << endl;
			int p = 0, n = 0;
			cin >> p;
			cin >> n;
			int* arr_new = new int[arr_size - n];
			int num = remove(&arr[0], &arr_new[0], p, n, &arr_size);

			printList(&arr_new[0], arr_size);
			
			arr = new int[arr_size];
			for (int i = 0; i < arr_size; i++)
			{
				arr[i] = arr_new[i];
			}
			delete[] arr_new;
		}
		if (judge == "3")
		{
			cout << "从键盘输入1个数（e），在无序向量中查找该数的位置" << endl;
			int e = 0;
			cin >> e;
			int position = find(&arr[0], e, &arr_size);
			if (position == -1)
				cout << "无此元素" << endl;
			else
				cout << "该结点的秩为：" << position << endl;
		}
	}
	
	
	delete[] arr;
}

void printList(int* arr, int arr_size)
{
	cout << "向量输出如下：" << endl;
	for (int i = 0; i < arr_size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insert(int* arr, int* arr_new, int p, int e, int* arr_size)
{
	if (p < 0)
	{
		cout << "请注意输入的合法性问题" << endl;
		for (int i = 0; i < *arr_size; i++)
		{
			arr_new[i] = arr[i];
		}
	}
		
	else if (p > *arr_size)
	{
		cout << "由于输入的秩超过向量空间中向量的个数，所以把其插入到最后" << endl;
		for (int i = 0; i < *arr_size; i++)
		{
			arr_new[i] = arr[i];
		}
		arr_new[*arr_size] = e;
		*arr_size = *arr_size + 1;
	}		
	else
	{
		for (int i = 0; i <= p; i++)
		{
			arr_new[i] = arr[i];
		}
		arr_new[p] = e;
		for (int i = p + 1; i <= *arr_size; i++)
		{
			arr_new[i] = arr[i - 1];
		}
		*arr_size = *arr_size + 1;
		cout << "向量插入成功" << endl;
	}
}

int remove(int* arr, int* arr_new, int p, int n, int* arr_size)
{
	int num;//代表被删除的第一个数据元素的值
	if (p < 0)
	{
		cout << "请注意输入的合法性问题" << endl;
		for (int i = 0; i < *arr_size; i++)
		{
			arr_new[i] = arr[i];
		}
		return -1;
	}
	else if (p > *arr_size)
	{
		cout << "由于输入的秩超过向量空间中向量的个数，所以保持不变" << endl;
		for (int i = 0; i < *arr_size; i++)
		{
			arr_new[i] = arr[i];
		}
	}
	else
	{
		for (int i = 0; i < p; i++)
		{
			arr_new[i] = arr[i];
		}
		num = arr[p];
		for (int i = p + n; i <= *arr_size; i++)
		{
			arr_new[i - n] = arr[i];
		}
		if ((p + n) > *arr_size)
			*arr_size = p;
		else
			*arr_size = *arr_size - n;
		cout << "向量删除成功" << endl;
		cout << "被删除的第一个数据元素的值为" << num << endl;
	}
	return num;
}

int find(int* arr, int e, int* arr_size)
{
	int position = -1;
	for (int i = 0; i < *arr_size; i++)
	{
		if (arr[i] == e)
		{
			position = i;
		}
	}
	return position;
}
