
// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include<iostream>
#include <stack> 
#include<cstdlib>
#include <string>
using namespace std;

// 把一个整数减去1，再和原整数做与运算，会把该整数最右边的一个1变成0
int  NumberOf1(int n) 
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n = n & (n - 1);  // 每做一次与运算减少一次1
    }
    return count;
}

// ====================测试代码====================
int main()
{
    int result = NumberOf1(4);

    cout << result;
    system("pause");
}






