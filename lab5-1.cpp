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
	list* head = new list;//创建头节点，给头节点分配地址
	list* end = head;//另尾节点等于头节点
	list* node;//中间节点
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
		now = rand() % (num - i) + i;//随机生成一个从i到（num - 1）的数
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
	cout << "如果要展示牌堆，请输入数字1，否则随意输入" << endl;
	cin >> judge;
	while (judge == "1")
	{
		cout << "目前牌堆顺序为:" << endl;
		printlist(head);
		cout << "请问是否还需要再展示牌堆，如果需要请输入数字1， 否则随意输入" << endl;
		cin >> judge;
	}
	
	list* member1 = new list;
	list* member2 = new list;
	list* member3 = new list;
	list* rest = new list;
	list* rest_end = rest;
	fapai(member1, member2, member3, head);
	cout << "---------------发牌成功---------------" << endl << "用户1的牌为：" << endl;
	printlist(member1);
	cout << "用户2的牌为：" << endl;
	printlist(member2);
	cout << "用户3的牌为：" << endl;
	printlist(member3);
	judge = "1";
	while ((judge == "1") || (judge == "2") || (judge == "3"))
	{
		cout << "输入1，2，3代表你想要出牌的玩家，输入其他代表游戏退出" << endl;
		cin >> judge;
		if (judge == "1")
		{
			cout << "请输入你需要出的牌，如果输入0， 表示出牌结束" << endl;
			string card_val[18] = {};
			int pai_num = 0;//出牌数
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
					cout << "该用户手中没有你要的牌" << endl;
				}					
				if (flag_judge == 1)
				{
					card_val[pai_num] = judge_new;
					pai_num++;
				}						
			}
			int flag = 1;//判断是否是合理出牌
			if (pai_num > 1)
			{
				int pai_judge = card_val[0][card_val[0].length() - 1];
				for (int i = 1; i < pai_num; i++)
				{
					if (pai_judge != card_val[i][card_val[i].length() - 1])
						flag = 0;
				}
			}
			if (flag == 1)//代表出牌合理
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
				cout << "此时牌堆中的牌为：" << endl;
				printlist(rest);
				cout << "用户1的牌为：" << endl;
				printlist(member1);
				cout << "用户2的牌为：" << endl;
				printlist(member2);
				cout << "用户3的牌为：" << endl;
				printlist(member3);
			}
			if (flag == 0)
			{
				cout << "你的出牌并不合理，请重新选择用户出牌" << endl;
				cin >> judge;
				flag = 1;
			}
		}
		else if (judge == "2")
		{
			cout << "请输入你需要出的牌，如果输入0， 表示出牌结束" << endl;
			string card_val[18] = {};
			int pai_num = 0;//出牌数
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
					cout << "该用户手中没有你要的牌" << endl;
				}
				if (flag_judge == 1)
				{
					card_val[pai_num] = judge_new;
					pai_num++;
				}
			}
			int flag = 1;//判断是否是合理出牌
			if (pai_num > 1)
			{
				int pai_judge = card_val[0][card_val[0].length() - 1];
				for (int i = 1; i < pai_num; i++)
				{
					if (pai_judge != card_val[i][card_val[i].length() - 1])
						flag = 0;
				}
			}
			if (flag == 1)//代表出牌合理
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
				cout << "此时牌堆中的牌为：" << endl;
				printlist(rest);
				cout << "用户1的牌为：" << endl;
				printlist(member1);
				cout << "用户2的牌为：" << endl;
				printlist(member2);
				cout << "用户3的牌为：" << endl;
				printlist(member3);
			}
			if (flag == 0)
			{
				cout << "你的出牌并不合理，请重新选择用户出牌" << endl;
				cin >> judge;
				flag = 1;
			}
		}
		else if (judge == "3")
		{
			cout << "请输入你需要出的牌，如果输入0， 表示出牌结束" << endl;
			string card_val[18] = {};
			int pai_num = 0;//出牌数
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
					cout << "该用户手中没有你要的牌" << endl;
				}
				if (flag_judge == 1)
				{
					card_val[pai_num] = judge_new;
					pai_num++;
				}
			}
			int flag = 1;//判断是否是合理出牌
			if (pai_num > 1)
			{
				int pai_judge = card_val[0][card_val[0].length() - 1];
				for (int i = 1; i < pai_num; i++)
				{
					if (pai_judge != card_val[i][card_val[i].length() - 1])
						flag = 0;
				}
			}
			if (flag == 1)//代表出牌合理
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
				cout << "此时牌堆中的牌为：" << endl;
				printlist(rest);
				cout << "用户1的牌为：" << endl;
				printlist(member1);
				cout << "用户2的牌为：" << endl;
				printlist(member2);
				cout << "用户3的牌为：" << endl;
				printlist(member3);
			}
			if (flag == 0)
			{
				cout << "你的出牌并不合理，请重新选择用户出牌" << endl;
				cin >> judge;
				flag = 1;
			}
		}
	}
	


	
	

	
}