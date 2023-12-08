#include <iostream>
#include <cstring>
using namespace std;

int n2(int n)
{
	int num = 1;
	for (int i = 0; i < n; i++)
	{
		num = num * 2;
	}
	return num;
}

typedef struct LinkNode
{
	int m_data;//数据域
	struct LinkNode* next;//指针域
}list, * LinkStack;

/*初始化*/
void Init(LinkStack& top)
{
	top = NULL;//不需要头节点
}
/*入栈*/
void Input(LinkStack& top, int data)
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
void Output(LinkStack& top, int& data)
{
	list* p = new list;
	if (top == NULL)
	{
		//cout << "此时栈为空" << endl;
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
bool Empty(LinkStack& top)
{
	if (top == NULL)
		return true;
	else
		return false;
}

class binary_tree
{
public:
	int departure_time[31];//搜索二叉树
	int departure_rank[31];//起飞时间排序
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
	/*用于输出已经排序好的31个数*/
	void rank_cout(void)
	{
		cout << "随机生成的31个数为(已经排序)：" << endl;
		for (int i = 0; i < 31; i++)
		{
			cout << departure_rank[i] << " ";
		}
		cout << endl << "将其改为时间为：" << endl;
		for (int i = 0; i < 31; i++)
		{
			time_cout(departure_rank[i]);
			cout << " ";
		}
		cout << endl;
	}
	void tree_Init(void)
	{
		srand(time(NULL));
		for (int i = 0; i < 31; i++)
		{
			departure_rank[i] = rand() % 1441;
		}
		sort(departure_rank, 31);

		departure_time[0] = departure_rank[15];
		departure_time[1] = departure_rank[7];
		departure_time[2] = departure_rank[23];
		for (int i = 0; i <= 3; i++)
		{
			departure_time[3 + i] = departure_rank[3 + i * 8];
		}
		for (int i = 0; i <= 7; i++)
		{
			departure_time[7 + i] = departure_rank[1 + i * 4];
		}
		for (int i = 0; i <= 15; i++)
		{
			departure_time[15 + i] = departure_rank[0 + i * 2];
		}
	}
	/* 用于输出数据内容*/
	void time_cout(int num)
	{
		int hour = num / 60;
		int minite = num % 60;
		cout << hour << ":" << minite;
	}
	/*用于输出节点路径*/
	void path_cout(int rank ,int num)
	{
		int arr[4];
		int temp;
		int i = 0;
		do
		{
			temp = num % 2;
			num = num / 2;
			arr[i++] = temp;
		} while (num != 0);
		if (i < rank)
		{
			for (int j = 0; j < (rank - i); j++)
			{
				cout << "0";
			}
		}
		for (int j = i - 1; j >= 0; j--)
		{
			cout << arr[j];
		}
	}
	void tree_Show(void)
	{
		int pointer = 0; //用于指向目前输出的结点
		//输出根节点
		cout << "根节点： " ;
		time_cout(departure_time[pointer]);
		cout << endl;
		pointer++;
		//输出第一级
		cout << "第1级： ";
		for (int i = 0; i < 2; i++)
		{
			path_cout(1,i);
			cout << "-";
			time_cout(departure_time[pointer]);
			cout << "  ";
			pointer++;
		}
		cout << endl;
		//输出第二级
		cout << "第2级： ";
		for (int i = 0; i < 4; i++)
		{
			path_cout(2,i);
			cout << "-";
			time_cout(departure_time[pointer]);
			cout << "  ";
			pointer++;
		}
		cout << endl;
		//输出第三级
		cout << "第3级： ";
		for (int i = 0; i < 8; i++)
		{
			path_cout(3,i);
			cout << "-";
			time_cout(departure_time[pointer]);
			cout << "  ";
			pointer++;
		}
		cout << endl;
		//输出第四级
		cout << "第4级： ";
		for (int i = 0; i < 16; i++)
		{
			path_cout(4,i);
			cout << "-";
			time_cout(departure_time[pointer]);
			cout << "  ";
			pointer++;
		}
		cout << endl << endl;
	}
	int return_left(int num)
	{
		int temp = num * 2 + 1;
		return temp;
	}
	int return_right(int num)
	{
		int temp = num * 2 + 2;
		return temp;
	}
	int return_father(int num)
	{
		int temp = (num - 1) / 2;
		return temp;
	}
	void preorder_traversal(int num)
	{
		if (num > 30)
		{
			return;
		}
		time_cout(departure_time[num]);
		cout << " ";
		preorder_traversal(return_left(num));
		preorder_traversal(return_right(num));
	}
	void inorder_traversal(int num)
	{
		if (num > 30)
		{
			return;
		}		
		inorder_traversal(return_left(num));
		time_cout(departure_time[num]);
		cout << " ";
		inorder_traversal(return_right(num));
	}
	void postorder_traversal(int num)
	{
		if (num > 30)
		{
			return;
		}
		postorder_traversal(return_left(num));
		postorder_traversal(return_right(num));
		time_cout(departure_time[num]);
		cout << " ";		
	}
	void find(int hour, int minite)
	{
		int time = hour * 60 + minite;
		int pointer = 0;
		for (int i = 0; i < 31; i++)
		{
			if (departure_rank[i] >= time)
			{
				pointer = i;
				break;
			}
		}
		if (time == departure_rank[pointer])
		{
			cout << "等于查询时刻的节点：";
			for (int i = 0; i < 31; i++)
			{
				if (departure_rank[pointer] == departure_time[i])
				{
					pointer = i;
					break;
				}
			}
			if (pointer == 0)
				cout << "根节点" << endl;
			if (pointer == 1 || pointer == 2)
				path_cout(1, pointer - 1);
			if (pointer >= 3 && pointer <= 6)
				path_cout(2, pointer - 3);
			if (pointer >= 7 && pointer <= 14)
				path_cout(3, pointer - 7);
			if (pointer >= 15 && pointer <= 30)
				path_cout(4, pointer - 15);
			cout << endl;
		}
		else
		{
			int min = departure_rank[pointer] - time;
			if (time - departure_rank[pointer - 1] < min)
			{
				min = time - departure_rank[pointer - 1];
				pointer = pointer - 1;
			}
			for (int i = 0; i < 31; i++)
			{
				if (departure_rank[pointer] == departure_time[i])
				{
					pointer = i;
					break;
				}
			}
			cout << "离查询时刻最近的节点：";
			if (pointer == 0)
				cout << "根节点" << endl;
			if (pointer == 1 || pointer == 2)
				path_cout(1, pointer - 1);
			if (pointer >= 3 && pointer <= 6)
				path_cout(2, pointer - 3);
			if (pointer >= 7 && pointer <= 14)
				path_cout(3, pointer - 7);
			if (pointer >= 15 && pointer <= 30)
				path_cout(4, pointer - 15);
			cout << endl;
		}
		
			
	}
	void preorder_traversal(void)
	{
		cout << "使用迭代的前序：" << endl;
		LinkStack top;
		Init(top);
		int pointer = 0;
		Input(top, pointer);
		while (!Empty(top) || pointer == 0)
		{
			if (pointer < 15)
			{
				time_cout(departure_time[pointer]);
				cout << " ";
				Input(top, pointer);
				pointer = return_left(pointer);
			}
			else
			{
				time_cout(departure_time[pointer]);
				cout << " ";
				Output(top, pointer);
				pointer = return_right(pointer);
			}
		}
		cout << endl;
	}
	void inorder_traversal(void)
	{
		cout << "使用迭代的中序：" << endl;
		LinkStack top;
		Init(top);
		int pointer = 0;
		int num = 0;
		Input(top, pointer);
		while (num < 31)
		{
			if (pointer < 31)
			{	
				Input(top, pointer);
				pointer = return_left(pointer);									
			}
			else
			{			
				Output(top, pointer);
				time_cout(departure_time[pointer]);
				cout << " ";	
				num++;
				pointer = return_right(pointer);
			}
		}
		cout << endl;
	}
	void find_ancestor(int num1, int num2)
	{
		int num1_pointer = 0, num2_pointer = 0;
		int num1_rank = 0, num2_rank = 0;
		for (int i = 0; i < 31; i++)
		{
			if (num1 == departure_time[i])
			{
				num1_pointer = i;
				break;
			}
		}
		for (int i = 0; i < 31; i++)
		{
			if (num2 == departure_time[i])
			{
				num2_pointer = i;
				break;
			}
		}
		if (num1 == 0 || num2 == 0)
		{
			cout << "最近的共同祖宗是：根节点  ";
			time_cout(departure_time[0]);
			cout << endl;
		}
		else
		{
			if (num1_pointer > 0 && num1_pointer < 3)
				num1_rank = 1;
			else if (num1_pointer > 2 && num1_pointer < 7)
				num1_rank = 2;
			else if (num1_pointer > 6 && num1_pointer < 15)
				num1_rank = 3;
			else if (num1_pointer > 14 && num1_pointer < 31)
				num1_rank = 4;
			if (num2_pointer > 0 && num2_pointer < 3)
				num2_rank = 1;
			else if (num2_pointer > 2 && num2_pointer < 7)
				num2_rank = 2;
			else if (num2_pointer > 6 && num2_pointer < 15)
				num2_rank = 3;
			else if (num2_pointer > 14 && num2_pointer < 31)
				num2_rank = 4;
			int arr1[4], arr11[4],temp;
			int i = 0, m = 0;
			num1 = num1_pointer - n2(num1_rank) + 1;
			do
			{
				temp = num1 % 2;
				num1 = num1 / 2;
				arr1[i++] = temp;
			} while (num1 != 0);
			if (i < num1_rank)
			{
				for (int j = 0; j < (num1_rank - i); j++)
				{
					arr11[m] = 0;
					m++;
				}
			}
			for (int j = i - 1; j >= 0; j--)
			{
				arr11[m] = arr1[j];
				m++;
			}
			int arr2[4], arr22[4];
			i = 0, m = 0,temp = 0;
			num2 = num2_pointer - n2(num2_rank) + 1;
			do
			{
				temp = num2 % 2;
				num2 = num2 / 2;
				arr2[i++] = temp;
			} while (num2 != 0);
			if (i < num2_rank)
			{
				for (int j = 0; j < (num2_rank - i); j++)
				{
					arr22[m] = 0;
					m++;
				}
			}
			for (int j = i - 1; j >= 0; j--)
			{
				arr22[m] = arr2[j];
				m++;
			}
			int min = num1_rank;
			if (min > num2_rank)
				min = num2_rank;
			int ancesor[4];
			int ancesor_num = 0;
			for (int n = 0; n < min; n++)
			{
				if (arr11[n] == arr22[n])
				{
					ancesor[ancesor_num] = arr11[n];
					ancesor_num++;
				}
				else
					break;
			}
			if (ancesor_num == 0)
			{
				cout << "最近的共同祖宗是：根节点  ";
				time_cout(departure_time[0]);
				cout << endl;
			}
			else
			{
				cout << "最近的共同祖宗是：  ";
				for (int i = 0; i < ancesor_num; i++)
				{
					cout << ancesor[i];
				}
				int num = 0;
				for (int i = ancesor_num; i > 0; i++)
				{
					num = num + ancesor[ancesor_num] * n2(ancesor_num - i);
				}
				num = n2(ancesor_num) + num - 1;
				time_cout(departure_time[num]);
				cout << endl;
			}
		}
	}
};

int main()
{
	binary_tree tree1;
	string judge = "1";
	cout << "逐层输出二叉树结果如下:" << endl;
	while (judge == "1")
	{		
		tree1.tree_Init();
		tree1.rank_cout();
		tree1.tree_Show();
		cout << "如果要重复，请输入1，否则随意输入" << endl;
		cin >> judge;
	}
	cout << "先序，递归：" << endl;
	tree1.preorder_traversal(0);
	cout << endl;
	cout << "中序，递归：" << endl;
	tree1.inorder_traversal(0);
	cout << endl;
	cout << "后序，递归：" << endl;
	tree1.postorder_traversal(0);
	cout << endl;
	tree1.preorder_traversal();
	tree1.inorder_traversal();
	judge = "1";
	while (judge == "1")
	{
		cout << "请输入小时与时间" << endl;
		int hour, minite;
		cin >> hour;
		cin >> minite;
		tree1.find(hour, minite);
		cout << "如果要重复，请输入1，否则随意输入" << endl;
		cin >> judge;
	}
	cout << "请输入两个节点" << endl;
	int num1, num2;
	cin >> num1;
	cin >> num2;
	tree1.find_ancestor(num1, num2);
	return 0;
}