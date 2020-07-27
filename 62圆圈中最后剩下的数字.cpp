
// 面试题62：圆圈中最后剩下的数字
// 题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
// 删除第m个数字。求出这个圆圈里剩下的最后一个数字。

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

// f(n, m) = 0                     n = 1
// f(n, m) = [f(n-1, m) + m] % n   n > 1
// f表示最后剩下的数字
int LastRemaining_Solution(int n, int m)
{
    if (n < 1 || m < 1)
        return -1;

    int f = 0;
    for (int i = 2; i <= n; i++)  // 去掉n-1个数，故n-1次循环
        f = (f + m) % i;

    return f;
}



// ====================测试代码====================
int main()
{
    bool res = LastRemaining_Solution(10, 2);

    cout << res << endl;
    system("pause");
}













