
// 面试题10（二）：青蛙跳台阶问题
// 题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include<iostream>
#include <stack> 
#include<cstdlib>
#include <string>
using namespace std;


int jumpFloor(int number)  // 还是斐波那契数列问题
{
    int n = number + 1;
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
    int result = jumpFloor(5);

    cout << result;
    system("pause");
}






