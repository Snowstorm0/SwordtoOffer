
// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

void replaceSpace(char *str, int len) 
{
    int cnt = 0;
    int len2;
    if (str == nullptr)
        return;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
            cnt++;
    }
    len2 = len + 2 * cnt;
    int j = len2 - 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] != ' ')
            str[j--] = str[i];
        else
        {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        }
    }
    return;
}



// ====================测试代码====================
int main()
{
    const int length = 100;
    char str[length] = " helloworld";
    replaceSpace(str, length);
    //printf("result: %d\n", length);
    //system("pause");
    return 0;
}



"%20helloworld"
"%20helloworld"




