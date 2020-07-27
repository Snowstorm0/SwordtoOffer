
// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。


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



ListNode* ReverseList(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* nex = nullptr;

    while (cur != nullptr)
    {
        nex = cur->next;
        cur->next = pre;
        pre = cur;

        if (nex == nullptr) // cur要作为头结点返回，避免给他赋值为空
            break;
        cur = nex;
    }
    return cur;
}

// ====================测试代码====================
int main()
{
    ListNode* list = new ListNode(0);
    list = CreateListNode(list);
    ListNode* result = ReverseList(list);
    print(result);
    system("pause");
}





