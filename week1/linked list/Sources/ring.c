#define _CRT_SECURE_NO_WARNINGS
#include"linked.h"
int ring(oneway* head) 
{
    //判断是否只有一个或没有节点
    if (head == NULL || head->next == NULL) return 0;
    oneway* slow = head;
    oneway* fast = head->next;//快慢指针，如果是环，最后fast会追是slow
    while (slow != fast)
    {
        //如果走到头了，就不是环
        if (fast == NULL || fast->next == NULL) 
        {
            return 0;
        }
        slow = slow->next;
        fast = fast->next->next;
        //fast一次走两步，slow一次走一步
    }
    return 1;
}