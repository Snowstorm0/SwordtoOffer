
// 面试题43：从1到n整数中1出现的次数
// 题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。例如
// 输入12，从1到12这些整数中包含1 的数字有1，10，11和12，1一共出现了5次。


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string>
using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
    int num = 0;
    for (int i = 0; i <= n; i++)
    {
        int num1 = 0;
        int tmp = i;
        while (tmp != 0)
        {
            if (tmp % 10 == 1)
                num1++;
            tmp = tmp / 10;
        }
        num = num + num1;
    }
    return num;
}


// ====================测试代码====================
int main()
{
    int result;
    result = NumberOf1Between1AndN_Solution(1);

    cout << result << endl;
    system("pause");

}





