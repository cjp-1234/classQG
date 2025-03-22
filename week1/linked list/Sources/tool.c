#define _CRT_SECURE_NO_WARNINGS
#include"linked.h"
//创建一个单向链表的函数
oneway* createone()
{
	oneway* head = NULL;//创建头节点和尾节点
	oneway* tail = NULL;
	oneway* p;
	printf("请输入数字，用空格隔开，输入'-99'时停止输入\n");
	while (1)//循环读入，当读入-99时退出
	{
		p = (oneway*)malloc(sizeof(oneway));
		if (p == NULL)
		{
			printf("内存分配失败\n");
			return NULL;
		}
		scanf("%d", &p->num);
		//判断是否为-99，如果不是，把节点加进链表
		if (p->num != -99)
		{
			if (head == NULL)
			{
				head = p;
				tail = p;
			}
			else
			{
				tail->next = p;
				tail = p;
			}
			p->next = NULL;
		}
		else
		{
			free(p);
			break;
		}
	}
	return head;//最后返回头结点
}

//创建双向链表
twoway* createtwo()
{
	twoway* head = NULL;//创建头节点和尾节点
	twoway* tail = NULL;
	twoway* p;
	printf("请输入数字，用空格隔开，输入'-99'时停止输入\n");
	while (1)//循环读入，当读入-99时退出
	{
		p = (twoway*)malloc(sizeof(twoway));
		if (p == NULL)
		{
			printf("内存分配失败");
			return NULL;
		}
		scanf("%d", &p->num);
		//判断是否为-99，如果不是，把节点加进链表
		if (p->num != -99)
		{
			p->next = NULL;
			p->prev = NULL;
			if (head == NULL)
			{
				head = p;
				tail = p;
			}
			else
			{
				tail->next = p;
				p->prev = tail;
				tail = p;
			}
			p->next = NULL;
		}
		else
		{
			free(p);
			break;
		}
	}
	return head;//最后返回头结点
}

//打印单向链表
void one_print(oneway* head)
{
	oneway* p = head;
	while (p)
	{
		printf("%d ", p->num);
		p = p->next;
	}
	printf("\n");
}

//打印双向链表
void two_print(twoway* head)
{
	twoway* p = head;
	while (p)
	{
		printf("%d ", p->num);
		p = p->next;
	}
	printf("\n");
}




