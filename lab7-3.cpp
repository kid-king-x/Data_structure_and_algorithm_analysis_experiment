#include <iostream>
#include <cstring>
using namespace std;
typedef struct LinkNode
{
	char m_data;//数据域
	struct LinkNode* next;//指针域
}list, * LinkStack;

class Stack
{
public:
	LinkStack top;
	void Init(void)
	{
		top = NULL;//不需要头节点
	}
	/*入栈*/
	void Input(char data)
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
	void Output(char& data)
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
			//cout << "此时出栈的值为" << data << endl;
			top = top->next;
			delete p;
		}
	}
	/*检查栈是否为空*/
	bool Empty(void)
	{
		if (top == NULL)
			return true;
		else
			return false;
	}
	/*检查栈的深度*/
	int GetLength(void)
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
	void GetTop(char data)
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
};
/*初始化*/


int main()
{
	Stack stack;
	for (int i = 0; i < 10; i++)
	{
		cout << "请输入表达式" << endl;
		string express;
		stack.Init();
		cin >> express;
		int small_num = 0;//小括号的数量
		int middle_num = 0;//中括号的数量
		int big_num = 0;//大括号的数量
		int shunxu_last = 0;//0表示大括号，1表示中括号，2表示中括号
		int shunxu = 0;
		int flag = 0;//0表示未出现前半边括号，1表示出现前半边括号
		int judge = 1;//1表示表达式正确，2表示表达式错误
		for (int i = 0; i < express.length(); i++)
		{
			stack.Input(express[i]);
		}
		for (int i = 0; i < express.length(); i++)
		{
			char data;
			stack.Output(data);
			if (flag == 0)
			{
				if (data == '}')
				{
					shunxu = 0;
					big_num++;
					if (shunxu < shunxu_last)
					{
						judge = 0;
						break;
					}
					shunxu_last = shunxu;
				}
				if (data == ']')
				{
					shunxu = 1;
					middle_num++;
					if (shunxu < shunxu_last)
					{
						judge = 0;
						break;
					}
					shunxu_last = shunxu;
				}
				if (data == ')')
				{
					shunxu = 2;
					small_num++;
					if (shunxu < shunxu_last)
					{
						judge = 0;
						break;
					}
					shunxu_last = shunxu;
				}
				if (data == '{')
				{
					judge = 0;
					break;
				}
				if (data == '[')
				{
					judge = 0;
					break;
				}
				if (data == '(')
				{
					flag = 1;
				}
			}
			if (flag == 1)
			{
				if (data == '{')
				{
					shunxu = 0;
					big_num--;
					if (shunxu > shunxu_last)
					{
						judge = 0;
						break;
					}
					shunxu_last = shunxu;
				}
				if (data == '[')
				{
					shunxu = 1;
					middle_num--;
					if (shunxu > shunxu_last)
					{
						judge = 0;
						break;
					}
					shunxu_last = shunxu;
				}
				if (data == '(')
				{
					shunxu = 2;
					small_num--;
					if (shunxu > shunxu_last)
					{
						judge = 0;
						break;
					}
					shunxu_last = shunxu;
				}
				if (data == '}')
				{
					shunxu = 0;
					big_num++;
					flag = 0;
				}
				if (data == ']')
				{
					shunxu = 0;
					middle_num++;
					flag = 0;
				}
				if (data == ')')
				{
					shunxu = 0;
					small_num++;
					flag = 0;
				}
			}
		}
		if (small_num != 0 || middle_num != 0 || big_num != 0 || judge == 0)
			cout << "表达式有误" << endl;
		else
			cout << "表达式正确" << endl;
	}

}