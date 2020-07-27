
// 面试题64：求1+2+…+n
// 题目：求1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case
// 等关键字及条件判断语句（A?B:C）。

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

typedef int (*fun)(int);  // 定义函数指针

static int Sum0(int n)
{
    return 0;
}

static int Sum_Solution(int n)
{
    // 定义指针函数f指向两个函数，[]内为0代表Sum0，为1代表Sum_Solution
    static fun f[2] = { Sum0, Sum_Solution };

    // !!n：两次取反运算，即非零数变成1，零还是0
    return n + f[!!n](n - 1);
}



// ====================测试代码====================
int main()
{
    int res = Sum_Solution(5);

    cout << res << endl;
    system("pause");
}













