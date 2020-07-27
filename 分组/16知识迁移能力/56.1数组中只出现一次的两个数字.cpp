
// 面试题56（一）：数组中只出现一次的两个数字
// 题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
// 找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

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


void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) 
{
    int len = data.size();
    if (len <= 1)
        return;
    int num = 0;   // 任何数与0异或等于本身
    for (int i = 0; i < len; i++)  
    {
        num = num ^ data[i];      // 异或操作，相同数异或为零
    }
    int flag = 1;
    while (!(num & flag))  // 使flag表示num中第一个为1的位数
    {
        flag = flag << 1;
    }
    *num1 = *num2 = 0;  // a ^ 0 = a
    for (int j = 0; j < len; j++)
    {
        if (data[j] & flag)
            *num1 = *num1 ^ data[j];
        else
            *num2 = *num2 ^ data[j];
    }

}




// ====================测试代码====================
int main()
{
    vector<int> data = { 1,2,3,3,4,4,5,5 };
    int res1, res2;
    FindNumsAppearOnce(data, &res1, &res2);
    cout << res1 << endl;
    system("pause");

}














