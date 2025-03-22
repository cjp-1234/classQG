#define _CRT_SECURE_NO_WARNINGS
#include"linked.h"
//添加元素的函数
void add(oneway** head)
{	
	system("cls");
	//打印链表
	one_print(*head);
	oneway* p = *head;
	int count = 0;//确定链表的总长度
	int find; //决定添加的位置
	int flag = 0;//判断是否已经到目标位置
	printf("请输入要添加的位置(至少为1)：");
	while (p)//计算总长度
	{
		count++;
		p = p->next;
	}
	while (1)//输入直到输入正确
	{
		scanf("%d", &find);
		if (find >= 1 && find <= count + 1)
		{
			break;
		}
		else
		{
			while (getchar() != '\n');
			printf("输入错误，请重新输入：");
		}
	}
	p = *head;//重置p为头指针
	int num_add;
	//输入直到输入正确
	printf("请输入要添加的数,按enter结束(直到输入正确的数)：\n");
	while (1)
	{
		if (scanf("%d", &num_add)== 1) break;
		else
		{
			while (getchar() != '\n');
			printf("输入错误，请重新输入：");
		}
	}
	if(find==1)
	{
		oneway* t = (oneway*)malloc(sizeof(oneway));
		t->num = num_add;
		t->next = p;
		*head = t;
	}
	else
	{
		//找到要插入位置的前一个节点
		for (int i = 2; i < find; i++) p = p->next;
		//插入新节点
		oneway* t = (oneway*)malloc(sizeof(oneway));
		t->num = num_add;
		t->next = p->next;
		p->next = t;
	}
	printf("插入成功\n");
	Sleep(300);
}
//删除元素的函数
void delete(oneway** head)
{
	system("cls");
	//打印链表
	one_print(*head);
	oneway* p = *head;
	int del=0;//要删除的数
	//输入直到输入正确
	printf("请输入要删除的数,按enter结束(直到输入正确的数)：\n");
	while (1)
	{
		if (scanf("%d", &del) == 1) break;
		else
		{
			while (getchar() != '\n');
			printf("输入错误，请重新输入：");
		}
	}
	//记录当前节点的前一个，方便删除
	oneway x;
	x.next = *head;
	oneway* pev = &x;
	int find = 0;//记录是否找到该数
	//遍历链表，直到找到该数
	while (p)
	{
		if (p->num == del)
		{
			find = 1;
			if (p == *head)
			{
				*head = p->next;
				free(p);
				return;
			}
			else
			{
				pev->next = p->next;
				free(p);
				return;
			}
		}
		p = p->next;
		pev = pev->next;
	}
	if (find == 0)printf("没有找到该数\n");
	else printf("删除成功\n");
	Sleep(500);
}
void must()
{
	//创建并打印链表
	printf("创建单向链表\n");
	oneway* headone = createone();
	char x; int flag = 1;//x 为执行的操作序号，flag判断循环
	system("cls");
	while (flag)
	{
		system("cls");
		//打印菜单，
		printf("------1.添加----------\n");
		printf("------2.删除----------\n");
		printf("------3.进行下一步----\n");
		x = _getch();
		switch (x)
		{
		case '1':
		{
			add(&headone);
			one_print(headone);
			system("pause");//执行完打印链表
			break;
		}
		case '2':delete(&headone); one_print(headone); system("pause"); break;
		case '3':flag = 0;
		default:printf("无效的选择，请重新输入\n");
		}
	}
	//释放链表
	oneway*p = headone;
	oneway* cur = p;
	while (p != NULL)
	{
		cur = p;
		p = p->next;
		free(cur);
	}
	system("cls");
	printf("创建双向链表\n");
	twoway*headtwo=createtwo();
	printf("打印链表\n");
	two_print(headtwo);
	system("pause");
	//释放链表
	twoway*t = headtwo;
	twoway*curr = t;
	while (t != NULL)
	{
		curr = t;
		t = t->next;
		free(curr);
	}
}