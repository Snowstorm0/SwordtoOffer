
// 面试题58（二）：左旋转字符串
// 题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数
// 字2，该函数将返回左旋转2位得到的结果"cdefgab"。

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

string LeftRotateString(string str, int n)
{
    int len = str.size();

    if (n <= 0 || len <= 0)
        return str;


    string res;
    for (int i = n; i < len; i++)
    {
        res = res + str[i];
    }

    for (int i = 0; i < n; i++)
    {
        res = res + str[i];
    }

    return res;
}



// ====================测试代码====================
int main()
{
    string str = "abcdefg";
    string res = LeftRotateString(str, 2);

    cout << res << endl;
    system("pause");
}













