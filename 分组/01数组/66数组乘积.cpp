
// 面试题66：构建乘积数组
// 题目：给定一个数组A[0, 1, …, n-1]，请构建一个数组B[0, 1, …, n-1]，其
// 中B中的元素B[i] =A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> multiply(const vector<int>& A) 
{
    int i, j, k;
    int n = A.size();
    vector<int> B(n);
    for (i = 0; i < n; i++)
    {
        B[i] = 1;
        for (j = 0; j < n; j++)
        {
            if (j == i)
                B[i] = B[i] * 1;
            else
                B[i] = B[i] * A[j];
        }
    }
    return B;
}

// ====================测试代码====================
int main()
{
    vector<int> A = { 2,4,2,1,4 };
    
    vector<int> result = multiply(A);
    printf("result: %d\n", result);
    system("pause");
    return 0;
}








