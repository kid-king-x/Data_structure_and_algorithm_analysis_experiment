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
	/*���еĳ�ʼ��*/
	void Init()
	{
		Q.front = 0;
		Q.rear = 0;
	}
	/*���*/
	void Input(int m_data)
	{
		Q.data[Q.rear] = m_data;
		Q.rear++;
	}
	/*����*/
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
	p = (QueueNode*)malloc(sizeof(QueueNode));//Ϊָ��ڵ��ָ�����ռ�
	p->next = NULL;
	s->front = s->rear = p;
}
//�ж϶����Ƿ�Ϊ��,Ϊ�շ�����1����Ϊ�շ��ؼ�0
int Empty(LinkQueue s)
{
	//�ӿյ�������ͷָ���βָ��ָ����ͬ�ĵط�
	if (s.front == s.rear)
	{
		return 1;
	}
	return 0;
}
//��Ӳ���
void Add(LinkQueue* s, int x)
{
	//����һ���ڵ����͵�ָ����������洢Ҫ��ӵ�Ԫ��
	QueueNode* p;
	p = (QueueNode*)malloc(sizeof(QueueNode));
	if (!p) {
		printf("�ڴ����ʧ��\n\n");
		return;
	}
	p->data = x;        //ָ��ָ��Ľڵ����������x
	p->next = NULL;     //ָ��ָ��Ľڵ��ָ������Ϊ��
	s->rear->next = p;   //�����е�βָ���ָ����nextָ��ָ��p��ָ�Ľڵ�
	s->rear = p;         //�����е�βָ�������һλ��ָ�����ӵĽڵ��λ��
}
//��ȡ����Ԫ��
int GetTop(LinkQueue s)
{
	//�����ж϶����Ƿ�Ϊ��
	if (Empty(s))
	{
		printf("����Ϊ�գ��޷���ȡ����Ԫ��\n\n");
		return 0;
	}
	return s.front->next->data;//��Ϊ�յĻ��ͷ��ض���ָ��ָ��ĵ�һ��Ԫ�ص�������
}
//���Ӳ���
void Del(LinkQueue* s, int* e)
{
	//����ʱ����������ӵ�Ԫ��
	QueueNode* p;
	p = s->front->next;
	if (p == s->rear)    //���pָ���˶�β�ڵ�
	{
		s->front = s->rear;  //��ôɾ��֮�����ָ���βָ��ָ��ͬһ��λ��
	}
	*e = p->data;
	s->front->next = p->next;//������ָ��ָ���һ���ڵ����һ���ڵ㡣
	free(p);

}
int main()
{
	
	string m_judge = "0";//�����ж��Ƿ�Ҫ�ٽ��б���

	while (m_judge == "0")
	{
		Queue Q1, Q2;//�����Ļ�
		Q1.Init();
		Q2.Init();

		int depart[11] = {};//�������Ļ�
		depart[0] = 0;//depart[0]�����ݱ�����ʱ�������Ļ�����
		int data[10] = { 1,2,3,4,5,6,7,8,9,10 };

		LinkQueue S1, S2, S3, S4;
		Init(&S1);
		Init(&S2);
		Init(&S3);
		Init(&S4);
		int S1_last = 0;//���ڼ�¼������1����������������Ϊ0����˵��û������
		int S2_last = 0;//���ڼ�¼������2����������������Ϊ0����˵��û������
		int S3_last = 0;//���ڼ�¼������3����������������Ϊ0����˵��û������
		int S4_last = 0;//���ڼ�¼������4����������������Ϊ0����˵��û������

		/*����˳��*/
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
		cout << "��һ���г��ĳ����Ϊ��";
		for (int i = 4; i >= 0; i--)
			cout << data[i] << " ";

		for (int i = 5; i < 10; i++)
		{
			Q2.Input(data[i]);
		}
		cout << endl << "�ڶ����г��ĳ����Ϊ��";
		for (int i = 9; i >= 5; i--)
			cout << data[i] << " ";
		cout << endl;
		int Q1_out = 0, Q2_out = 0;//�����г���ǰ����Ǹ�����
		Q1_out = Q1.Output();
		Q2_out = Q2.Output();
		while (1)
		{
			if (depart[0] == 10)
			{
				cout << "����������" << endl;
				break;
			}

			int judge = 0; //�����жϻ������Ƿ��п��������������
			int car_num = 0;//���ڼ�¼��������������ĳ����
			int buffer_num = 0;//���ڼ�¼�����ĺ���
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

			if (judge == 1)//�������п�����������������
			{
				cout << car_num << "�ų����" << buffer_num << "#������������������������Ϊ";
				for (int i = depart[0]; i > 1; i--)
				{
					cout << depart[i] << ",";
				}
				cout << depart[1] << endl;
			}
			else//���û�п�����������������
			{
				int num = 0;
				if (Empty(S1) == 1)//Ϊ�շ���1
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
					cout << "�޷���ɱ��飬���·����г�����" << endl;
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
						cout << car_num << "�ų��ᾭ" << buffer_num << "#������������������������Ϊ";
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
							cout << temp << "�ų�������" << 1 << "#�����" << endl;
							S1_last = temp;
						}
						else if (min == min2)
						{
							Add(&S2, temp);
							cout << temp << "�ų�������" << 2 << "#�����" << endl;
							S2_last = temp;
						}
						else if (min == min3)
						{
							Add(&S3, temp);
							cout << temp << "�ų�������" << 3 << "#�����" << endl;
							S3_last = temp;
						}
						else if (min == min4)
						{
							Add(&S4, temp);
							cout << temp << "�ų�������" << 4 << "#�����" << endl;
							S4_last = temp;
						}
					}
				}
				
			}
		}
		cout << "�Ƿ�Ҫ�ٴ�ִ������������̣�����ִ������0" << endl;
		cin >> m_judge;
	}
	
	
}