
// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include<iostream>
#include <stack> 
#include<cstdlib>
#include <string>
using namespace std;

// 次方可以参考斐波那契数列
double Power(double base, int exp)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base;
    if (exp == -1)
        return 1 / base;

    int exp1 = abs(exp);
    double res = 1.0;
    double res1 = base;

    while (exp1)
    {
        if (exp1 & 1 == 1)      // 与运算代替取余，判断奇偶
            res = res * res1;  // 若奇数，多乘一个base；并在exp1=1时将res1乘上去

        res1 = res1 * res1;

        exp1 >>= 1;             // 右移一位，代替除以2
    }

    if (exp > 0)
        return res;
    else if (exp < 0)
        return 1 / res;
}


// ====================测试代码====================
int main()
{
    double base = 2;
    int exponent = 8;
    int result = Power(base, exponent);

    cout << result;
    system("pause");
}





