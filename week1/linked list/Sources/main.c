#define _CRT_SECURE_NO_WARNINGS
#include"linked.h"
int main()
{
	char x; //x 为执行的操作序号
	while (1)
	{
		system("cls");
		//打印菜单，
		printf("---1.必做任务(创建链表)---\n");
		printf("---2.单链表奇偶调换-------\n");
		printf("---3.找单链表中点---------\n");
		printf("---4.退出-----------------\n");
		printf("(判断成环有写但没运用）\n");
		printf("请输入：\n");
		x = _getch();
		switch (x)
		{
		case '1': must(); break;
		case '2':
		{
			printf("创建单向链表：\n");
			oneway* q = createone();
			exchange(&q);
			one_print(q);
			system("pause");
			break;
		}
		case '3':
		{
			printf("创建单向链表：\n");
			oneway* p = createone();
			oneway* mid = midpoint(p);
			if (mid != NULL)printf("中间的数为：%d\n", mid->num);
			else printf("链表少于两个节点\n");
			system("pause");
			break;
		}
		case '4':exit(1);
		default:printf("无效的选择，请重新输入\n");
		}
	}
	return 0;
}