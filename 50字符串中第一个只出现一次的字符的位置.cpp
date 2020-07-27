
// 面试题50（一）：字符串中第一个只出现一次的字符的位置
// 题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出 2。


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


int FirstNotRepeatingChar(string str) 
{
    int len = str.size();
    if (len == 0)
        return -1;

    char cha[256] = { 0 };
    for (int i = 0; i < len; i++)
        cha[str[i]]++;
    for (int i = 0; i < len; i++)
    {
        if (cha[str[i]] == 1)
            return i;
    }
}


// ====================测试代码====================
int main()
{
    string str = {2,3,4,2};
    int result = FirstNotRepeatingChar(str);

    cout << result << endl;
    system("pause");

}














