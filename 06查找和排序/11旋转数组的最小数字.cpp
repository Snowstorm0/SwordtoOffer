
// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include<iostream>
#include <stack> 
#include<cstdlib>
#include <string>
using namespace std;


int minNumberInRotateArray(vector<int> vec) 
{
    int len = vec.size();
    int index1 = 0;
    int index2 = len - 1;
    int indexmid = (index1 + index2)/2;

    if (len == 0)
        return 0;

    if ((len == 1) || (vec[index1] < vec[index2]))  // 若长度为1 或 已经排好序
        return vec[0];
    if (vec[index1] == vec[index2] == vec[indexmid]) // 若前中后都相等
    {
        int min = vec[0];
        for (int i = 0; i < len; i++)    // 只能遍历寻找
        {
            if (min > vec[i])
                min = vec[i];
        }
        return min;
    }

    while (index1+1 != index2)
    {
        if (vec[index1] <= vec[indexmid])
        {
            index1 = indexmid;
            indexmid = (index1 + index2) / 2;
        }
        if (vec[index2] >= vec[indexmid])
        {
            index2 = indexmid;
            indexmid = (index1 + index2) / 2;
        }
    }
    return vec[index2];

}

// ====================测试代码====================
int main()
{
    vector<int> rotateArray = { 6501,6828,6963,7036,7422,7674,8146,8468,8704,8717,9170,9359,9719,9895,9896,9913,9962,154,293,334,492,1323,1479,1539,1727,1870,1943,2383,2392,2996,3282,3812,3903,4465,4605,4665,4772,4828,5142,5437,5448,5668,5706,5725,6300,6335 };
    int result = minNumberInRotateArray(rotateArray);

    cout << result;
    system("pause");
}






