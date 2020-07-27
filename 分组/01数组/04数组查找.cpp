
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。

#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

//bool Find(int number, int* matrix)
bool Find(int number, vector<vector<int> > matrix)
{
    if (matrix.empty())
        return false;
    bool found = false;
    int rows = matrix.size();
    int columns = matrix[0].size();
    int row = 0, column = columns - 1;

    while (column >= 0 && row < rows)
    {
        if (matrix[row][column] == number)
        {
            found = true;
            break;
        }
            
        else if (matrix[row][column] > number)
            column--;
        else
            row++;
    }
    return found;
}

// ====================测试代码====================
int main()
{
    int number = 7;
    vector<vector<int> > matrix = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
    
    bool result = Find(number, matrix);
    printf("%d\n", result);
    system("pause");
    return 0;
}




