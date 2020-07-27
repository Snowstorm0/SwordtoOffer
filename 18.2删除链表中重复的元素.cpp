
// 面试题18（二）：删除链表中重复的结点
// 题目：在一个排序的链表中，如何删除重复的结点？例如，在图3.4（a）中重复
// 结点被删除之后，链表如图3.4（b）所示。


#include <stdio.h>
#include <stdlib.h>
//#include <cstdio>
#include <vector>
#include<iostream>
#include <stack> 
#include<cstdlib>
using namespace std;

struct ListNode                 //定义一个结构体  ListNode的结构
{
      int val;                  //当前结点的值用val表示
      struct ListNode *next;  //指向下一个结点的指针用next表示
      ListNode(int x) : val(x), next(NULL) { } //初始化当前结点值为x,指针为空
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
    pNewNode2->val = 1;
    pNewNode2->next = NULL;
    p->next = pNewNode2;
    p = p->next;
    
    ListNode* pNewNode3 = new ListNode(0);
    pNewNode3->val = 1;
    pNewNode3->next = NULL;
    p->next = pNewNode3;
    p = p->next; 
    
    ListNode* pNewNode4 = new ListNode(0);
    pNewNode4->val = 1;
    pNewNode4->next = NULL;
    p->next = pNewNode4;
    p = p->next;
   
    ListNode* pNewNode5 = new ListNode(0);
    pNewNode5->val = 1;
    pNewNode5->next = NULL;
    p->next = pNewNode5;
    p = p->next;
    
    ListNode* pNewNode6 = new ListNode(0);
    pNewNode6->val = 1;
    pNewNode6->next = NULL;
    p->next = pNewNode6;
    p = p->next;
    
    ListNode* pNewNode7 = new ListNode(0);
    pNewNode7->val = 2;
    pNewNode7->next = NULL;
    p->next = pNewNode7;
    p = p->next;

    return pHead;
}



ListNode* deleteDuplication(ListNode* pHead) 
{
    if (pHead == nullptr || pHead->next == nullptr)
        return pHead;

    ListNode* pHead1 = new ListNode(0);
    pHead1->next = pHead;      // 向后错开一位，应对头结点就重复的情况
    ListNode* pfast = pHead1;
    ListNode* plast = pHead1->next;

    while (plast != nullptr)         // 检查是否出现重复（可能不止一次）
    {
        if (plast->next != nullptr && plast->val == plast->next->val)
        {
            while(plast->next != nullptr && plast->val == plast->next->val)
                plast = plast->next;
            pfast->next = plast->next;
            plast = plast->next;
        }
        else
        {
            pfast = pfast->next;
            plast = plast->next;
        }
    }
    return pHead1->next;
}


// ====================测试代码====================
int main()
{

    ListNode* head;                     // 声明头节点
    head = new ListNode(1);             // 头节点需要赋值才能调用
    ListNode* listnode = CreateListNode(head); // 引用头结点创建链表

    //print(listnode);
    //system("pause");

    ListNode* restlt = deleteDuplication(listnode);
    if (restlt == nullptr)
        cout << "null" << endl;
    else    
        print(restlt);
        system("pause");

    return 0;
}








