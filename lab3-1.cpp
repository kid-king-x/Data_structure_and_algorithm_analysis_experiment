#include <iostream>
#include <ctime>
using namespace std;

/*
* 给无序数组排序
*/
void sort(int* num, int length);

/*
* 输出向量
*/
void printList(int* arr, int arr_size);

/*
* 给向量插入一个数
* 参数：p为需要插入的秩，e为插入的数
*/
void insert(int* arr, int* arr_new, int p, int e, int* arr_size);

/*
* 给向量删除n个数
* 参数：p为需要删除的秩，n为总共需要删除几个（从秩p开始数n个）
*/
void remove(int* arr, int* arr_new, int p, int n, int* arr_size);

/*
* 顺序查找有序向量中等于e的数据元素
* 参数：num代表有序向量中等于e的数据元素的数量
* 返回值：该数的秩，或者找不到e时候的临近e的前一个数的秩
*/
int LinearSearch(int e, int arr_size, int* arr, int* num);

/*
* 二分查找有序向量中等于e的数据元素
* 参数：num代表有序向量中等于e的数据元素的数量
* 返回值：该数的秩，如果没有找到返回-1
*/
int DichotomiaSerach(int e, int arr_size, int* arr, int* num);

/*
* 分块查找有序向量中等于e的数据元素
* 参数：num代表有序向量中等于e的数据元素的数量
* 返回值：该数的秩，如果没有找到返回-1
*/
int BlockSearch(int e, int arr_size, int* arr, int* num);

int main()
{
	int arr_size = 10000;
	int* arr = new int[arr_size];
	for (int i = 0; i < arr_size; i++)
	{
		arr[i] = rand();
	}
	sort(&arr[0], arr_size);
	printList(&arr[0], arr_size);

	string judge = "1";
	while (judge == "1" || judge == "2" || judge == "3")
	{
		cout << endl << "插入参数测试请输入1，删除参数测试请输入2，查找操作请输入3，若想退出操作请随意输入" << endl;
		cin >> judge;
		if (judge == "1")
		{
			cout << "从键盘输入1个数，我将该数插入到有序向量的适当位置，以保持有序向量的有序性" << endl;
			int e = 0, p = 0, num = 0;
			cin >> e;
			p = LinearSearch(e, arr_size, &arr[0], &num) + 1;
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
			cout << "从键盘输入1个数，我将删除有序向量中所有等于该数的数据元素。若找不到该元素，则会显示“无此元素”" << endl;
			int e = 0, num = 0, p = 0;
			cin >> e;
			p = LinearSearch(e, arr_size, &arr[0], &num) - num + 1;
			if (num == 0)
				cout << "无此元素" << endl;
			else
			{
				int* arr_new = new int[arr_size - num];
				remove(&arr[0], &arr_new[0], p, num, &arr_size);
				printList(&arr_new[0], arr_size);
				arr = new int[arr_size];
				for (int i = 0; i < arr_size; i++)
				{
					arr[i] = arr_new[i];
				}
				delete[] arr_new;
			}
			
		}
		if (judge == "3")
		{
			cout << "从键盘输入1个数，找到有序向量中等于该数的数据元素，并统计数量。若找不到该元素，则显示“无此元素”" << endl;
			int e = 0, num = 0;
			cin >> e;

			clock_t start, end;
			start = clock();
			int position = LinearSearch(e, arr_size, &arr[0], &num);
			end = clock();
			if (num == 0)
				cout << "无此元素" << endl;
			else
				cout << "该数所在位置为" << position << "   该数的数量为" << num << endl;
			start = end - start;
			cout << "使用顺序查找所花时间：" << start << endl;

			start = clock();
			position = DichotomiaSerach(e, arr_size, &arr[0], &num);
			end = clock();
			if (num == 0)
				cout << "无此元素" << endl;
			else
				cout << "该数所在位置为" << position << "   该数的数量为" << num << endl;
			start = end - start;
			cout << "使用二分查找所花时间：" << start << endl;

			start = clock();
			position = BlockSearch(e, arr_size, &arr[0], &num);
			end = clock();
			if (num == 0)
				cout << "无此元素" << endl;
			else
				cout << "该数所在位置为" << position << "   该数的数量为" << num << endl;
			start = end - start;
			cout << "使用分块查找所花时间：" << start << endl;
			
		}
	}


	delete[] arr;
}

void sort(int* num, int length)
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

void printList(int* arr, int arr_size)
{
	cout << "向量输出如下：" << endl;
	for (int i = 0; i < arr_size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int LinearSearch(int e, int arr_size, int* arr, int* num)
{
	int e_position = -1;
	*num = 0;
	for (int i = 0; i < arr_size; i++)
	{
		if (arr[i] < e)
		{
			e_position = i;
		}
		if (arr[i] == e)
		{
			*num = *num + 1;
			e_position = i;
		}
		if (arr[i] > e)
			break;
	}
	return e_position;
}

int DichotomiaSerach(int e, int arr_size, int* arr, int* num)
{
	int mid = 0, r = 0, l = arr_size;
	int e_position = -1;
	*num = 0;
	while (r <= l)
	{
		mid = (r + l) / 2;
		if (arr[mid] == e)
		{
			*num = *num + 1;
			e_position = mid;
			int search = mid - 1;
			while (arr[search] == e)
			{
				*num = *num + 1;
				search = search - 1;
			}
			search = mid + 1;
			while (arr[search] == e)
			{
				*num = *num + 1;
				search = search + 1;
			}
			return e_position;
		}
		else if (arr[mid] >= e)
			l = mid - 1;		
		else if (arr[mid] <= e)
			r = mid + 1;
	}
	return e_position;//如果没有找到返回-1
}

int BlockSearch(int e, int arr_size, int* arr, int* num)
{
	int e_position = -1, i = 0, mid = 0;
	*num = 0;
	while (i < arr_size)
	{
		if (arr[i] >= e)
		{
			mid = i - 100;
			break;
		}
		i = i + 100;
		if (i >= arr_size)
			i = arr_size - 1;
	}

	for (int j = mid; j <= (mid + 100); j++)
	{
		if (arr[j] == e)
		{
			e_position = j;
			*num = *num + 1;
			break;
		}
	}
	if (e_position != -1)
	{
		int search = e_position - 1;
		while (arr[search] == e)
		{
			*num = *num + 1;
			search = search - 1;
			if (search < 0)
				break;
		}
		search = e_position + 1;
		while (arr[search] == e)
		{
			*num = *num + 1;
			search = search + 1;
			if (search > arr_size)
				break;
		}		
	}
	
	return e_position;
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

void remove(int* arr, int* arr_new, int p, int n, int* arr_size)
{
	if (p < 0)
	{
		cout << "请注意输入的合法性问题" << endl;
		for (int i = 0; i < *arr_size; i++)
		{
			arr_new[i] = arr[i];
		}
		return;
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
		for (int i = p + n; i <= *arr_size; i++)
		{
			arr_new[i - n] = arr[i];
		}
		if ((p + n) > *arr_size)
			*arr_size = p;
		else
			*arr_size = *arr_size - n;
		cout << "向量删除成功" << endl;
	}
}