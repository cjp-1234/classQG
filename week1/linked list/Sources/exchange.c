#define _CRT_SECURE_NO_WARNINGS
#include"linked.h"
//单链表奇偶调换
void exchange(oneway**head)//传入单向链表头指针
{
	if (*head == NULL || (*head)->next == NULL) return;

	oneway* p = *head;
	int a, b;//分别记录当前节点和下一个节点是否为偶数，为偶数为0，奇数为1,如果a,b不一样就调换
	oneway x;
	x.next = *head;
	oneway* pev=&x;
	//加入一个节点，来记录遍历中当前结点的上一个，方便交换
	while (p->next!=NULL)//遍历
	{
		a = p->num % 2;
		b = p->next->num % 2;
		if (a != b)//如果前后奇偶不相等，就调换
		{
			oneway* temp = p->next;//记录p的下一个节点
			if (p == *head)
			{
				*head = temp;
				pev->next=temp;
				p->next = temp->next;   //调整p的next
				temp->next = p;      //调整p下一个节点的next

			}
			else
			{
				pev->next = temp;
				p->next = temp->next;   //调整p的next
				temp->next = p;      //调整p下一个节点的next

			}
		}
		else p = p->next;
		pev= pev->next;
	}
	return;
}
