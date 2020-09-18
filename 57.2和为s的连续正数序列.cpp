
// 面试题57（二）：和为s的连续正数序列
// 题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
// 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、
// 4～6和7～8。

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


vector<vector<int> > FindContinuousSequence(int sum) 
{
    vector<vector<int>> res;
    if (sum <= 0)
        return res;

    int left = 1, right = 2, sum1 = 3;
    while (left < right)
    {
        if (sum1 < sum)
        {
            right++;
            sum1 = sum1 + right;
        }
        if (sum1 > sum)
        {
            sum1 = sum1 - left;
            left++;
        }
        if (sum1 == sum)   // 相等
        {
            vector<int> tmp;
            for (int i = left; i <= right; i++)
            {
                tmp.push_back(i);
            }
            res.push_back(tmp);

            sum1 = sum1 - left;  // 左边的数右移一位
            left++;
        }
    }
    return res;

}




// ====================测试代码====================
int main()
{
    vector<vector<int> > res;
    res = FindContinuousSequence(9);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << endl;
        }
    }
    system("pause");

}














