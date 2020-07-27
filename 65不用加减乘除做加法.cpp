
// 面试题65：不用加减乘除做加法
// 题目：写一个函数，求两个整数之和，要求在函数体内不得使用＋、－、×、÷
// 四则运算符号。

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string>
//#include <algorithm>
using namespace std;

int Add(int num1, int num2)
{
    int sum, carry;
    do 
    {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;

        num1 = sum;
        num2 = carry;
    } while (carry != 0);

    return sum;
}



// ====================测试代码====================
int main()
{
    int res = Add(5,17);

    cout << res << endl;
    system("pause");
}













