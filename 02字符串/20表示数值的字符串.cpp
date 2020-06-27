
// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是

#include <stdio.h>
#include <stdlib.h>
//#include <cstdio>
//#include <vector>
//using namespace std;


bool isInteger(char astr) // 是0-9
{
    if (astr >= '0' && astr <= '9')
        return true;
    else
        return false;
}
bool isSign(char astr) // 正负号
{
    if (astr == '+' || astr == '-')
        return true;
    else
        return false;
}
bool isE(char astr) // E或e
{
    if (astr == 'E' || astr == 'e')
        return true;
    else
        return false;
}


bool isNumeric(char* string)
{
    if (string == nullptr)
        return false;

    if (isSign(*string) && ((isInteger(*(string + 1))) || isE(*(string + 1)) || *(string + 1) == '.')) // 正负号
        string++;
    if (isInteger(*string))                 // 整数部分
    {
        while (isInteger(*string))
            string++;
    }
    if ((*string == '.') && isInteger(*(string + 1))) // 小数点
        string++;
    if (*(string - 1) == '.' && isInteger(*string))   // 小数部分
    {
        while (isInteger(*string))
            string++;
    }
    if ((isE(*string)) && (isInteger(*(string - 1)) || isSign(*(string - 1))) && (*(string + 1) != '\0'))  // E或e
    {
        string++;
        if (isSign(*string) && (isInteger(*(string + 1)))) // 正负号
            string++;
        if (isInteger(*string))                 // 整数
        {
            while (isInteger(*string))
                string++;
        }
    }

    if (*string == '\0')
        return true;
    else
        return false;
}


// ====================测试代码====================
int main()
{
    const int len = 100;
    char string[len] = "12e";
    bool restlt = isNumeric(string);
    printf("result: %d\n", restlt);
    system("pause");
    return 0;
}










