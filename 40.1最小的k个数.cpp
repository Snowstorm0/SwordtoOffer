
// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。

// 时间复杂度为 O(n*logn)


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string>
using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
{
    int len = input.size();
    vector<int> result;

    if (len <= 0)
        return input;
    if(len<k)
        return result;

    sort(input.begin(), input.end());
    for (int i = 0; i < k; i++)
        result.push_back(input[i]);
    return result;
}


// ====================测试代码====================
int main()
{
    vector<int> num = { 1,2,3,2,2,2,5,4,2 };
    int result;
    result = MoreThanHalfNum_Solution(num);

    cout << result << endl;
    system("pause");

}





