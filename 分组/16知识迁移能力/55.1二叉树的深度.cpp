
// 面试题55（一）：二叉树的深度
// 题目：输入一棵二叉树的根结点，求该树的深度。从根结点到叶结点依次经过的
// 结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

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

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};


//创建树
TreeNode* insert(TreeNode* tree, int value)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); // 创建一个节点
    node->val = value;      // 初始化节点
    node->left = NULL;
    node->right = NULL;

    TreeNode* temp = tree;      // 从树根开始
    while (temp != NULL)
    {
        if (value < temp->val)  // 小于就进左儿子
        {
            if (temp->left == NULL)
            {
                temp->left = node;
                return tree;
            }
            else {          // 继续判断
                temp = temp->left;
            }
        }
        else {              // 否则进右儿子

            if (temp->right == NULL)
            {
                temp->right = node;
                return tree;
            }
            else {          // 继续判断
                temp = temp->right;
            }
        }
    }
    return tree;
}



int TreeDepth(TreeNode* root)
{
    if (root == NULL)
        return 0;
    int lef = TreeDepth(root->left);
    int rig = TreeDepth(root->right);
    if (lef > rig)
        return lef + 1;
    else
        return rig + 1;
}


int main()
{
    TreeNode tree = TreeNode(10);       // 树的根节点
    TreeNode* result;

    result = insert(&tree, 6);         // 输入n个数并创建这个树
    result = insert(&tree, 4);
    result = insert(&tree, 8);
    result = insert(&tree, 14);
    result = insert(&tree, 12);
    result = insert(&tree, 16);


    int res = TreeDepth(result);

    cout << res << endl;
    system("pause");

}














