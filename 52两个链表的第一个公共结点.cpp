
// 面试题52：两个链表的第一个公共结点
// 题目：输入两个链表，找出它们的第一个公共结点。


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string>
//#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

void print(ListNode *head)   //打印输出链表
{
    ListNode *p = head;
    while (p != NULL)
    {
        cout << p->val;
        p = p->next;
    }
}

// 创建链表1   012
ListNode* CreateListNode1(ListNode* pHead)
{
    ListNode* p = pHead;                // 声明移动指针，最开始指向头结点               
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

    return pHead;
}

// 创建链表2   34
ListNode* CreateListNode2(ListNode* pHead)
{
    ListNode* p = pHead;                // 声明移动指针，最开始指向头结点               

    ListNode* pNewNode2 = new ListNode(0);
    pNewNode2->val = 4;
    pNewNode2->next = NULL;
    p->next = pNewNode2;
    p = p->next;

    return pHead;
}

// 创建链表3   56
ListNode* CreateListNode3(ListNode* pHead)
{
    ListNode* p = pHead;                // 声明移动指针，最开始指向头结点               

    ListNode* pNewNode2 = new ListNode(0);
    pNewNode2->val = 6;
    pNewNode2->next = NULL;
    p->next = pNewNode2;
    p = p->next;

    return pHead;
}


ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) 
{
    ListNode* p1 = pHead1;
    ListNode* p2 = pHead2;
    int len1 = 0, len2 = 0, len3;
    while (p1 != nullptr)
    {
        len1++;
        p1 = p1->next;
    }
    while (p2 != nullptr)
    {
        len2++;
        p2 = p2->next;
    }
    p1 = pHead1;    // 回到开头
    p2 = pHead2;
    if (len1 > len2)   // 若p1更长
    {
        len3 = len1 - len2;
        for (int i = 0; i < len3; i++)
            p1 = p1->next;
        for (int i = 0; i < len2; i++)
        {
            if (p1 == p2)
                break;
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;

    }
    else                 // 若p2更长
    {
        len3 = len2 - len1;
        for (int i = 0; i < len3; i++)
            p2 = p2->next;
        for (int i = 0; i < len1; i++)
        {
            if (p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
}


// ====================测试代码====================
int main()
{
    ListNode* head1;
    ListNode* head2;
    ListNode* head3;                     // 声明头节点
    head1 = new ListNode(0);             // 头节点需要赋值才能调用
    head2 = new ListNode(3);             // 头节点需要赋值才能调用
    head3 = new ListNode(5);             // 头节点需要赋值才能调用
    ListNode* p1 = CreateListNode1(head1); // 引用头结点创建链表
    ListNode* p2 = CreateListNode2(head2);
    ListNode* p3 = CreateListNode3(head3);
    p1->next->next->next = p3;
    p2->next->next = p3;

    ListNode* result = FindFirstCommonNode(p1, p2);

    print(result);
    system("pause");

}














