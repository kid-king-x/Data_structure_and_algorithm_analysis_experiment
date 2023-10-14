#include <iostream>
#include <ctime>
using namespace std;

void recursion(int* arr, int length);

void process(int* arr, int l, int r);
void MergeSort(int* arr, int l, int mid, int r);

void process(int* arr, int l, int r)
{
	if (l == r)
		return;
	int mid = l + (r - l) / 2;
	process(arr, l, mid);
	process(arr, mid + 1, r);
	MergeSort(arr, l, mid, r);
}
void MergeSort(int* arr, int l, int mid, int r)
{
	int* arr_new = new int[r - l + 1];
	int i = l;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= r)
	{
		if (arr[i] < arr[j])
		{
			arr_new[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			arr_new[k] = arr[j];
			j++;
			k++;
		}
	}
	while (i <= mid)
	{
		arr_new[k] = arr[i];
		k++;
		i++;
	}
	while (j <= r)
	{
		arr_new[k] = arr[j];
		k++;
		j++;
	}

	for (k = l; k <= r; k++) {
		arr[k] = arr_new[k - l];
	}
}


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

int main()
{
	int length = 100000;
	int* arr = new int[length];
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand();
	}
	clock_t start, end;
	start = clock();
	sort(arr, length);
	end = clock();
	start = end - start;
	cout << "使用冒泡排序处理无序向量所需时间" << start << "毫秒" << endl;

	for (int i = 0; i < length; i++)
	{
		arr[i] = rand();
	}
	start = clock();
	process(arr, 0, length - 1);
	end = clock();
	start = end - start;
	cout << "使用归并排序处理无序向量所需时间" << start << "毫秒" << endl;


	for (int i = 0; i < length; i++)
	{
		arr[i] = length - i + 10;
	}
	start = clock();
	sort(arr, length);
	end = clock();
	start = end - start;
	cout << "使用冒泡排序处理逆序向量所需时间" << start << "毫秒" << endl;

	for (int i = 0; i < length; i++)
	{
		arr[i] = length - i + 10;
	}
	start = clock();
	process(arr, 0, length - 1);
	end = clock();
	start = end - start;
	cout << "使用归并排序处理逆序向量所需时间" << start << "毫秒" << endl;

}