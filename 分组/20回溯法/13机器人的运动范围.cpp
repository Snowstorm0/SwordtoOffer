
// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

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

int getsum(int num)
{
    int sum = 0;
    while (num)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int SumCount(int thr, int row, int col, int i, int j, bool* flag)
{
    if (i < 0 || i >= row || j < 0 || j >= col || flag[col*i + j] == 1)
        return 0;
    int count = 0;
    if (getsum(i) + getsum(j) <= thr)
    {
        count++;
        flag[col*i + j] = true;

        // flag 必须为指针，否则在i+1时修改的flag值到了i-1还没有修改
        count += SumCount(thr, row, col, i + 1, j, flag) +
                SumCount(thr, row, col, i - 1, j, flag) +
                SumCount(thr, row, col, i, j + 1, flag) +
                SumCount(thr, row, col, i, j - 1, flag);

        return count;
    }
    return 0;
}

int movingCount(int thr, int row, int col)
{
    if (row < 1 || col < 1)
        return 0;

    int count = 0;
    bool* flag = new bool[row * col];
    for (int i = 0; i < row * col; i++)
        flag[i] = false;

    count = SumCount(thr, row, col, 0, 0, flag);  // 从(0,0)开始

    return count;
}



// ====================测试代码====================
int main()
{

    int res = movingCount(15, 10, 1);

    printf("%d", res);
    //cout << res << endl;
    system("pause");

}










