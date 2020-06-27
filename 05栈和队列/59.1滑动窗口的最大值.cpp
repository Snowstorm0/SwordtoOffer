
// 面试题59（一）：滑动窗口的最大值
// 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
// 如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
// 滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include<iostream>
#include <stack> 
#include<cstdlib>
#include <string>
using namespace std;

// vector<int>& num：对 vector<int> 这个整体的引用，参考：int &a = b；
// vector里面的元素不存在引用的情况
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> maxv;
    if (num.empty() || size <= 0)
        return maxv;

    int len = num.size();
    int max = num[0];
    for (int i = 0; i < len-(size-1); i++)
    {
        max = num[i];
        for (int j = i; j < i+size; j++)  // 窗口内最大值
        {
            if (max < num[j])
                max = num[j];
        }
        maxv.push_back(max);
    }
    return maxv;
}

// ====================测试代码====================
int main()
{
    const vector<int> num = { 2,3,4,2,6,2,5,1 };
    unsigned int size = 3;
    vector<int> result = maxInWindows(num, size);

    int len = result.size();
    for (int i = 0; i < len; i++)
    {
        cout << result[i];
    }
    system("pause");
}




