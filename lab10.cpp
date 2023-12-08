#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Queue
{
public:
	int data[5];
	int front, rear;
	/*队列的初始化*/
	void Init()
	{
		front = 0;
		rear = 0;
	}
	/*入队*/
	void Input(int m_data)
	{
		data[rear] = m_data;
		rear++;
	}
	/*出队*/
	int Output(void)
	{
		int temp = data[front];
		front++;
		return temp;
	}
};


class Graph
{
public:
	string name[10];//节点名
	int serial[10];//节点序号
	int num = 0;
	int bian[10][10];//边
	Graph()
	{
		for (int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				bian[i][j] = 0;
			}
		}
	}
	void Delete(int number)
	{
		int temp;
		for (int i = 0; i < num; i++)
		{
			if (number == serial[i])
			{
				temp = i;
				break;
			}
		}
		for (int i = temp; i < num - 1; i++)
		{
			serial[i] = serial[i + 1];
			name[i] = name[i + 1];
		}
		for (int i = 0; i < num; i++)
		{
			bian[temp][i] = bian[temp + 1][i];
			bian[i][temp] = bian[i][temp + 1];
		}
		num--;
	}
};
class graph
{
public:
	Graph g;
	void Add_num(void)
	{
		cout << "请输入节点序号" << endl;
		cin >> g.serial[g.num];
		cout << "请输入节点名称" << endl;
		cin >> g.name[g.num];
		g.num++;
	}
	void Add_bian(void)
	{
		int temp1;
		cout << "请输入边的起始节点序号" << endl;
		cin >> temp1;
		for (int i = 0; i < g.num; i++)
		{
			if (temp1 == g.serial[i])
			{
				temp1 = i;
				break;
			}
		}
		int temp2;
		cout << "请输入边的到达节点序号" << endl;
		cin >> temp2;
		for (int i = 0; i < g.num; i++)
		{
			if (temp2 == g.serial[i])
			{
				temp2 = i;
				break;
			}
		}
		if (temp1 == temp2)
		{
			cout << "请不要输入自环" << endl;
			return;
		}
		cout << "请输入边的权重" << endl;
		cin >> g.bian[temp1][temp2];
	}
	void Delete_nod(void)
	{
		cout << "请输入要删除节点的序号" << endl;		
		int temp;
		cin >> temp;
		g.Delete(temp);
	}
	void Delete_bian(void)
	{
		int temp1;
		cout << "请输入边的起始节点序号" << endl;
		cin >> temp1;
		for (int i = 0; i < g.num; i++)
		{
			if (temp1 == g.serial[i])
			{
				temp1 = i;
				break;
			}
		}
		int temp2;
		cout << "请输入边的到达节点序号" << endl;
		cin >> temp2;
		for (int i = 0; i < g.num; i++)
		{
			if (temp2 == g.serial[i])
			{
				temp2 = i;
				break;
			}
		}
		g.bian[temp1][temp2] = 0;
	}
	void show(void)
	{
		cout << "      ";
		for (int i = 0; i < g.num; i++)
		{
			cout << setw(3) << g.serial[i] << setw(3) << g.name[i];
		}
		cout << endl;
		for (int i = 0; i < g.num; i++)
		{
			cout << setw(3) << g.serial[i] << setw(3) << g.name[i];
			for (int j = 0; j < g.num; j++)
			{
				if (g.bian[i][j] == 0)
					cout << "   -  ";
				else
					cout << setw(6) << g.bian[i][j];
			}
			cout << endl;
		}
	}
	void search(void)
	{
		Queue q;
		q.Init();
		int temp;
		int* init = new int[g.num];
		int init_num = 0;
		for (int i = 0; i < g.num; i++)
		{
			init[i] = 0;
		}
		cout << "请输入你想开始的节点序号" << endl;
		cin >> temp;
		for(int i = 0; i < g.num; i++)
		{
			if (temp == g.serial[i])
			{
				temp = i; 
				break;
			}
		}
		cout << "广度优先遍历序列为：";
		init[temp] = 1;
		init_num++;
		q.Input(temp);
		cout << g.name[temp] << " ";
		while (init_num < g.num)
		{
			int temp_num = q.Output();
			for (int i = 0; i < g.num; i++)
			{
				if ((g.bian[temp_num][i] != 0 || g.bian[i][temp_num] != 0) && init[i] == 0)
				{
					init[i] = 1;
					init_num++;
					q.Input(i);
					cout << g.name[i] << " ";
				}
			}
		}
		cout << endl;

	}
};
int main()
{
	graph g;
	string judge = "1";	
	while (judge == "1" || judge == "2" || judge == "3" || judge == "4" || judge == "5" || judge == "6")
	{
		cout << "------------------------菜单栏--------------" << endl;
		cout << "------1.加入节点--------------" << endl;
		cout << "------2.加入边--------------" << endl;
		cout << "------3.删除节点--------------" << endl;
		cout << "------4.删除边--------------" << endl;
		cout << "------5.展示数据--------------" << endl;
		cout << "------6.广度优先遍历--------------" << endl;
		cin >> judge;
		if (judge == "1")
		{
			g.Add_num();
		}
		if (judge == "2")
		{
			g.Add_bian();
		}
		if (judge == "3")
		{
			g.Delete_nod();
		}
		if (judge == "4")
		{
			g.Delete_bian();
		}
		if (judge == "5")
		{
			g.show();
		}
		if (judge == "6")
		{
			g.search();
		}
	}

}