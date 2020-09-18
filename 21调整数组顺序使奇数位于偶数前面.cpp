
// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include<iostream>
#include <stack> 
#include<cstdlib>
#include <string>
using namespace std;

void reOrderArray(vector<int> &arr)
{
    int len = arr.size();
    if (len == 0)
        return;

    vector<int> res;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] & 1)           // 奇数
            res.push_back(arr[i]);
    }
    for (int i = 0; i < len; i++)
    {
        if (!(arr[i] & 1))         // 偶数
            res.push_back(arr[i]);
    }
    arr = res;
}



// ====================测试代码====================
int main()
{
    vector<int> array = { 1,2,3,4,5 };
    reOrderArray(array);
    int len = array.size();
    for (int i = 0; i < len; i++)
    {
        cout << array[i];
    }
    system("pause");
}





