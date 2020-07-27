
// 面试题51：数组中的逆序对
// 题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组
// 成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

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



// &引用，可以在递归时修改数组
long long InverseCount(vector<int>& data, vector<int>& copy, int sta, int end)
{
    if (sta == end)
    {
        copy[sta] = data[sta];
        return 0;
    }

    long long count = 0;
    int length = (end - sta) >> 1;    // 半段的长度

    long long left_num;     // 左边部分的count
    long long right_num;    // 右边部分的count
    left_num = InverseCount(copy, data, sta, sta + length); // data 与 copy 交换
    right_num = InverseCount(copy, data, sta + length + 1, end); 

    int left = sta + length;
    int right = end;           // 从两段的最后开始

    int copy_flag = end;      // 从后往前复制

    while (left >= sta && right >= sta + length + 1)
    {
        if (data[left] > data[right])
        {
            count += right - (sta + length);
            copy[copy_flag] = data[left];
            left--;
            copy_flag--;
        }
        else
        {
            copy[copy_flag] = data[right];
            right--;
            copy_flag--;
        }
    }

    for (; left >= sta; left--)       // while结束后复制数组剩余值
    {
        copy[copy_flag] = data[left];
        copy_flag--;
    }
    for (; right >= sta + length + 1; right--)
    {
        copy[copy_flag] = data[right];
        copy_flag--;
    }

    return count + left_num + right_num;
}


int InversePairs(vector<int> data) 
{
    int len = data.size();
    if (len < 2)
        return 0;
    long long count = 0;
    int start = 0, end = len - 1;
    //vector<int> copy(data.begin(), data.end());
    vector<int> copy = data；
    count = InverseCount(data, copy, start, end);
    return count % 1000000007;
}



// ====================测试代码====================
int main()
{
    vector<int> data = { 1,2,3,4,5,6,7,0 };
    int res = InversePairs(data);

    printf("%d", res);
    //cout << res << endl;
    system("pause");

}










