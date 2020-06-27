
// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。


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

    //// 0123456789
    //for (int i = 1; i < 10; ++i) 
    //{
    //    ListNode* pNewNode;           // 声明链表 pNewNode 来保存数据，pNewNode 就是一个链表的节点
    //    pNewNode = new ListNode(0);   // 初始化变量 pNewNode

    //    pNewNode->val = i;            // 将新节点的值赋值为 i
    //    pNewNode->next = NULL;

    //    p->next = pNewNode;            // p的下一节点指向这个新的节点，将此节点与头节点连接
    //    p = p->next;    // p节点指向这个新的节点，向后移动指针，以便下一次链接；p一直指向链表最后的一个节点 
    //}
    //return pHead;

    // 012345634563456……
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
    p->next = pNewNode3;
    p = p->next;

    return pHead;
}



ListNode* EntryNodeOfLoop(ListNode* head)
{
    if (head == nullptr)
        return nullptr;

    ListNode* pfast = head;
    ListNode* pslow = head;
    int nodecount = 1, i;

    pfast = pfast->next;
    if (pfast != nullptr)
        pfast = pfast->next;
    pslow = pslow->next;
    while (pfast != nullptr && pslow != nullptr && pfast != pslow)
    {
        pfast = pfast->next;
        if (pfast != nullptr)
            pfast = pfast->next;
        pslow = pslow->next;
    }

    if (pfast != pslow || pfast == nullptr) // 无环
        return nullptr;

    ListNode* pfast1 = pfast;
    ListNode* pslow1 = pfast;
    if (pfast1 != nullptr)
        pfast1 = pfast1->next;
    while (pfast1 != pslow1)  // 计算环节点数
    {
        if (pfast1 != nullptr)
            pfast1 = pfast1->next;
        nodecount++;
    }

    ListNode* pfast2 = head;  // 找节点位置
    ListNode* pslow2 = head;
    for (i = 0; i < nodecount; i++)
    {
        pfast2 = pfast2->next;
    }
    while (pfast2 != pslow2)
    {
        pfast2 = pfast2->next;
        pslow2 = pslow2->next;
    }
    return pfast2;
}

// ====================测试代码====================
int main()
{

    ListNode* head;                     // 声明头节点
    head = new ListNode(0);             // 头节点需要赋值才能调用
    ListNode* listnode = CreateListNode(head); // 引用头结点创建链表

    //print(listnode);
    //system("pause");

    ListNode* restlt = EntryNodeOfLoop(listnode);
    if (restlt == nullptr)
        cout << "null" << endl;
    else    
        print(restlt);
        system("pause");

    return 0;
}






