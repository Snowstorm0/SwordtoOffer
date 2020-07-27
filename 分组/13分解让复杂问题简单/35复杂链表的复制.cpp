
// 面试题35：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
// 结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。



#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string>
using namespace std;


struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) { }
};


void print(RandomListNode *head)   //打印输出链表
{
    RandomListNode *p = head;
    while (p != NULL)
    {
        cout << p->label;
        p = p->next;
    }
}


RandomListNode* CreateListNode(RandomListNode* pHead)  // 创建链表
{
    RandomListNode* p = pHead;                // 声明移动指针，最开始指向头结点               

    for (int i = 1; i < 10; ++i)
    {
        RandomListNode* pNewNode;           // 声明链表 pNewNode 来保存数据，pNewNode 就是一个链表的节点
        pNewNode = new RandomListNode(0);   // 初始化变量 pNewNode

        pNewNode->label = i;            // 将新节点的值赋值为 i
        pNewNode->next = NULL;

        p->next = pNewNode;            // p的下一节点指向这个新的节点，将此节点与头节点连接
        p = p->next;    // p节点指向这个新的节点，向后移动指针，以便下一次链接；p一直指向链表最后的一个节点 
    }
    return pHead;
}




//[1]复制结点，插入到原结点后方
void CloneNext(RandomListNode* head)
{
    if (head == nullptr)
        return;
    RandomListNode* p1 = head;
    RandomListNode* p2;

    while (p1 != nullptr)
    {
        p2 = new RandomListNode(p1->label);
        p2->next = p1->next;
        p1->next = p2;
        p1 = p1->next->next;
    }

    return;

}

//[2]还原新结点的random指针
void CloneRandom(RandomListNode* head)
{
    if (head == nullptr)
        return;
    RandomListNode* p = head;
    while (p != nullptr)
    {
        if(p->random != nullptr)
            p->next->random = p->random->next;
        p = p->next->next;
    }
    return;
}

//[3]拆分
RandomListNode* Break(RandomListNode* head)
{
    RandomListNode* res = head->next;
    RandomListNode* p1 = head;
    RandomListNode* p2 = res;

    while (p1 != nullptr)
    {
        p1->next = p1->next->next;
        if (p1->next == nullptr)
            break;
        p2->next = p1->next->next;

        p1 = p1->next;
        p2 = p2->next;
    }

    return res;
}

RandomListNode* Clone(RandomListNode* head)
{
    if (head == nullptr)
        return head;

    CloneNext(head);
    CloneRandom(head);
    RandomListNode* res = Break(head);

    return res;

}








// ====================测试代码====================
int main()
{
    RandomListNode* head;
    head = new RandomListNode(0);
    RandomListNode* listnode = CreateListNode(head);

    //print(listnode);
    //system("pause");

    //CloneNext(listnode);
    //CloneRandom(listnode);
    //print(listnode);
    //system("pause");


    RandomListNode* restlt = Clone(listnode);

    print(restlt);
    system("pause");

}





