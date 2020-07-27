
// 面试题49：丑数
// 题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
// 大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做第一个丑数。求按从小到大的顺序的第N个丑数。


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


int GetUglyNumber_Solution(int index) 
{
    if (index < 2)
        return index;

    int i, i2 = 0, i3 = 0, i5 = 0;
    vector<int> res(index);
    res[0] = 1;
    for (int i = 1; i < index; i++)
    {
        res[i] = min(res[i2]*2, min(res[i3]*3, res[i5]*5));
        if (res[i] == 2 * res[i2])   i2++;
        if (res[i] == 3 * res[i3])   i3++;
        if (res[i] == 5 * res[i5])   i5++;
    }
    return res[index - 1];
}



// ====================测试代码====================
int main()
{
    //vector<int> num = { 3, 32, 321 };
    //string result;
    int result = GetUglyNumber_Solution(8);

    cout << result << endl;
    system("pause");

}














