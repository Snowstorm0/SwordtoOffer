
// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。

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

int cutRope(int num) 
{
    if (num <= 1)
        return 0;
    if (num == 2)
        return 1;
    if (num == 3)
        return 2;
    if (num == 4)
        return 4;

    int res;
    int num3 = num / 3;
    int rem = num % 3;

    if (rem == 0)       // 余数为0
        res = pow(3, num3);
    else if (rem == 1)      // 余数为1
        res = pow(3, num - 1) * 4;
    else              // 余数为2
        res = pow(3, num3) * 2;
     
    return res;
}



// ====================测试代码====================
int main()
{

    int res = cutRope(5);

    printf("%d", res);
    //cout << res << endl;
    system("pause");

}










