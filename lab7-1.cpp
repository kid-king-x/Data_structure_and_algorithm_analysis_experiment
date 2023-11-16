#include <iostream>
#include <cstring>
using namespace std;

typedef struct LinkNode
{
	string m_data;//������
	struct LinkNode* next;//ָ����
}list,*LinkStack;

/*��ʼ��*/
void Init(LinkStack &top)
{
	top = NULL;//����Ҫͷ�ڵ�
}
/*��ջ*/
void Input(LinkStack &top, string data)
{
	list* p = new list;
	p->m_data = data;
	p->next = NULL;
	if (top == NULL)
	{
		top = p;
	}
	else
	{
		p->next = top;
		top = p;
	}
}

/*��ջ*/
void Output(LinkStack &top, string &data)
{
	list* p = new list;
	if (top == NULL)
	{
		cout << "��ʱջΪ��" << endl;
	}
	else
	{
		p = top;
		data = p->m_data;
		cout << "��ʱ��ջ��ֵΪ" << data << endl;
		top = top->next;
		delete p;
	}
}
/*���ջ�Ƿ�Ϊ��*/
bool Empty(LinkStack& top)
{
	if (top == NULL)
		return true;
	else
		return false;
}
/*���ջ�����*/
int GetLength(LinkStack& top)
{
	int sum = 0;
	list* temp = top;
	while (temp != NULL)
	{
		sum++;
		temp = temp->next;
	}
	return sum;
}
/*����ջ��*/
void GetTop(LinkStack top,string data)
{
	if (top == NULL)
	{
		cout << "ջΪ��" << endl;
	}
	else
	{
		data = top->m_data;
		cout << "ջ������Ϊ:" << data << endl;
	}
}

void menu()
{
	cout << "-----------------------------------------------------" << endl;
	cout << "����1�����ջ�Ƿ�Ϊ��" << endl;
	cout << "����2������ջ������" << endl;
	cout << "����3������ջ���" << endl;
	cout << "����4��ѹջ" << endl;
	cout << "����5����ջ" << endl;
}
int main()
{
	LinkStack top;
	Init(top);
	string judge = "1";
	while (judge == "1" || judge == "2" || judge == "3" || judge == "4" || judge == "5")
	{
		menu();
		cin >> judge;
		if (judge == "1")
		{
			if (Empty(top) == true)
				cout << "ջΪ��" << endl;
			else
				cout << "ջ��Ϊ��" << endl;
		}
		if (judge == "2")
		{
			string data;
			GetTop(top, data);
		}
		if (judge == "3")
		{
			cout << "ջ���Ϊ" << GetLength(top) << endl;
		}
		if (judge == "4")
		{
			cout << "��������Ҫѹ�������" << endl;
			string data;
			cin >> data;
			Input(top, data);
		}
		if (judge == "5")
		{
			string data;
			Output(top, data);
		}
	}
}