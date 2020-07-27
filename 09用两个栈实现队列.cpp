
// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include<iostream>
#include <stack> 
#include<cstdlib>
#include <string>
using namespace std;


stack<int> stack1;
stack<int> stack2;

void push(int node) 
{
    stack1.push(node);
}

int pop() 
{
    if(stack2.empty())
        while (!stack1.empty())   // stack1 数据存入 stack2
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    int res = stack2.top();
    stack2.pop();

    return res;
}

// ====================测试代码====================
int main()
{

    push(0);
    push(1);
    push(2);
    push(3);
    int result = pop();

    cout << result;
    system("pause");


}




