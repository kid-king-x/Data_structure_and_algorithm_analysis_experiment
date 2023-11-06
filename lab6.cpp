#include <iostream>
#include <cstring>
using namespace std;

#define card_num 54
string card[54] = { "DaWang", "XiaoWang", "HeitaoA", "Heitao2", "Heitao3", "Heitao4", "Heitao5",
"Heitao6", "Heitao7", "Heitao8", "Heitao9", "Heitao10", "HeitaoJ", "HeitaoQ", "HeitaoK", "HongtaoA",
 "Hongtao2",  "Hongtao3",  "Hongtao4",  "Hongtao5",  "Hongtao6",  "Hongtao7",  "Hongtao8",  "Hongtao9",
 "Hongtao10",  "HongtaoJ",  "HongtaoQ",  "HongtaoK", "FangkuaiA", "Fangkuai2", "Fangkuai3", "Fangkuai4"
, "Fangkuai5" , "Fangkuai6" , "Fangkuai7" , "Fangkuai8" , "Fangkuai9" , "Fangkuai10" , "FangkuaiJ" , "FangkuaiQ"
, "FangkuaiK", "MeihuaA", "Meihua2" , "Meihua3" , "Meihua4" , "Meihua5" , "Meihua6" , "Meihua7"
, "Meihua8" , "Meihua9", "Meihua10" , "MeihuaJ" , "MeihuaQ" , "MeihuaK" };

char shunxu[14] = { '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', 'g' };
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

int search_card(string value, list* member)
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

list* lipai(list* member)
{
	list* p = member;
	list* member_new = new list;
	list* node;
	list* member_end = member_new;
	string pai[10] = {};
	int num = 0;

	for (int i = 0; i < 14; i++)
	{
		while (p->next != nullptr)
		{
			p = p->next;
			if (p->val[p->val.length() - 1] == shunxu[i])
			{
				pai[num] = p->val;
				num++;
			}
		}
		p = member;

		//��ȷ���ɲ������õĴ��룬�������Կ�
		if (num == 1)
		{
			node = new list;
			node->val = pai[0];
			member_end->next = node;
			member_end = node;
			member_end->next = NULL;
		}
		if (num > 1)
		{
			for (int j = 0; j < num; j++)
			{
				if (pai[j][0] == 'F')
				{
					node = new list;
					node->val = pai[j];
					member_end->next = node;
					member_end = node;
					member_end->next = NULL;
				}
			}
			for (int j = 0; j < num; j++)
			{
				if (pai[j][0] == 'M')
				{
					node = new list;
					node->val = pai[j];
					member_end->next = node;
					member_end = node;
					member_end->next = NULL;
				}
			}
			for (int j = 0; j < num; j++)
			{
				if (pai[j][0] == 'H' && pai[j][1] == 'o')
				{
					node = new list;
					node->val = pai[j];
					member_end->next = node;
					member_end = node;
					member_end->next = NULL;
				}
			}
			for (int j = 0; j < num; j++)
			{
				if (pai[j][0] == 'H' && pai[j][1] == 'e')
				{
					node = new list;
					node->val = pai[j];
					member_end->next = node;
					member_end = node;
					member_end->next = NULL;
				}
			}
			for (int j = 0; j < num; j++)
			{
				if (pai[j][0] == 'X')
				{
					node = new list;
					node->val = pai[j];
					member_end->next = node;
					member_end = node;
					member_end->next = NULL;
				}
			}
			for (int j = 0; j < num; j++)
			{
				if (pai[j][0] == 'D')
				{
					node = new list;
					node->val = pai[j];
					member_end->next = node;
					member_end = node;
					member_end->next = NULL;
				}
			}
		}
		num = 0;
	}
	return member_new;
}
//�����ж������������Ƿ�Ϊ��
int judge_NULL(list* member)
{
	int judge = 1;
	int pai_num = 0;
	while (member->next != nullptr)
	{
		member = member->next;
		pai_num++;
	}
	if (pai_num == 0)
		judge = 0;
	return judge;
}
int main()
{
	int n = 54;
	RandomCards(card, card_num);
	list* head = createlist(n);
	cout << "Ŀǰ�ƶ�˳��Ϊ:" << endl;
	printlist(head);
	cout << endl;

	list* member1 = new list;
	list* member2 = new list;
	list* member3 = new list;
	list* rest = new list;
	list* rest_end = rest;
	fapai(member1, member2, member3, head);


	cout << "---------------���Ƴɹ�---------------" << endl << "�û�A����Ϊ��" << endl;
	printlist(member1);
	cout << "�û�B����Ϊ��" << endl;
	printlist(member2);
	cout << "�û�C����Ϊ��" << endl;
	printlist(member3);
	cout << endl;
	list* member1_new = new list;
	list* member2_new = new list;
	list* member3_new = new list;
	member1_new = lipai(member1);
	member2_new = lipai(member2);
	member3_new = lipai(member3);
	cout << "---------------���Ƴɹ�---------------" << endl << "�û�A����Ϊ��" << endl;
	printlist(member1_new);
	cout << "�û�B����Ϊ��" << endl;
	printlist(member2_new);
	cout << "�û�C����Ϊ��" << endl;
	printlist(member3_new);

	cout << endl << "---------------��Ϸ��ʼ---------------" << endl <<
		"��ʱ�������A����������Ҫ�����ƣ��������0����ʾ���ƽ��������ʲô��û������0����ʾ������" << endl;
	int judge = 2;
	int A_num = 0;//���ڼ�¼���A��������
	int B_num = 0;//���ڼ�¼���B��������
	int C_num = 0;//���ڼ�¼���C��������
	int lun = 0;
	char pai_valA;//���ڼ�¼���A������ֵ
	char pai_valB;//���ڼ�¼���B������ֵ
	char pai_valC;//���ڼ�¼���C������ֵ

	int A_guo = 1;//���ڱ������A�Ƿ��й�
	int B_guo = 1;//���ڱ������B�Ƿ��й�
	int C_guo = 1;//���ڱ������C�Ƿ��й�

	int judge_d = 1;
	while (judge_d == 1)
	{
		int judge_member1_num = judge_NULL(member1_new);//�����ж����A�Ƿ�������


		A_guo = 1;
		if (judge_member1_num == 0)
		{
			cout << "���A��ɳ���" << endl;
			A_guo = 0;
		}
		else
		{
			int judge_member1 = 0;//�����ж����A�Ƿ�����������
			while (judge_member1 == 0)
			{
				string card_val[18] = {};
				int pai_num = 0;//������
				string judge_new = "1";
				while (judge_new != "0")
				{
					int flag_judge = 1;
					cin >> judge_new;
					if (judge_new == "0")
						break;
					if (search_card(judge_new, member1_new) == -1)
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
				if (pai_num == 0)
				{
					cout << "��ѡ���ˡ���������ʾ���������" << endl;
					A_guo = 0;
					if (lun == 0)
						flag = 0;
				}
				if (flag == 1)//������ƺ���
				{
					pai_valA = card_val[0][card_val[0].length() - 1];
					for (int i = 0; i < pai_num; i++)
					{
						int pai = search_card(card_val[i], member1_new);
						list* node = new list;
						node->val = card_val[i];
						rest_end->next = node;
						rest_end = node;
						rest_end->next = NULL;
						delete_card(member1_new, pai);
					}
					cout << "��ʱ�ƶ��е���Ϊ��" << endl;
					printlist(rest);
					cout << "�û�A����Ϊ��" << endl;
					printlist(member1_new);
					cout << "�û�B����Ϊ��" << endl;
					printlist(member2_new);
					cout << "�û�C����Ϊ��" << endl;
					printlist(member3_new);
					lun++;
					judge_member1 = 1;
					A_num = pai_num;
					if(A_num != 0)
						A_guo = 1;
				}
				if (flag == 0)
				{
					cout << "��ĳ��Ʋ������������³���" << endl;
					flag = 1;
				}
			}
		}

		B_guo = 1;
		int judge_member2_num = judge_NULL(member2_new);//�����ж����B�Ƿ�������
		if (judge_member2_num == 0)
		{
			cout << "���B��ɳ���" << endl;
			B_guo = 0;
		}
		else
		{
			if (A_guo == 0)
			{
				if (C_guo == 0)
				{
					list* member2_transfer = member2_new;
					member2_transfer = member2_transfer->next;
					cout << endl << "���B�ĳ���Ϊ" << endl << member2_transfer->val << " " << endl;
					pai_valB = member2_transfer->val[member2_transfer->val.length() - 1];
					int pai = search_card(member2_transfer->val, member2_new);
					list* node = new list;
					node->val = member2_transfer->val;
					rest_end->next = node;
					rest_end = node;
					rest_end->next = NULL;
					delete_card(member2_new, pai);
					B_num = 1;
					B_guo = 1;
				}
				else
				{
					B_num = C_num;//���B�ĳ�����
					cout << endl << "��ʱ�ֵ����B�ĳ���" << endl;
					int shunxu_val = 0;//���ڱ���A��������shunxu��������е���

					for (int i = 0; i < 14; i++)
					{
						if (pai_valC == shunxu[i])
						{
							shunxu_val = i;
							break;
						}
					}
					//cout << pai_val << endl;
					list* member2_transfer = member2_new;

					int member2_num_val = 0;//�����жϴ������A���Ƶ������ж���
					int member2_num_shunxu = 0;//�����ж����B����Ƶ�˳�����

					int flag = 0;//�����ж����B�Ƿ�����������
					for (int i = shunxu_val + 1; i < 14; i++)
					{
						while (member2_transfer->next != nullptr)
						{
							member2_transfer = member2_transfer->next;
							if (member2_transfer->val[member2_transfer->val.length() - 1] == shunxu[i])
							{
								member2_num_val++;
								//cout << member2_num << endl;
							}
						}
						if (member2_num_val >= C_num)
						{
							flag = 1;
							member2_num_shunxu = i;
							break;

						}

						else
						{
							member2_num_val = 0;
							member2_transfer = member2_new;
						}

					}
					if (flag == 0)
					{
						cout << "���Bû���������ƣ�ѡ�񡰹��� " << endl;
						cout << "��ʱ�ƶ��е���Ϊ��" << endl;
						printlist(rest);
						cout << "�û�A����Ϊ��" << endl;
						printlist(member1_new);
						cout << "�û�B����Ϊ��" << endl;
						printlist(member2_new);
						cout << "�û�C����Ϊ��" << endl;
						printlist(member3_new);
						B_num = 0;
						B_guo = 0;
					}
					if (flag == 1)
					{
						member2_transfer = member2_new;
						int member2_chupai = 0;//���ڱ������B���˼�������
						cout << "���B�ĳ���Ϊ" << endl;
						while (member2_transfer->next != nullptr)
						{
							member2_transfer = member2_transfer->next;
							if (member2_transfer->val[member2_transfer->val.length() - 1] == shunxu[member2_num_shunxu])
							{
								if (member2_chupai < B_num)
								{
									cout << member2_transfer->val << " ";
									pai_valB = member2_transfer->val[member2_transfer->val.length() - 1];
									int pai = search_card(member2_transfer->val, member2_new);
									list* node = new list;
									node->val = member2_transfer->val;
									rest_end->next = node;
									rest_end = node;
									rest_end->next = NULL;
									delete_card(member2_new, pai);
									member2_chupai++;
								}
								else
									break;
							}

						}
						cout << endl;
						cout << "��ʱ�ƶ��е���Ϊ��" << endl;
						printlist(rest);
						cout << "�û�A����Ϊ��" << endl;
						printlist(member1_new);
						cout << "�û�B����Ϊ��" << endl;
						printlist(member2_new);
						cout << "�û�C����Ϊ��" << endl;
						printlist(member3_new);
						B_num = C_num;
						B_guo = 1;
					}
				}
			}
			else
			{
				B_num = A_num;//���B�ĳ�����
				cout << endl << "��ʱ�ֵ����B�ĳ���" << endl;
				int shunxu_val = 0;//���ڱ���A��������shunxu��������е���

				for (int i = 0; i < 14; i++)
				{
					if (pai_valA == shunxu[i])
					{
						shunxu_val = i;
						break;
					}
				}

				list* member2_transfer = member2_new;

				int member2_num_val = 0;//�����жϴ������A���Ƶ������ж���
				int member2_num_shunxu = 0;//�����ж����B����Ƶ�˳�����

				int flag = 0;//�����ж����B�Ƿ�����������
				for (int i = shunxu_val + 1; i < 14; i++)
				{
					while (member2_transfer->next != nullptr)
					{
						member2_transfer = member2_transfer->next;
						if (member2_transfer->val[member2_transfer->val.length() - 1] == shunxu[i])
						{
							member2_num_val++;
							//cout << member2_num << endl;
						}
					}
					if (member2_num_val >= A_num)
					{
						flag = 1;
						member2_num_shunxu = i;
						break;

					}

					else
					{
						member2_num_val = 0;
						member2_transfer = member2_new;
					}

				}
				if (flag == 0)
				{
					cout << "���Bû���������ƣ�ѡ�񡰹��� " << endl;
					cout << "��ʱ�ƶ��е���Ϊ��" << endl;
					printlist(rest);
					cout << "�û�A����Ϊ��" << endl;
					printlist(member1_new);
					cout << "�û�B����Ϊ��" << endl;
					printlist(member2_new);
					cout << "�û�C����Ϊ��" << endl;
					printlist(member3_new);
					B_num = 0;
					B_guo = 0;
				}
				if (flag == 1)
				{
					member2_transfer = member2_new;
					int member2_chupai = 0;//���ڱ������B���˼�������
					cout << "���B�ĳ���Ϊ" << endl;
					while (member2_transfer->next != nullptr)
					{
						member2_transfer = member2_transfer->next;
						if (member2_transfer->val[member2_transfer->val.length() - 1] == shunxu[member2_num_shunxu])
						{
							if (member2_chupai < A_num)
							{
								cout << member2_transfer->val << " ";
								pai_valB = member2_transfer->val[member2_transfer->val.length() - 1];
								int pai = search_card(member2_transfer->val, member2_new);
								list* node = new list;
								node->val = member2_transfer->val;
								rest_end->next = node;
								rest_end = node;
								rest_end->next = NULL;
								delete_card(member2_new, pai);
								member2_chupai++;
							}
							else
								break;
						}

					}
					cout << endl;
					cout << "��ʱ�ƶ��е���Ϊ��" << endl;
					printlist(rest);
					cout << "�û�A����Ϊ��" << endl;
					printlist(member1_new);
					cout << "�û�B����Ϊ��" << endl;
					printlist(member2_new);
					cout << "�û�C����Ϊ��" << endl;
					printlist(member3_new);
					B_num = A_num;
					B_guo = 1;
				}
			}
		}

		C_guo = 1;
		int judge_member3_num = judge_NULL(member3_new);//�����ж����C�Ƿ�������
		if (judge_member3_num == 0)
		{
			cout << "���C��ɳ���" << endl;
			C_guo = 0;
		}
		else
		{
			if (B_guo == 0)
			{
				if (A_guo == 0)
				{
					list* member3_transfer = member3_new;
					member3_transfer = member3_transfer->next;
					cout << "���C�ĳ���Ϊ" << endl << member3_transfer->val << " ";
					pai_valC = member3_transfer->val[member3_transfer->val.length() - 1];
					int pai = search_card(member3_transfer->val, member3_new);
					list* node = new list;
					node->val = member3_transfer->val;
					rest_end->next = node;
					rest_end = node;
					rest_end->next = NULL;
					delete_card(member3_new, pai);
					C_num = 1;
					C_guo = 1;
				}
				else
				{
					C_num = A_num;//���C�ĳ�����
					cout << endl << "��ʱ�ֵ����C�ĳ���" << endl;
					int shunxu_val = 0;//���ڱ���B��������shunxu��������е���

					for (int i = 0; i < 14; i++)
					{
						if (pai_valA == shunxu[i])
						{
							shunxu_val = i;
							break;
						}
					}

					//cout << pai_val << endl;
					list* member3_transfer = member3_new;

					int member3_num_val = 0;//�����жϴ������B���Ƶ������ж���
					int member3_num_shunxu = 0;//�����ж����C����Ƶ�˳�����

					int flag = 0;//�����ж����B�Ƿ�����������
					for (int i = shunxu_val + 1; i < 14; i++)
					{
						while (member3_transfer->next != nullptr)
						{
							member3_transfer = member3_transfer->next;
							if (member3_transfer->val[member3_transfer->val.length() - 1] == shunxu[i])
							{
								C_num++;
								//cout << member2_num << endl;
							}
						}
						if (member3_num_val >= A_num)
						{
							flag = 1;
							member3_num_shunxu = i;
							break;

						}

						else
						{
							member3_num_val = 0;
							member3_transfer = member3_new;
						}

					}
					if (flag == 0)
					{
						cout << "���Cû���������ƣ�ѡ�񡰹��� " << endl;
						cout << "��ʱ�ƶ��е���Ϊ��" << endl;
						printlist(rest);
						cout << "�û�A����Ϊ��" << endl;
						printlist(member1_new);
						cout << "�û�B����Ϊ��" << endl;
						printlist(member2_new);
						cout << "�û�C����Ϊ��" << endl;
						printlist(member3_new);
						C_num = 0;
						C_guo = 0;
					}
					if (flag == 1)
					{
						member3_transfer = member3_new;
						int member3_chupai = 0;//���ڱ������B���˼�������
						cout << "���C�ĳ���Ϊ" << endl;
						while (member3_transfer->next != nullptr)
						{
							member3_transfer = member3_transfer->next;
							if (member3_transfer->val[member3_transfer->val.length() - 1] == shunxu[member3_num_shunxu])
							{
								if (member3_chupai < A_num)
								{
									cout << member3_transfer->val << " ";
									pai_valC = member3_transfer->val[member3_transfer->val.length() - 1];
									int pai = search_card(member3_transfer->val, member3_new);
									list* node = new list;
									node->val = member3_transfer->val;
									rest_end->next = node;
									rest_end = node;
									rest_end->next = NULL;
									delete_card(member3_new, pai);
									member3_chupai++;
								}
								else
									break;
							}
						}
						C_num = A_num;
						cout << endl;
						cout << "��ʱ�ƶ��е���Ϊ��" << endl;
						printlist(rest);
						cout << "�û�A����Ϊ��" << endl;
						printlist(member1_new);
						cout << "�û�B����Ϊ��" << endl;
						printlist(member2_new);
						cout << "�û�C����Ϊ��" << endl;
						printlist(member3_new);
						C_guo = 1;
					}
				}
			}
			else
			{
				C_num = B_num;//���C�ĳ�����
				cout << endl << "��ʱ�ֵ����C�ĳ���" << endl;
				int shunxu_val = 0;//���ڱ���B��������shunxu��������е���

				for (int i = 0; i < 14; i++)
				{
					if (pai_valB == shunxu[i])
					{
						shunxu_val = i;
						break;
					}
				}

				list* member3_transfer = member3_new;

				int member3_num_val = 0;//�����жϴ������B���Ƶ������ж���
				int member3_num_shunxu = 0;//�����ж����C����Ƶ�˳�����

				int flag = 0;//�����ж����B�Ƿ�����������
				for (int i = shunxu_val + 1; i < 14; i++)
				{
					while (member3_transfer->next != nullptr)
					{
						member3_transfer = member3_transfer->next;
						if (member3_transfer->val[member3_transfer->val.length() - 1] == shunxu[i])
						{
							member3_num_val++;
							//cout << member2_num << endl;
						}
					}
					if (member3_num_val >= B_num)
					{
						flag = 1;
						member3_num_shunxu = i;
						break;

					}

					else
					{
						member3_num_val = 0;
						member3_transfer = member3_new;
					}

				}
				if (flag == 0)
				{
					cout << "���Cû���������ƣ�ѡ�񡰹��� " << endl;
					cout << "��ʱ�ƶ��е���Ϊ��" << endl;
					printlist(rest);
					cout << "�û�A����Ϊ��" << endl;
					printlist(member1_new);
					cout << "�û�B����Ϊ��" << endl;
					printlist(member2_new);
					cout << "�û�C����Ϊ��" << endl;
					printlist(member3_new);
					C_num = 0;
					C_guo = 0;
				}
				if (flag == 1)
				{
					member3_transfer = member3_new;
					int member3_chupai = 0;//���ڱ������B���˼�������
					cout << "���C�ĳ���Ϊ" << endl;
					while (member3_transfer->next != nullptr)
					{
						member3_transfer = member3_transfer->next;
						if (member3_transfer->val[member3_transfer->val.length() - 1] == shunxu[member3_num_shunxu])
						{
							if (member3_chupai < B_num)
							{
								cout << member3_transfer->val << " ";
								pai_valC = member3_transfer->val[member3_transfer->val.length() - 1];
								int pai = search_card(member3_transfer->val, member3_new);
								list* node = new list;
								node->val = member3_transfer->val;
								rest_end->next = node;
								rest_end = node;
								rest_end->next = NULL;
								delete_card(member3_new, pai);
								member3_chupai++;
							}
							else
								break;
						}
					}
					C_num = B_num;
					cout << endl;
					cout << "��ʱ�ƶ��е���Ϊ��" << endl;
					printlist(rest);
					cout << "�û�A����Ϊ��" << endl;
					printlist(member1_new);
					cout << "�û�B����Ϊ��" << endl;
					printlist(member2_new);
					cout << "�û�C����Ϊ��" << endl;
					printlist(member3_new);
					C_guo = 1;
				}
			}
		}


		if ((judge_member1_num + judge_member2_num + judge_member3_num) <= 1)
		{
			judge_d = 0;
			break;
		}
		cout << "��ʱ�ֵ����A����" << endl;
	}
	cout << "��Ϸ����" << endl;
}