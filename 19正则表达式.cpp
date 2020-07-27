
// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。

#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;


bool match(char* str, char* pattern)
{
    if (str == nullptr || pattern == nullptr)
        return false;

    if (*str == '\0' && *pattern == '\0') // 结束
        return true;
    else if (*str != '\0' && *pattern == '\0')
        return false;
    else if (*str == '\0' && *pattern != '\0')
    {
        if (*(pattern + 1) == '*')
            return match(str, pattern + 2);
        else
            return false;
    }


    else if (*(pattern + 1) != '*') // 无*
    {
        if (*str == *pattern || *pattern == '.')
            return match(str + 1, pattern + 1);
        else
            return false;
    }
    else if (*(pattern + 1) == '*') // 有 *
    {
        if (*str == *pattern || *pattern == '.')
            return (match(str, pattern + 2) || match(str + 1, pattern) || match(str + 1, pattern + 2));
        else if (*str != *pattern)
            return match(str, pattern + 2);
    }
}


// ====================测试代码====================
int main()
{
    const int len = 100;
    char str[len] = "bbbba", pattern[len] = ".*a*a";
    bool restlt = match(str, pattern);
    printf("result: %d\n", restlt);
    system("pause");
    return 0;
}









