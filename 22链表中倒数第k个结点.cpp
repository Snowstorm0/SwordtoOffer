
// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
// 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
// 值为4的结点。


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

    // 0123456
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

    return pHead;
}



ListNode* FindKthToTail(ListNode* list, unsigned int k) 
{
    if (list == nullptr || k == 0)
        return nullptr;
    ListNode* p1 = list;
    ListNode* p2 = list;
    for (int i = 0; i < k; i++)
    {
        if (p1 != nullptr)
            p1 = p1->next;
        else
            return nullptr;    // k超出链表范围
    }
    while (p1 != nullptr)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}

// ====================测试代码====================
int main()
{
    ListNode* list = new ListNode(0);
    list = CreateListNode(list);
    ListNode* result = FindKthToTail(list, 3);
    print(result);
    system("pause");
}





