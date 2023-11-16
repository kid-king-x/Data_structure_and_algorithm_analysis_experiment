#include <iostream>
#include <cstring>
using namespace std;
typedef struct LinkNode
{
	char m_data;//������
	struct LinkNode* next;//ָ����
}list, * LinkStack;

class Stack
{
public:
	LinkStack top;
	void Init(void)
	{
		top = NULL;//����Ҫͷ�ڵ�
	}
	/*��ջ*/
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

	/*��ջ*/
	void Output(char& data)
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
			//cout << "��ʱ��ջ��ֵΪ" << data << endl;
			top = top->next;
			delete p;
		}
	}
	/*���ջ�Ƿ�Ϊ��*/
	bool Empty(void)
	{
		if (top == NULL)
			return true;
		else
			return false;
	}
	/*���ջ�����*/
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
	/*����ջ��*/
	void GetTop(char data)
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
};
/*��ʼ��*/


int main()
{
	Stack stack;
	for (int i = 0; i < 10; i++)
	{
		cout << "��������ʽ" << endl;
		string express;
		stack.Init();
		cin >> express;
		int small_num = 0;//С���ŵ�����
		int middle_num = 0;//�����ŵ�����
		int big_num = 0;//�����ŵ�����
		int shunxu_last = 0;//0��ʾ�����ţ�1��ʾ�����ţ�2��ʾ������
		int shunxu = 0;
		int flag = 0;//0��ʾδ����ǰ������ţ�1��ʾ����ǰ�������
		int judge = 1;//1��ʾ���ʽ��ȷ��2��ʾ���ʽ����
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
			cout << "���ʽ����" << endl;
		else
			cout << "���ʽ��ȷ" << endl;
	}

}