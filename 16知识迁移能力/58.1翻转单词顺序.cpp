
// 面试题58（一）：翻转单词顺序
// 题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
// 为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
// 则输出"student. a am I"。

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

string ReverseWord(string str)   // 反转所有字符
{
    int len = str.size();

    if (len <= 1)
        return str;

    int left = 0;
    int right = len - 1;

    while (left < right)
    {
        swap(str[left], str[right]);
        left++;
        right--;
    }

    return str;
}


string ReverseSentence(string str)  // 反转单词顺序
{
    int len = str.size();

    if (len <= 1)
        return str;

    string res;
    string word;

    str = ReverseWord(str);

    for (int i = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            if (word.size() == 0)
                word = str[i];
            else
                word = word + str[i];
        }

        if (str[i] == ' ')
        {
            word = ReverseWord(word);
            res = res + word;
            res = res + ' ';

            word.clear();
        }

        if (i == len - 1)   // 最后一个单词不要空格
        {
            word = ReverseWord(word);
            res = res + word;
            i++;
        }

    }

    return res;

}


// ====================测试代码====================
int main()
{
    string str = "I am a student.";
    string res = ReverseSentence(str);

    //string res = str + str;

    cout << res << endl;
    system("pause");
}













