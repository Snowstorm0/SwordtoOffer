
// 面试题38：字符串的排列
// 题目：输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，
// 则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。



#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string>
using namespace std;

vector<string> result;
vector<string> Permutation(string str)
{
    if (str.length() == 0)
        return result;

    Permutation1(str, 0);
    sort(result.begin(), result.end()); // result[i]是一个排列
    return result;

}

void Permutation1(string str, int begin)
{
    if (str.size() == begin)
    {
        result.push_back(str);
        return;
    }

    int len = str.size();
    for (int i = begin; i < len; i++)
    {
        if (i != begin && str[i] == str[begin])
            continue;
        swap(str[begin], str[i]);
        Permutation1(str, begin + 1);
        swap(str[begin], str[i]);
    }
}


// ====================测试代码====================
int main()
{
    char str[] = "abc";
    vector<string> result;
    result = Permutation(str);

    int len = result.size();
    for (int i = 0; i < len; i++)
    {
        cout << result[i] << endl;
    }
    system("pause");

}





