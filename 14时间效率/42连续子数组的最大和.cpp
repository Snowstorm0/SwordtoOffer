
// 面试题42：连续子数组的最大和
// 题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整
// 数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> arr) 
{
    int len = arr.size();
    int cur = arr[0];
    int max = arr[0];
    if (len == 0)
        return 0;
    for (int i = 1; i < len; i++)
    {
        cur = cur + arr[i];
        if (cur < arr[i])
            cur = arr[i];
        if (cur > max)
            max = cur;
    }
    return max;
}


// ====================测试代码====================
int main()
{
    vector<int> num = { 1,-2,3,10,-4,7,2,-5 };
    int result;
    result = FindGreatestSumOfSubArray(num);

    cout << result << endl;
    system("pause");

}





