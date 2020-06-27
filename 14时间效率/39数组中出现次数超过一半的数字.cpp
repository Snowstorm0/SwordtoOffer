
// 面试题39：数组中出现次数超过一半的数字
// 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
// 如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
// 出现了5次，超过数组长度的一半，因此输出2


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> num) 
{
    if (num.size() == 0)
        return 0;

    int count = 1;
    int tmp = num[0];
    int len = num.size();
    for (int i = 0; i < len; i++)
    {
        if (count == 0)   // 开始计下一个数
            tmp = num[i];

        if (tmp == num[i])
            count++;
        else
            count--;
    }

    int result = tmp;
    int time = 0;
    for (int i = 0; i < len; i++)
    {
        if (result == num[i])
            time++;
    }
    if (time > len / 2)
        return result;
    else
        return 0;
}


// ====================测试代码====================
int main()
{
    vector<int> num = { 1,2,3,2,2,2,5,4,2 };
    int result;
    result = MoreThanHalfNum_Solution(num);

    cout << result << endl;
    system("pause");

}





