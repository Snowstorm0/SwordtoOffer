
// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

void replaceSpace(char *str, int length) 
{
    if (str == nullptr)
        return;

    int oldlen = strlen(str) + 1;
    int i, blanknum = 0;
    for (i = 0; i < oldlen; i++)
    {
        if (str[i] == ' ')
        {
            blanknum = blanknum + 1;
        }
    }

    int newlen = oldlen + blanknum * 2;
    int j = 0;
    for (i = 0; i <= oldlen; i++)
    {
        if (str[oldlen - i] != ' ')
        {
            str[newlen - i - j] = str[oldlen - i];
        }
        else
        {
            str[newlen - i - j] = '0';
            str[newlen - i - j - 1] = '2';
            str[newlen - i - j - 2] = '%';
            j = j + 2;
        }
    }
    printf("result: %s\n", str);
    system("pause");

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




