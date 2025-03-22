#define _CRT_SECURE_NO_WARNINGS
#include"linked.h"
oneway* midpoint(oneway* head)
{
	//判断是否只有一个或没有节点
	if (head == NULL || head->next == NULL) return NULL;
	oneway* slow = head;
	oneway* fast = head;//快慢指针，当块指针走到底时，慢指针就是中点
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;//返回中间节点
}