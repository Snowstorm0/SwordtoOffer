
// 面试题45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼
// 接出的所有数字中最小的一个。例如输入数组{3, 32, 321}，则打印出这3个数
// 字能排成的最小数字321323。


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


string PrintMinNumber(vector<int> num) 
{
    int len = num.size();
    if (len <= 0)
        return "";

    sort(num.begin(), num.end(), cmp);
    string result;
    for (int i = 0; i < len; i++)
        result += to_string(num[i]);
    return result;
}
static bool cmp(int a, int b)
{
    string x = to_string(a) + to_string(b);
    string y = to_string(b) + to_string(a);
    return x < y;
}



// ====================测试代码====================
int main()
{
    vector<int> num = { 3, 32, 321 };
    string result;
    result = PrintMinNumber(num);

    cout << result << endl;
    system("pause");

}














