
// 面试题41：数据流中的中位数
// 题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么
// 中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
// 那么中位数就是所有数值排序之后中间两个数的平均值。


#include <stdio.h>
#include <stdlib.h>
//#include <cstdio>
#include <vector>
#include <queue>
#include<iostream>
#include <stack> 
#include<cstdlib>
#include<functional>//因为用了greater<int>()
#include <string>
using namespace std;

struct TreeNode          // 定义二叉树
{
    int val;                   // 当前节点值用val表示
    struct TreeNode *left;     // 指向左子树的指针用left表示
    struct TreeNode *right;    // 指向右子树的指针用right表示
    TreeNode(int x) :val(x), left(NULL), right(NULL) { } // 初始化当前结点值为x，左右子树为空
};


//创建树
TreeNode* insert(TreeNode* tree, int value)
{

    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); // 创建一个节点
    node->val = value;      // 初始化节点                            // malloc函数可以分配长度
    node->left = NULL;
    node->right = NULL;

    TreeNode* temp = tree;      // 从树根开始
    while (temp != NULL)
    {
        if (value < temp->val)  // 小于根节点就进左子树
        {
            if (temp->left == NULL)
            {
                temp->left = node;  // 新插入的数为temp的左子树
                return tree;
            }
            else           // 下一轮判断
                temp = temp->left;
        }
        else           // 否则进右子树
        {

            if (temp->right == NULL)
            {
                temp->right = node;  // 新插入的数为temp的右子树
                return tree;
            }
            else           // 下一轮判断
                temp = temp->right;
        }
    }
    return tree;
}

//  ************* 输出图形二叉树 *************
void output_impl(TreeNode* n, bool left, string const& indent)
{
    if (n->right)
    {
        output_impl(n->right, false, indent + (left ? "|     " : "      "));
    }
    cout << indent;
    cout << (left ? '\\' : '/');
    cout << "-----";
    cout << n->val << endl;
    if (n->left)
    {
        output_impl(n->left, true, indent + (left ? "      " : "|     "));
    }
}
void output(TreeNode* root)
{
    if (root->right)
    {
        output_impl(root->right, false, "");
    }
    cout << root->val << endl;
    if (root->left)
    {
        output_impl(root->left, true, "");
    }
    system("pause");
}
//  ******************************************


vector<int> maxv, minv;   // 定义最大最小堆
void Insert(int num)
{
    int a = num;
    int size = maxv.size() + minv.size();
    if ((size & 1) == 1)   // 奇数个放入最小堆
    {
        if (maxv.size() > 0 && num < maxv[0])  // 从第二个数开始判断与最大堆的大小
        {
            maxv.push_back(num);                              // 放入最大堆
            push_heap(maxv.begin(), maxv.end(), less<int>()); // 构建最大堆
            num = maxv[0];                                    // 复制最大堆中最大值
            pop_heap(maxv.begin(), maxv.end(), less<int>());  // 将最大值放在容器尾部
            maxv.pop_back();                                  // 删除放在尾部的最大值
        }
        minv.push_back(num);                              // 放入最小堆
        push_heap(minv.begin(), minv.end(), greater<int>()); // 构建最小堆
    }
    else if ((size & 1) == 0)   // 0或偶数个放入最大堆
    {
        if (minv.size() > 0 && num > minv[0])  // 从第二个数开始判断与最小堆大小
        {
            minv.push_back(num);                                 // 放入最小堆
            push_heap(minv.begin(), minv.end(), greater<int>()); // 构建最小堆
            num = minv[0];                                       // 复制最小堆中最小值
            pop_heap(minv.begin(), minv.end(), greater<int>());  // 将最小值放在容器尾部
            minv.pop_back();                                     // 删除放在尾部的最小值
        }
        maxv.push_back(num);                                 // 放入最大堆
        push_heap(maxv.begin(), maxv.end(), less<int>()); // 构建最大堆
    }
}

double GetMedian()
{
    int size = maxv.size() + minv.size();
    if (size <= 0)
        return 0;
    if (size % 2 == 1)  // 奇数个
        return maxv[0];
    else
        return ((maxv[0] + minv[0]) / 2.0);
}




// ====================测试代码====================
int main()
{
    //TreeNode* tree = new TreeNode(5);       // 树的根节点
    //TreeNode* treeresult;
    //treeresult = insert(tree, 3);         // 输入n个数并创建这个树
    //treeresult = insert(tree, 7);
    //treeresult = insert(tree, 2);
    //treeresult = insert(tree, 4);
    //treeresult = insert(tree, 6);
    //treeresult = insert(tree, 8);
    ////output(treeresult);         //  输出图形二叉树

    Insert(0);
    Insert(1);
    Insert(2);
    //Insert(3);
    double result = GetMedian();

    cout << result;
    system("pause");


}




