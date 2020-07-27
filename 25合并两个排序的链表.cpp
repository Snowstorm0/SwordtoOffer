
// 面试题25：合并两个排序的链表
// 题目：输入两个单调递增的链表，
// 输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include<iostream>
#include <stack> 
#include<cstdlib>
#include <string>
using namespace std;





struct ListNode 
{
    int val;
    struct ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

//打印输出链表
void print(ListNode *head)
{
    ListNode *p = head;
    while (p != NULL)
    {
        cout << p->val;
        p = p->next;
    }
}
// 创建链表
ListNode* CreateListNode(ListNode* pHead)
{
    ListNode* p = pHead;                // 声明移动指针，最开始指向头结点               

     // 01233456
    ListNode* pNewNode1 = new ListNode(0);
    pNewNode1->val = 1;
    pNewNode1->next = NULL;
    p->next = pNewNode1;
    p = p->next;

    ListNode* pNewNode2 = new ListNode(0);
    pNewNode2->val = 2;
    pNewNode2->next = NULL;
    p->next = pNewNode2;
    p = p->next;

    ListNode* pNewNode3 = new ListNode(0);
    pNewNode3->val = 3;
    pNewNode3->next = NULL;
    p->next = pNewNode3;
    p = p->next;

    ListNode* pNewNode4 = new ListNode(0);
    pNewNode4->val = 4;
    pNewNode4->next = NULL;
    p->next = pNewNode4;
    p = p->next;

    ListNode* pNewNode5 = new ListNode(0);
    pNewNode5->val = 5;
    pNewNode5->next = NULL;
    p->next = pNewNode5;
    p = p->next;

    ListNode* pNewNode6 = new ListNode(0);
    pNewNode6->val = 6;
    pNewNode6->next = NULL;
    p->next = pNewNode6;
    p = p->next;

    ListNode* pNewNode7 = new ListNode(0);
    pNewNode7->val = 7;
    pNewNode7->next = NULL;
    p->next = pNewNode7;
    p = p->next;

    return pHead;
}



ListNode* Merge(ListNode* head1, ListNode* head2)
{
    if (head1 == nullptr && head2 == nullptr)
        return nullptr;
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    ListNode* result = nullptr;
    if (head1->val <= head2->val)
    {
        result = head1;
        result->next = Merge(head1->next, head2);
    }
    else if (head1->val > head2->val)
    {
        result = head2;
        result->next = Merge(head1, head2->next);
    }
    return result;
}

// ====================测试代码====================
int main()
{
    ListNode* head = new ListNode(0);
    ListNode* list1 = CreateListNode(head);
    ListNode* list2 = CreateListNode(head);
    ListNode* result = Merge(list1, list2);
    print(result);
    system("pause");
}





