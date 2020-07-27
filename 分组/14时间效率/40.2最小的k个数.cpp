
// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。

// 复杂度为O(n)解法

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string>
using namespace std;




int MinK(int sta, int end, vector<int>& data)
{
    if (sta < 0 || end < 0 || sta > end)
        return 0;
    int flag = sta;
    int tmp = data[end];
    for (int i = sta; i < end; i++)
    {
        if (data[i] < tmp)
        {
            if(i != flag)
                swap(data[i], data[flag]);
            flag++;
        }
    }

    swap(data[flag], data[end]);

    return flag;
}
vector<int> GetLeastNumbers_Solution(vector<int> num, int k)
{
    vector<int> res;

    int len = num.size();
    if (len <= 0 || k <= 0 || len < k)
        return res;

    int sta = 0;
    int end = len - 1;
    int flag = MinK(sta, end, num);// 0 - flag是最小的flag+1个数

    while (flag != k - 1) // 需要 0 -- k-1 为最小的k个数
    {
        if(flag > k-1)
            flag = MinK(sta, flag - 1, num);
        else
            flag = MinK(flag + 1, end, num);
    }

    for (int i = 0; i < k; i++)
        res.push_back(num[i]);

    return res;

}





int main()
{
    vector<int> num = { 4, 5, 1, 6, 2, 7, 3, 8 };
    vector<int> res = GetLeastNumbers_Solution(num, 4);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    system("pause");

}








