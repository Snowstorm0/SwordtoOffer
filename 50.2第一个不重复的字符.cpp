
// 面试题50（二）：字符流中第一个只出现一次的字符
// 题目：请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从
// 字符流中只读出前两个字符"go"时，第一个只出现一次的字符是'g'。当从该字
// 符流中读出前六个字符"google"时，第一个只出现一次的字符是'l'。

#include <stdio.h>
#include <stdlib.h>
//#include <cstdio>
#include <vector>
using namespace std;

vector<char> str;

//从字符流插入一个字符
void Insert(char ch)
{
    str.push_back(ch);
}

//返回字符流中第一个只出现一次的字符
char FirstAppearingOnce()
{
    int i;
    int len = str.size();
    int ary[256] = { 0 };   // 定义哈希表，ASCII码对应0-256
    for (i = 0; i < len; i++)
        ary[str[i]]++;
    for (i = 0; i < len; i++)
    {
        if (ary[str[i]] == 1)
            return str[i];
    }

    return '#';
}


// ====================测试代码====================
int main()
{
    Insert('g');
    Insert('o');
    Insert('o');
    Insert('g');
    //Insert('l');
    //Insert('e');
    char restlt = FirstAppearingOnce();
    printf("result: %d\n", restlt);
    system("pause");
    return 0;
}






