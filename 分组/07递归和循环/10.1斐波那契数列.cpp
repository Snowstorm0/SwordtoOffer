
// 面试题10（一）：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include<iostream>
#include <stack> 
#include<cstdlib>
#include <string>
using namespace std;


int Fibonacci(int n) 
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    else
    {
        long num, num1 = 1, num2 = 1;
        for (int i = 2; i < n; i++)   // 保存中间变量，节约时间
        {
            num = num1 + num2;
            num1 = num2;
            num2 = num;
        }
        return num;
    }
}

// ====================测试代码====================
int main()
{
    int result = Fibonacci(5);

    cout << result;
    system("pause");
}






