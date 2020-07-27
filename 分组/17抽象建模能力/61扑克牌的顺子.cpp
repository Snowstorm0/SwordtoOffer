
// 面试题61：扑克牌的顺子
// 题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。

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

bool IsContinuous(vector<int> num)
{

    int len = num.size();
    if (len != 5)
        return false;

    int max = num[0];
    int min = num[0];
    int num0 = 0;

    for (int i = 0; i < len; i++)     // 最小值应不是0
    {
        if (num[i] != 0)
        {
            min = num[i];
            break;
        }
    }


    for (int i = 0; i < len; i++)
    {
        if (num[i] == 0)
            num0++;

        if (min > num[i] && num[i] != 0)
            min = num[i];

        if (max < num[i])
            max = num[i];

        for (int j = i + 1; j < len; j++) // 若有对子，则不是顺子
            if (num[i] == num[j] && num[i] != 0)
                return false;
    }


    if (max - min - (len - num0) + 1 <= num0)  // 间隔数小于0的个数
        return true;

    return false;


}


// ====================测试代码====================
int main()
{
    vector<int>num = { 1,3,0,5,0 };
    bool res = IsContinuous(num);

    cout << res << endl;
    system("pause");
}













