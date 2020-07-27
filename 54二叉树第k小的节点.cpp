
// 面试题54：二叉搜索树的第k个结点
// 题目：给定一棵二叉搜索树，请找出其中的第k小的结点。


#include <stdio.h>
#include <stdlib.h>
//#include <cstdio>
#include <vector>
#include <queue>
#include<iostream>
#include <stack> 
#include<cstdlib>

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

int cou;                                  // 计数
TreeNode* res = new TreeNode(0);          // 存放中序遍历的第k个结果
void inorder(TreeNode* root)     // 中序遍历
{
    if (cou > 0 && root == nullptr)  // 节点超出树的范围
    {
        res = nullptr;
        return;
    }
    if (root == nullptr)
        return;
    else if(root != nullptr)
    {
        inorder(root->left);   // 左子树

        cou--;
        if (cou >= 0 && root != nullptr)
            res = root;
        //else if(cou >= 0 && root == nullptr)  // 节点超出树的范围
        //    res = nullptr;

        inorder(root->right);   // 右子树
    }
}
TreeNode* KthNode(TreeNode* root, int k)
{
    if (root == nullptr || k <= 0)
        return nullptr;
    cou = k;
    inorder(root);

    return res;
}

// ====================测试代码====================
int main()
{
    TreeNode* tree = new TreeNode(5);       // 树的根节点
    TreeNode* treeresult;
    treeresult = insert(tree, 3);         // 输入n个数并创建这个树
    treeresult = insert(tree, 7);
    treeresult = insert(tree, 2);
    treeresult = insert(tree, 4);
    treeresult = insert(tree, 6);
    treeresult = insert(tree, 8);
    //output(treeresult);         //  输出图形二叉树

    TreeNode* result = KthNode(treeresult, 1);
    cout << result->val << endl;
    system("pause");


}






