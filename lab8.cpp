#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct {
	int data[5];
	int front, rear;
}SqQueue;


class Queue
{
public:
	SqQueue Q;
	/*队列的初始化*/
	void Init()
	{
		Q.front = 0;
		Q.rear = 0;
	}
	/*入队*/
	void Input(int m_data)
	{
		Q.data[Q.rear] = m_data;
		Q.rear++;
	}
	/*出队*/
	int Output(void)
	{
		int temp = Q.data[Q.front];
		Q.front++;
		return temp;
	}
};

typedef struct Node
{
	int data;
	struct Node* next;
}QueueNode;

typedef struct
{
	QueueNode* front, * rear;
}LinkQueue;


void Init(LinkQueue* s)
{
	QueueNode* p;
	p = (QueueNode*)malloc(sizeof(QueueNode));//为指向节点的指针分配空间
	p->next = NULL;
	s->front = s->rear = p;
}
//判断队列是否为空,为空返回真1，不为空返回假0
int Empty(LinkQueue s)
{
	//队空的条件是头指针和尾指针指向相同的地方
	if (s.front == s.rear)
	{
		return 1;
	}
	return 0;
}
//入队操作
void Add(LinkQueue* s, int x)
{
	//声明一个节点类型的指针变量用来存储要入队的元素
	QueueNode* p;
	p = (QueueNode*)malloc(sizeof(QueueNode));
	if (!p) {
		printf("内存分配失败\n\n");
		return;
	}
	p->data = x;        //指针指向的节点的数据域存放x
	p->next = NULL;     //指针指向的节点的指针域置为空
	s->rear->next = p;   //将队列的尾指针的指针域next指向指针p所指的节点
	s->rear = p;         //将队列的尾指针向后移一位，指向刚入队的节点的位置
}
//获取队首元素
int GetTop(LinkQueue s)
{
	//首先判断队列是否为空
	if (Empty(s))
	{
		printf("队列为空，无法获取队首元素\n\n");
		return 0;
	}
	return s.front->next->data;//不为空的话就返回队首指针指向的第一个元素的数据域
}
//出队操作
void Del(LinkQueue* s, int* e)
{
	//用临时变量保存出队的元素
	QueueNode* p;
	p = s->front->next;
	if (p == s->rear)    //如果p指向了队尾节点
	{
		s->front = s->rear;  //那么删除之后队首指针和尾指针指向同一个位置
	}
	*e = p->data;
	s->front->next = p->next;//将队首指针指向第一个节点的下一个节点。
	free(p);

}
int main()
{
	
	string m_judge = "0";//用于判断是否要再进行编组

	while (m_judge == "0")
	{
		Queue Q1, Q2;//到达轨的火车
		Q1.Init();
		Q2.Init();

		int depart[11] = {};//出发区的火车
		depart[0] = 0;//depart[0]的数据表明此时出发区的火车数量
		int data[10] = { 1,2,3,4,5,6,7,8,9,10 };

		LinkQueue S1, S2, S3, S4;
		Init(&S1);
		Init(&S2);
		Init(&S3);
		Init(&S4);
		int S1_last = 0;//用于记录缓冲轨道1的最后入轨的数，如果为0，则说明没有入轨道
		int S2_last = 0;//用于记录缓冲轨道2的最后入轨的数，如果为0，则说明没有入轨道
		int S3_last = 0;//用于记录缓冲轨道3的最后入轨的数，如果为0，则说明没有入轨道
		int S4_last = 0;//用于记录缓冲轨道4的最后入轨的数，如果为0，则说明没有入轨道

		/*打乱顺序*/
		srand(time(NULL));
		for (int i = 0; i < 10; i++)
		{
			int temp = rand() % (10 - i) + i;
			if (i != temp)
			{
				int temp_num = data[i];
				data[i] = data[temp];
				data[temp] = temp_num;
			}
		}

		for (int i = 0; i < 5; i++)
		{
			Q1.Input(data[i]);
		}
		cout << "第一条列车的车厢号为：";
		for (int i = 4; i >= 0; i--)
			cout << data[i] << " ";

		for (int i = 5; i < 10; i++)
		{
			Q2.Input(data[i]);
		}
		cout << endl << "第二条列车的车厢号为：";
		for (int i = 9; i >= 5; i--)
			cout << data[i] << " ";
		cout << endl;
		int Q1_out = 0, Q2_out = 0;//代表列车最前面的那个车厢
		Q1_out = Q1.Output();
		Q2_out = Q2.Output();
		while (1)
		{
			if (depart[0] == 10)
			{
				cout << "完成排序编组" << endl;
				break;
			}

			int judge = 0; //用于判断缓冲区是否有可以推入出发区的
			int car_num = 0;//用于记录可以推入出发区的车厢号
			int buffer_num = 0;//用于记录缓冲轨的号码
			int temp1;
			if(Empty(S1) == 0)
			{
				temp1 = GetTop(S1);
				if (temp1 == (depart[0] + 1))
				{
					judge = 1;
					Del(&S1, &car_num);
					buffer_num = 1;
					depart[0]++;
					depart[depart[0]] = car_num;
				}
			}
			if (Empty(S2) == 0)
			{
				temp1 = GetTop(S2);
				if (temp1 == (depart[0] + 1))
				{
					judge = 1;
					Del(&S2, &car_num);
					buffer_num = 2;
					depart[0]++;
					depart[depart[0]] = car_num;
				}
			}
			if (Empty(S3) == 0)
			{
				temp1 = GetTop(S3);
				if (temp1 == (depart[0] + 1))
				{
					judge = 1;
					Del(&S3, &car_num);
					buffer_num = 3;
					depart[0]++;
					depart[depart[0]] = car_num;
				}
			}
			if (Empty(S4) == 0)
			{
				temp1 = GetTop(S4);
				if (temp1 == (depart[0] + 1))
				{
					judge = 1;
					Del(&S4, &car_num);
					buffer_num = 4;
					depart[0]++;
					depart[depart[0]] = car_num;
				}
			}

			if (judge == 1)//缓冲区有可以推入出发区的情况
			{
				cout << car_num << "号车厢从" << buffer_num << "#缓冲轨推入出发区，出发队列为";
				for (int i = depart[0]; i > 1; i--)
				{
					cout << depart[i] << ",";
				}
				cout << depart[1] << endl;
			}
			else//如果没有可以推入出发区的情况
			{
				int num = 0;
				if (Empty(S1) == 1)//为空返回1
				{
					num++;
				}
				if (Empty(S2) == 1)
				{
					num++;
				}
				if (Empty(S3) == 1)
				{
					num++;
				}
				if (Empty(S4) == 1)
				{
					num++;
				}
				if (num == 0 && depart[0] != 10)
				{
					cout << "无法完成编组，重新分配列车序列" << endl;
					break;
				}
				else
				{
					int temp = Q1_out;

					if (temp > Q2_out)
					{
						temp = Q2_out;
						if (Q2.Q.front == 5)
							Q2_out = 11;
						else
							Q2_out = Q2.Output();
					}
					else
					{
						if (Q1.Q.front == 5)
							Q1_out = 11;
						else
							Q1_out = Q1.Output();
					}
					if (temp == (depart[0] + 1))
					{
						car_num = temp;
						if (Empty(S4) == 1)
							buffer_num = 4;
						if (Empty(S3) == 1)
							buffer_num = 3;
						if (Empty(S2) == 1)
							buffer_num = 2;
						if (Empty(S1) == 1)
							buffer_num = 1;
						depart[0]++;
						depart[depart[0]] = car_num;
						cout << car_num << "号车厢经" << buffer_num << "#缓冲轨推入出发区，出发队列为";
						for (int i = depart[0]; i > 1; i--)
						{
							cout << depart[i] << ",";
						}
						cout << depart[1] << endl;
					}
					else
					{
						int min1 = 0, min2 = 0, min3 = 0, min4 = 0, min = 100;
						if (temp > S1_last)
							min1 = temp - S1_last;
						if (temp > S2_last)
							min2 = temp - S2_last;
						if (temp > S3_last)
							min3 = temp - S3_last;
						if (temp > S4_last)
							min4 = temp - S4_last;

						if (min1 != 0 && min > min1)
							min = min1;
						if (min2 != 0 && min > min2)
							min = min2;
						if (min3 != 0 && min > min3)
							min = min3;
						if (min4 != 0 && min > min4)
							min = min4;

						if (min == min1)
						{
							Add(&S1, temp);
							cout << temp << "号车厢推入" << 1 << "#缓冲轨" << endl;
							S1_last = temp;
						}
						else if (min == min2)
						{
							Add(&S2, temp);
							cout << temp << "号车厢推入" << 2 << "#缓冲轨" << endl;
							S2_last = temp;
						}
						else if (min == min3)
						{
							Add(&S3, temp);
							cout << temp << "号车厢推入" << 3 << "#缓冲轨" << endl;
							S3_last = temp;
						}
						else if (min == min4)
						{
							Add(&S4, temp);
							cout << temp << "号车厢推入" << 4 << "#缓冲轨" << endl;
							S4_last = temp;
						}
					}
				}
				
			}
		}
		cout << "是否要再次执行上述编组过程，若再执行输入0" << endl;
		cin >> m_judge;
	}
	
	
}