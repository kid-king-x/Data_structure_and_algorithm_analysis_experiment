#include <iostream>
#include <cstring>
using namespace std;

typedef struct LinkNode
{
	string m_data;//数据域
	struct LinkNode* next;//指针域
}list,*LinkStack;

/*初始化*/
void Init(LinkStack &top)
{
	top = NULL;//不需要头节点
}
/*入栈*/
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

/*出栈*/
void Output(LinkStack &top, string &data)
{
	list* p = new list;
	if (top == NULL)
	{
		cout << "此时栈为空" << endl;
	}
	else
	{
		p = top;
		data = p->m_data;
		cout << "此时出栈的值为" << data << endl;
		top = top->next;
		delete p;
	}
}
/*检查栈是否为空*/
bool Empty(LinkStack& top)
{
	if (top == NULL)
		return true;
	else
		return false;
}
/*检查栈的深度*/
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
/*查找栈顶*/
void GetTop(LinkStack top,string data)
{
	if (top == NULL)
	{
		cout << "栈为空" << endl;
	}
	else
	{
		data = top->m_data;
		cout << "栈顶数据为:" << data << endl;
	}
}

void menu()
{
	cout << "-----------------------------------------------------" << endl;
	cout << "输入1，检查栈是否为空" << endl;
	cout << "输入2，返回栈顶数据" << endl;
	cout << "输入3，返回栈深度" << endl;
	cout << "输入4，压栈" << endl;
	cout << "输入5，出栈" << endl;
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
				cout << "栈为空" << endl;
			else
				cout << "栈不为空" << endl;
		}
		if (judge == "2")
		{
			string data;
			GetTop(top, data);
		}
		if (judge == "3")
		{
			cout << "栈深度为" << GetLength(top) << endl;
		}
		if (judge == "4")
		{
			cout << "请输入需要压入的数据" << endl;
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