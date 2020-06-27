
// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string>
using namespace std;


bool IsSquence(vector<int> vec, int beg, int end)
{
    int len = end - beg + 1;
    if (len == 0 || len == 1)
        return true;
    int left = 0;
    int right = 0;
    
    int i = beg;
    while (i < end && vec[i] < vec[end])
    {
        left++;
        i++;
    }
    while (i < end && vec[i] > vec[end])
    {
        right++;
        i++;
    }
    if (left + right + 1 != len)
        return false;

    return IsSquence(vec, beg, beg + left - 1) && IsSquence(vec, beg + left, beg + left + right - 1);
}


bool VerifySquenceOfBST(vector<int> seq)
{
    int len = seq.size();
    if (len <= 0)
        return false;

    return IsSquence(seq, 0, len-1);


}








int main()
{
    vector<int> vec = { 5,7,6,9,11,10,8 };
    //vector<int> vec1(vec.begin(), vec.begin() + 2);
    bool res = VerifySquenceOfBST(vec);
    cout << res << endl;
    system("pause");

}





