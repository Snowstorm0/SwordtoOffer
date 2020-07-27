
// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
// 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
// 4、3、5、1、2就不可能是该压栈序列的弹出序列。


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include<iostream>
#include <stack> 
#include<cstdlib>
#include <string>
using namespace std;





bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
    stack<int> sta;
    int len = pushV.size();
    if (len <= 0)
        return false;

    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        while (sta.empty() || sta.top() != popV[i])
        {
            sta.push(pushV[flag]);
            flag++;

            if (flag > len)
                return false;
        }

        if (sta.top() == popV[i])
            sta.pop();
    }

    if (sta.empty() && flag == len)
        return true;

    return false;



}








int main()
{
    vector<int> pushV = { 1,2,3,4,5 };
    vector<int> popV = { 4,5,3,2,1 };
    bool res = IsPopOrder(pushV, popV);

    cout << res << endl;
    system("pause");

}





