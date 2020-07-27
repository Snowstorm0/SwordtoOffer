
// 面试题29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include<iostream>
#include <stack> 
#include<cstdlib>
#include <string>
using namespace std;



vector<int> printMatrix(vector<vector<int> > matrix)
{
    vector<int> res;
    int row = matrix.size();
    int col = matrix[0].size();
    if (row <= 0 || col <= 0)
        return res;

    int top = 0;
    int botm = row - 1;
    int left = 0;
    int right = col - 1;
    while (top <= botm && left <= right)
    {
        if (top <= botm && left <= right) // 上
        {
            for (int i = left; i <= right; i++)
                res.push_back(matrix[top][i]);
            top++;
        }

        if (top <= botm && left <= right) // 右
        {
            for (int i = top; i <= botm; i++)
                res.push_back(matrix[i][right]);
            right--;
        }

        if (top <= botm && left <= right) // 下
        {
            for (int i = right; i >= left; i--)
                res.push_back(matrix[botm][i]);
            botm--;
        }
            
        if (top <= botm && left <= right) // 左
        {
            for (int i = botm; i >= top; i--)
                res.push_back(matrix[i][left]);
            left++;
        }
    }
    return res;
}


// ====================测试代码====================
int main()
{
    vector<vector<int>> matrix;
    int num = 0;
    for (int i = 0; i < 4; i++)
    {
        vector<int> arr;
        for (int j = 0; j < 4; j++)
        {
            matrix[i][j] = num;
            num++;
        }
    }
    vector<int> result = printMatrix(matrix);
    int len = result.size();
    for (int i = 0; i < len; i++)
    {
        cout << result[i] << endl;
    }
    system("pause");

}





