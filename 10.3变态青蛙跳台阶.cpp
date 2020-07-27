
// 面试题10（三）：变态青蛙跳台阶问题
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法。


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include<iostream>
#include <stack> 
#include<cstdlib>
#include <string>
using namespace std;


int jumpFloorII(int n)  // 数学归纳法求得f(n)=2^(n-1)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
    {
        long num, num1 = 1;
        for (int i = 1; i < n; i++)   // 保存中间变量，节约时间
        {
            num = num1 * 2;
            num1 = num;
        }
        return num;
    }
}

// ====================测试代码====================
int main()
{
    int result = jumpFloorII(5);

    cout << result;
    system("pause");
}






