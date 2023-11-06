#include <iostream>
#include <cstring>
using namespace std;

#define card_num 54
string card[54] = { "DaWang", "XiaoWang", "HeitaoA", "Heitao2", "Heitao3", "Heitao4", "Heitao5", 
"Heitao6", "Heitao7", "Heitao8", "Heitao9", "Heitao10", "HeitaoJ", "HeitaoQ", "HeitaoK", "HongtaoA",
 "Hongtao2",  "Hongtao3",  "Hongtao4",  "Hongtao5",  "Hongtao6",  "Hongtao7",  "Hongtao8",  "Hongtao9", 
 "Hongtao10",  "HongtaoJ",  "HongtaoQ",  "HongtaoK", "FangkuaiA", "Fangkuai2", "Fangkuai3", "Fangkuai4"
, "Fangkuai5" , "Fangkuai6" , "Fangkuai7" , "Fangkuai8" , "Fangkuai9" , "Fangkuai10" , "FangkuaiJ" , "FangkuaiQ" 
, "FangkuaiK", "MeihuangA", "Meihuang2" , "Meihuang3" , "Meihuang4" , "Meihuang5" , "Meihuang6" , "Meihuang7" 
, "Meihuang8" , "Meihuang9", "Meihuang10" , "MeihuangJ" , "MeihuangQ" , "MeihuangK" };

struct list
{
	string val;
	list* next;
};



list* createlist(int n)
{
	list* head = new list;//����ͷ�ڵ㣬��ͷ�ڵ�����ַ
	list* end = head;//��β�ڵ����ͷ�ڵ�
	list* node;//�м�ڵ�
	for (int i = 0; i < n; i++)
	{
		node = new list;
		node->val = card[i];
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}

void printlist(list* head)
{
	list* p = head;
	while (p->next != nullptr)
	{
		p = p->next;
		cout << p->val << " ";
	}
	cout << endl;
}

void delete_card(list* head, int num)
{
	for (int i = 1; i < num; i++)
	{
			head = head->next;
	}
	if (head->next == NULL)
		return;
	list* temp = head->next;
	head->next = temp->next;
}
void RandomCards(string* arr, int num)
{
	int now;
	srand(time(NULL));
	for (int i = 0; i < num; i++)
	{
		now = rand() % (num - i) + i;//�������һ����i����num - 1������
		if (now != i)
		{
			string temp = arr[i];
			arr[i] = arr[now];
			arr[now] = temp;
		}
	}
}

void fapai(list* member1, list* member2, list* member3, list* head)
{
	for (int i = 0; i < card_num; i++)
	{
		head = head->next;
		if (i % 3 == 0)
		{
			member1->next = head;
			member1 = member1->next;
		}
		if (i % 3 == 1)
		{
			member2->next = head;
			member2 = member2->next;
		}
		if (i % 3 == 2)
		{
			member3->next = head;
			member3 = member3->next;
		}
	}
	member1->next = NULL;
	member2->next = NULL;
	member3->next = NULL;
}

int search_card(string value,list* member)
{
	int i = 0;
	while (member->next != nullptr)
	{
		member = member->next;
		i++;
		if (member->val == value)
		{
			return i;
		}
	}
	
	return -1;
}

int main()
{
	int n = 54;
	RandomCards(card, card_num);
	list* head = createlist(n);
	string judge = "1";
	cout << "���Ҫչʾ�ƶѣ�����������1��������������" << endl;
	cin >> judge;
	while (judge == "1")
	{
		cout << "Ŀǰ�ƶ�˳��Ϊ:" << endl;
		printlist(head);
		cout << "�����Ƿ���Ҫ��չʾ�ƶѣ������Ҫ����������1�� ������������" << endl;
		cin >> judge;
	}
	
	list* member1 = new list;
	list* member2 = new list;
	list* member3 = new list;
	list* rest = new list;
	list* rest_end = rest;
	fapai(member1, member2, member3, head);
	cout << "---------------���Ƴɹ�---------------" << endl << "�û�1����Ϊ��" << endl;
	printlist(member1);
	cout << "�û�2����Ϊ��" << endl;
	printlist(member2);
	cout << "�û�3����Ϊ��" << endl;
	printlist(member3);
	judge = "1";
	while ((judge == "1") || (judge == "2") || (judge == "3"))
	{
		cout << "����1��2��3��������Ҫ���Ƶ���ң���������������Ϸ�˳�" << endl;
		cin >> judge;
		if (judge == "1")
		{
			cout << "����������Ҫ�����ƣ��������0�� ��ʾ���ƽ���" << endl;
			string card_val[18] = {};
			int pai_num = 0;//������
			string judge_new = "1";
			while (judge_new != "0")
			{
				int flag_judge = 1;
				cin >> judge_new;
				if (judge_new == "0")
					break;
				if (search_card(judge_new, member1) == -1)
				{
					flag_judge = 0;
					cout << "���û�����û����Ҫ����" << endl;
				}					
				if (flag_judge == 1)
				{
					card_val[pai_num] = judge_new;
					pai_num++;
				}						
			}
			int flag = 1;//�ж��Ƿ��Ǻ������
			if (pai_num > 1)
			{
				int pai_judge = card_val[0][card_val[0].length() - 1];
				for (int i = 1; i < pai_num; i++)
				{
					if (pai_judge != card_val[i][card_val[i].length() - 1])
						flag = 0;
				}
			}
			if (flag == 1)//������ƺ���
			{
				for (int i = 0; i < pai_num; i++)
				{
					int pai = search_card(card_val[i], member1);
					list* node = new list;
					node->val = card_val[i];
					rest_end->next = node;
					rest_end = node;
					rest_end->next = NULL;
					delete_card(member1, pai);					
				}
				cout << "��ʱ�ƶ��е���Ϊ��" << endl;
				printlist(rest);
				cout << "�û�1����Ϊ��" << endl;
				printlist(member1);
				cout << "�û�2����Ϊ��" << endl;
				printlist(member2);
				cout << "�û�3����Ϊ��" << endl;
				printlist(member3);
			}
			if (flag == 0)
			{
				cout << "��ĳ��Ʋ�������������ѡ���û�����" << endl;
				cin >> judge;
				flag = 1;
			}
		}
		else if (judge == "2")
		{
			cout << "����������Ҫ�����ƣ��������0�� ��ʾ���ƽ���" << endl;
			string card_val[18] = {};
			int pai_num = 0;//������
			string judge_new = "1";
			while (judge_new != "0")
			{
				int flag_judge = 1;
				cin >> judge_new;
				if (judge_new == "0")
					break;
				if (search_card(judge_new, member2) == -1)
				{
					flag_judge = 0;
					cout << "���û�����û����Ҫ����" << endl;
				}
				if (flag_judge == 1)
				{
					card_val[pai_num] = judge_new;
					pai_num++;
				}
			}
			int flag = 1;//�ж��Ƿ��Ǻ������
			if (pai_num > 1)
			{
				int pai_judge = card_val[0][card_val[0].length() - 1];
				for (int i = 1; i < pai_num; i++)
				{
					if (pai_judge != card_val[i][card_val[i].length() - 1])
						flag = 0;
				}
			}
			if (flag == 1)//������ƺ���
			{
				for (int i = 0; i < pai_num; i++)
				{
					int pai = search_card(card_val[i], member2);
					list* node = new list;
					node->val = card_val[i];
					rest_end->next = node;
					rest_end = node;
					rest_end->next = NULL;
					delete_card(member2, pai);
				}
				cout << "��ʱ�ƶ��е���Ϊ��" << endl;
				printlist(rest);
				cout << "�û�1����Ϊ��" << endl;
				printlist(member1);
				cout << "�û�2����Ϊ��" << endl;
				printlist(member2);
				cout << "�û�3����Ϊ��" << endl;
				printlist(member3);
			}
			if (flag == 0)
			{
				cout << "��ĳ��Ʋ�������������ѡ���û�����" << endl;
				cin >> judge;
				flag = 1;
			}
		}
		else if (judge == "3")
		{
			cout << "����������Ҫ�����ƣ��������0�� ��ʾ���ƽ���" << endl;
			string card_val[18] = {};
			int pai_num = 0;//������
			string judge_new = "1";
			while (judge_new != "0")
			{
				int flag_judge = 1;
				cin >> judge_new;
				if (judge_new == "0")
					break;
				if (search_card(judge_new, member3) == -1)
				{
					flag_judge = 0;
					cout << "���û�����û����Ҫ����" << endl;
				}
				if (flag_judge == 1)
				{
					card_val[pai_num] = judge_new;
					pai_num++;
				}
			}
			int flag = 1;//�ж��Ƿ��Ǻ������
			if (pai_num > 1)
			{
				int pai_judge = card_val[0][card_val[0].length() - 1];
				for (int i = 1; i < pai_num; i++)
				{
					if (pai_judge != card_val[i][card_val[i].length() - 1])
						flag = 0;
				}
			}
			if (flag == 1)//������ƺ���
			{
				for (int i = 0; i < pai_num; i++)
				{
					int pai = search_card(card_val[i], member3);
					list* node = new list;
					node->val = card_val[i];
					rest_end->next = node;
					rest_end = node;
					rest_end->next = NULL;
					delete_card(member3, pai);
				}
				cout << "��ʱ�ƶ��е���Ϊ��" << endl;
				printlist(rest);
				cout << "�û�1����Ϊ��" << endl;
				printlist(member1);
				cout << "�û�2����Ϊ��" << endl;
				printlist(member2);
				cout << "�û�3����Ϊ��" << endl;
				printlist(member3);
			}
			if (flag == 0)
			{
				cout << "��ĳ��Ʋ�������������ѡ���û�����" << endl;
				cin >> judge;
				flag = 1;
			}
		}
	}
	


	
	

	
}