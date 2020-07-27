
// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。


#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

// Parameters:
// numbers:     an array of integers
// length:      the length of array numbers
// duplication: (Output) the duplicated number in the array number
// Return value:       true if the input is valid, and there are some duplications in the array number
//                     otherwise false
bool duplicate(int numbers[], int length, int* duplication) 
{
    if (length == 0)
        return false;
    bool found = false;
    int i, s;


    for (i = 0; i < length; i++)
    {
        while (numbers[i] != i)
        {
            if (numbers[i] == numbers[numbers[i]])
            {
                found = true;
                *duplication = numbers[i];
                return found;
            }
            else
            {
                //swap
                s = numbers[i];
                numbers[i] = numbers[numbers[i]];
                numbers[s] = s;
            }

        }
    }
    return found;
}

// ====================测试代码====================
int main()
{
    int numbers[] = { 2,4,2,1,4 };
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int duplication ;
    
    bool result = duplicate(numbers, length, &duplication);
    printf("%d\n", result);
    printf("%d\n", duplication);
    system("pause");
    return 0;
}







