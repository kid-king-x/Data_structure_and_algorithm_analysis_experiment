#include <iostream>
using namespace std;

/*
* �������ã���ӡ�����е�����
* ����ֵ����
* ����������arrΪ��Ҫ��������飬
		   arr_sizeΪ����ĳ���
*/
void printList(int* arr, int arr_size);

/*
* �������ã������������е�λ��p������Ӧ�кϷ��жϣ�����Ԫ�� e������1����p��ʾ������λ�õ��ȣ���2����e��ʾ�����������Ԫ�ء�
* ����ֵ����
* ����������arrΪ��Ҫ��������飬
*		   arr_newΪ���ڹ��ɵ�����
*		   p��ʾ������λ�õ���
*		   e��ʾ�����������Ԫ��
*		   arr_sizeΪarr����ĳ���
*/
void insert(int* arr, int* arr_new, int p, int e, int* arr_size);

/*
* �������ã�ɾ������������λ��p������Ӧ�кϷ��жϣ����n������Ԫ�أ������ر�ɾ���ĵ�һ������Ԫ�ص�ֵ
* ����ֵ����
* ����������arrΪ��Ҫɾ�������飬
*		   arr_newΪ���ڹ��ɵ�����
*		   pΪҪɾ������ʼλ�õ���
*		   nΪҪɾ����Ԫ�ظ���
*		   arr_sizeΪarr����ĳ���
*/
int remove(int* arr, int* arr_new, int p, int n, int* arr_size);

/*
* �������ã��Ӽ�������1������e���������������в��Ҹ�����λ�á�
* ����ֵ��int ����ý�����
* ����������arrΪ��Ҫɾ�������飬
*		   eΪ��Ҫ���ҵ�ֵ
*		   arr_sizeΪarr����ĳ���
*/
int find(int* arr, int e, int* arr_size);
int main()
{
	int* arr = new int[10];
	int arr_size = 10;//���������ռ��е�Ԫ������
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand();
	}
	printList(&arr[0], arr_size);

	string judge = "1";
	while (judge == "1" || judge == "2" || judge == "3")
	{
		cout << endl << "�����������������1��ɾ����������������2�����Ҳ���������3�������˳���������������" << endl;
		cin >> judge;
		if (judge == "1")
		{
			cout << "�Ӽ�������2������p��e������1����p��ʾ������λ�õ��ȣ���2����e��ʾ�����������Ԫ��" << endl;
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
			cout << "�Ӽ�������2������p��n������1����pΪҪɾ������ʼλ�õ��ȣ���2����nΪҪɾ����Ԫ�ظ���" << endl;
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
			cout << "�Ӽ�������1������e���������������в��Ҹ�����λ��" << endl;
			int e = 0;
			cin >> e;
			int position = find(&arr[0], e, &arr_size);
			if (position == -1)
				cout << "�޴�Ԫ��" << endl;
			else
				cout << "�ý�����Ϊ��" << position << endl;
		}
	}
	
	
	delete[] arr;
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

int remove(int* arr, int* arr_new, int p, int n, int* arr_size)
{
	int num;//����ɾ���ĵ�һ������Ԫ�ص�ֵ
	if (p < 0)
	{
		cout << "��ע������ĺϷ�������" << endl;
		for (int i = 0; i < *arr_size; i++)
		{
			arr_new[i] = arr[i];
		}
		return -1;
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
		num = arr[p];
		for (int i = p + n; i <= *arr_size; i++)
		{
			arr_new[i - n] = arr[i];
		}
		if ((p + n) > *arr_size)
			*arr_size = p;
		else
			*arr_size = *arr_size - n;
		cout << "����ɾ���ɹ�" << endl;
		cout << "��ɾ���ĵ�һ������Ԫ�ص�ֵΪ" << num << endl;
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
