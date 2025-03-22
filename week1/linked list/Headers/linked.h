#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
//单向链表
typedef struct oneway
{
	int num;
	struct oneway* next;
}oneway;
//双向链表
typedef struct twoway
{
	struct twoway* prev;
	int num;
	struct twoway* next;
}twoway;
oneway* createone();
twoway* createtwo();
void one_print(oneway* head);
void two_print(twoway* head);

void must();
void exchange(oneway** head);
int ring(oneway* head);
oneway* midpoint(oneway* head);