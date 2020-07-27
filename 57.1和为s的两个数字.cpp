
// 面试题57（一）：和为s的两个数字
// 题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们
// 的和正好是s。如果有多对数字的和等于s，输出两个数的乘积最小的。

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

// 和相同，距离最远，乘积最小
vector<int> FindNumbersWithSum(vector<int> arr, int sum) 
{
    int len = arr.size();
    vector<int> res;
    if (len < 2)
        return res;

    int i = 0, j = len - 1, sum1;
    while (i < j)
    {
        sum1 = arr[i] + arr[j];
        if (sum1 < sum)
            i++;
        if (sum1 > sum)
            j--;
        if (sum1 == sum)
        {
            res.push_back(arr[i]);
            res.push_back(arr[j]);
            break;
        }
    }
    return res;
}




// ====================测试代码====================
int main()
{
    vector<int> arr = {1,2,4,7,11,15};
    vector<int> res = FindNumbersWithSum(arr, 15);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    system("pause");

}














