
// 面试题53（一）：数字在排序数组中出现的次数
// 题目：统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3,
// 3, 3, 4, 5}和数字3，由于3在这个数组中出现了4次，因此输出4。

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


int GetNumberOfK(vector<int> data, int k) 
{
    int len = data.size();
    if (len <= 0)
        return 0;
    int sta = 0, end = len - 1, mid;
    mid = (sta + end) >> 1;  // 右移除以2
    while (sta < end)
    {
        if (data[mid] < k)
            sta = mid + 1;
        else if (data[mid] > k)
            end = mid - 1;
        if (data[mid] == k)
            break;
        mid = (sta + end) >> 1;  // 右移除以2

    }
    int res = 0, i = mid, j = mid - 1;
    while (i < len)
    {
        if (data[i] == k)
        {
            res++;
            i++;
        }
        else
            break;
    }

    while (j >= 0)
    {
        if (data[j] == k)
        {
            res++;
            j--;
        }
        else
            break;
    }
    return res;
}


// ====================测试代码====================
int main()
{

    vector<int>data = { 0,1,1,2 };
    int result = GetNumberOfK(data, 2);

    cout << result << endl;
    system("pause");

}














