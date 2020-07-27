
// 面试题67：把字符串转换成整数
// 题目：请你写一个函数StrToInt，实现把字符串转换成整数这个功能。当然，不
// 能使用atoi或者其他类似的库函数。

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

int StrToInt(string str) 
{
    int invalid = 0, sign1 = 0;
    int sign = 1;
    int len = str.size();
    long long res;
    if (len <= 0)
    {
        invalid = 1;
        return 0;
    }
    if (str[0] == '+') // 若有正号
    {
        if (len == 1)   //只有正号
        {
            invalid = 1;
            return 0;
        }
        sign1++;
    }
    if (str[0] == '-') // 若有负号
    {
        if (len == 1)
        {
            invalid = 1;
            return 0;
        }
        sign = -1;
        sign1++;
    }
    for (int i = sign1; i < len; i++)
    {
        if (str[i] > '9' || str[i] < '0')
        {
            invalid = 1;
            return 0;
        }
        if (i == sign1)
            res = str[i] - '0';
        else
            res = res * 10 + str[i] - '0';
    }
    
    res *= sign;
    if ((res > 0 && res > 0x7FFFFFFF) || (res<0 && res < (signed int)0x80000000)) // 溢出
    {
        invalid = 1;
        return 0;
    }

    return res;

}



// ====================测试代码====================
int main()
{
    string str = "-123";
    int res = StrToInt(str);

    cout << res << endl;
    system("pause");
}










