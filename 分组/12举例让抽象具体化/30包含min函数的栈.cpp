
// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
// 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include<iostream>
#include <stack> 
#include<cstdlib>
#include <string>
using namespace std;

stack<int> sta;
stack<int> smin;
void push(int value) 
{
    sta.push(value);
    if (smin.empty())
        smin.push(value);
    if(smin.top() > value)        // 当前最小元素压入最小栈
        smin.push(value);
}
void pop() 
{
    if (smin.top() == sta.top())
        smin.pop();
    sta.pop();
}
int top() 
{
    return sta.top();
}
int min() 
{
    return smin.top();
}


// ====================测试代码====================
int main()
{
    push(0);
    push(1);
    int result = min();
    cout << result << endl;
    system("pause");

}





