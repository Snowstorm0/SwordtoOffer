
// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H

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


bool isPath(char* mat, int row, int col, char* str, int i, int j, vector<char> flag)
{
    if (i < 0 || i >= row || j < 0 || j >= col)
        return false;
    bool isp = false;
    if (*str == mat[i*col + j] && flag[i*col + j] == 0)
    {
        flag[i*col + j] = 1;  // 已走过该点，先置1再进入递归操作

        if (*(str + 1) == '\0')  // str表示位置，+1表示下一个位置
            return true;    // 字符串结束

        str++;
        isp = isPath(mat, row, col, str, i + 1, j, flag) ||  // 上下左右有一个符合即可
            isPath(mat, row, col, str, i - 1, j, flag) ||
            isPath(mat, row, col, str, i, j + 1, flag) ||
            isPath(mat, row, col, str, i, j - 1, flag);

        if(isp == false)
            flag[i*col + j] = 0;  // 取消已走过该点
        return isp;
    }
    return false;
}

bool hasPath(char* mat, int row, int col, char* str)
{
    vector<char> flag(row * col, 0);  // 用 row * col 个0初始化
    bool hasp = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            hasp = hasp || isPath(mat, row, col, str, i, j, flag); // 任意一个点为起点存在路径即可
        }
    }
    return hasp;
}



// ====================测试代码====================
int main()
{
    //ABCE
    //SFCS
    //ADEE
    char* mat = "ABCESFCSADEE";
    char* str = "ABCB";
    bool res = hasPath(mat, 3, 4, str);

    cout << res << endl;
    system("pause");
}










