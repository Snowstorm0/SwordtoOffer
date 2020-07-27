
// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

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


ListNode* CreateListNode(ListNode* pHead)  // 创建链表
{
    ListNode* p = pHead;                // 声明移动指针，最开始指向头结点               

    for (int i = 1; i < 10; ++i) 
    {
        ListNode* pNewNode;           // 声明链表 pNewNode 来保存数据，pNewNode 就是一个链表的节点
        pNewNode = new ListNode(0);   // 初始化变量 pNewNode

        pNewNode->val = i;            // 将新节点的值赋值为 i
        pNewNode->next = NULL;

        p->next = pNewNode;            // p的下一节点指向这个新的节点，将此节点与头节点连接
        p = p->next;    // p节点指向这个新的节点，向后移动指针，以便下一次链接；p一直指向链表最后的一个节点 
    }
    return pHead;
}



vector<int> printListFromTailToHead(ListNode* head) 
{
    vector<int> result;
    std::stack<int> stac; // 定义 int 类型的栈
    ListNode* p = head;    // 声明移动指针 pNode，最开始指向头结点  
    while (p != nullptr)
    {
        stac.push(p->val); // p为 ListNode*；p->val 为 int，对p解引用
        p = p->next;
    }

    int len = stac.size(), i;
    for(i=0; i<len; i++)
    {
        result.push_back(stac.top());   // stac.top():返回栈顶元素, 但不删除该元素
        stac.pop();                     // 弹出栈顶元素, 但不返回其值
    }
    return result;

}


// ====================测试代码====================
int main()
{

    ListNode* head;                     // 声明头节点
    head = new ListNode(0);             // 头节点需要赋值才能调用
    ListNode* listnode = CreateListNode(head); // 引用头结点创建链表

    //cout << listnode->val;  // 输出第一个节点的值
    print(listnode);
    system("pause");

    vector<int> restlt = printListFromTailToHead(listnode);

    // restlt 是vector ,restlt.size() 在容器说明中被定义为: unsigned int 类型, 
    // i也要定义 unsigned int 类型，否则会出现: 有符号/无符号不匹配警告
    for (unsigned int i = 0; i < restlt.size(); i++)
    {
        cout << restlt[i] << endl;
        system("pause");
    }
    //printf("result: %d\n", restlt);
    //system("pause");
    return 0;
}





