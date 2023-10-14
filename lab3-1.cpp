#include <iostream>
#include <ctime>
using namespace std;

/*
* ��������������
*/
void sort(int* num, int length);

/*
* �������
*/
void printList(int* arr, int arr_size);

/*
* ����������һ����
* ������pΪ��Ҫ������ȣ�eΪ�������
*/
void insert(int* arr, int* arr_new, int p, int e, int* arr_size);

/*
* ������ɾ��n����
* ������pΪ��Ҫɾ�����ȣ�nΪ�ܹ���Ҫɾ������������p��ʼ��n����
*/
void remove(int* arr, int* arr_new, int p, int n, int* arr_size);

/*
* ˳��������������е���e������Ԫ��
* ������num�������������е���e������Ԫ�ص�����
* ����ֵ���������ȣ������Ҳ���eʱ����ٽ�e��ǰһ��������
*/
int LinearSearch(int e, int arr_size, int* arr, int* num);

/*
* ���ֲ������������е���e������Ԫ��
* ������num�������������е���e������Ԫ�ص�����
* ����ֵ���������ȣ����û���ҵ�����-1
*/
int DichotomiaSerach(int e, int arr_size, int* arr, int* num);

/*
* �ֿ�������������е���e������Ԫ��
* ������num�������������е���e������Ԫ�ص�����
* ����ֵ���������ȣ����û���ҵ�����-1
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
		cout << endl << "�����������������1��ɾ����������������2�����Ҳ���������3�������˳���������������" << endl;
		cin >> judge;
		if (judge == "1")
		{
			cout << "�Ӽ�������1�������ҽ��������뵽�����������ʵ�λ�ã��Ա�������������������" << endl;
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
			cout << "�Ӽ�������1�������ҽ�ɾ���������������е��ڸ���������Ԫ�ء����Ҳ�����Ԫ�أ������ʾ���޴�Ԫ�ء�" << endl;
			int e = 0, num = 0, p = 0;
			cin >> e;
			p = LinearSearch(e, arr_size, &arr[0], &num) - num + 1;
			if (num == 0)
				cout << "�޴�Ԫ��" << endl;
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
			cout << "�Ӽ�������1�������ҵ����������е��ڸ���������Ԫ�أ���ͳ�����������Ҳ�����Ԫ�أ�����ʾ���޴�Ԫ�ء�" << endl;
			int e = 0, num = 0;
			cin >> e;

			clock_t start, end;
			start = clock();
			int position = LinearSearch(e, arr_size, &arr[0], &num);
			end = clock();
			if (num == 0)
				cout << "�޴�Ԫ��" << endl;
			else
				cout << "��������λ��Ϊ" << position << "   ����������Ϊ" << num << endl;
			start = end - start;
			cout << "ʹ��˳���������ʱ�䣺" << start << endl;

			start = clock();
			position = DichotomiaSerach(e, arr_size, &arr[0], &num);
			end = clock();
			if (num == 0)
				cout << "�޴�Ԫ��" << endl;
			else
				cout << "��������λ��Ϊ" << position << "   ����������Ϊ" << num << endl;
			start = end - start;
			cout << "ʹ�ö��ֲ�������ʱ�䣺" << start << endl;

			start = clock();
			position = BlockSearch(e, arr_size, &arr[0], &num);
			end = clock();
			if (num == 0)
				cout << "�޴�Ԫ��" << endl;
			else
				cout << "��������λ��Ϊ" << position << "   ����������Ϊ" << num << endl;
			start = end - start;
			cout << "ʹ�÷ֿ��������ʱ�䣺" << start << endl;
			
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
	cout << "����������£�" << endl;
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
	return e_position;//���û���ҵ�����-1
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
		cout << "��ע������ĺϷ�������" << endl;
		for (int i = 0; i < *arr_size; i++)
		{
			arr_new[i] = arr[i];
		}
	}

	else if (p > *arr_size)
	{
		cout << "����������ȳ��������ռ��������ĸ��������԰�����뵽���" << endl;
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
		cout << "��������ɹ�" << endl;
	}
}

void remove(int* arr, int* arr_new, int p, int n, int* arr_size)
{
	if (p < 0)
	{
		cout << "��ע������ĺϷ�������" << endl;
		for (int i = 0; i < *arr_size; i++)
		{
			arr_new[i] = arr[i];
		}
		return;
	}
	else if (p > *arr_size)
	{
		cout << "����������ȳ��������ռ��������ĸ��������Ա��ֲ���" << endl;
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
		cout << "����ɾ���ɹ�" << endl;
	}
}