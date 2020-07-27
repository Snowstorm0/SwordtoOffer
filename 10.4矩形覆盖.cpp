
// 面试题10（四）：矩形覆盖
// 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
// 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？。


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include<iostream>
#include <stack> 
#include<cstdlib>
#include <string>
using namespace std;


int rectCover(int n)  // 还是斐波那契数列问题
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    else
    {
        long num, num1 = 1, num2 = 1;
        for (int i = 1; i < n; i++)   // 保存中间变量，节约时间
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
    int result = rectCover(4);

    cout << result;
    system("pause");
}






