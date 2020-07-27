
// 面试题27：二叉树的镜像
// 题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。



#include <stdio.h>
#include <stdlib.h>
//#include <cstdio>
#include <vector>
#include<iostream>
#include <stack> 
#include<cstdlib>

#include <string>
using namespace std;



struct TreeNode          // 定义二叉树
{
    int val;                       // 当前节点值用val表示
    struct TreeNode *left;     // 指向左子树的指针用left表示
    struct TreeNode *right;    // 指向右子树的指针用right表示
    struct TreeNode *next;  //指向父节点的指针用next表示
    TreeNode(int x) :val(x), left(NULL), right(NULL), next(NULL) { }// 初始化当前结点值为x,左右子树、父节点为空
};

//// 创建节点
//TreeLinkNode* CreateNode(int value)
//{
//    TreeLinkNode* pNode = new TreeLinkNode(value);
//    pNode->val = value;
//    pNode->left = nullptr;
//    pNode->right = nullptr;
//    pNode->parent = nullptr;
//
//    return pNode;
//}

//创建树
TreeNode* insert(TreeNode* tree, int value)
{
    
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); // 创建一个节点
    node->val = value;      // 初始化节点                            // malloc函数可以分配长度
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;

    TreeNode* temp = tree;      // 从树根开始
    while (temp != NULL)
    {
        if (value < temp->val)  // 小于根节点就进左子树
        {
            if (temp->left == NULL)
            {
                temp->left = node;  // 新插入的数为temp的左子树
                node->next = temp; // temp为新插入的数的父节点
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
                node->next = temp; // temp为新插入的数的父节点
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



void Mirror(TreeNode *root) 
{
    if (root == nullptr)
        return;
    TreeNode* tem = nullptr;
    if (root->left != nullptr || root->right != nullptr)
    {
        tem = root->left;
        root->left = root->right;
        root->right = tem;
        //output(root);
    }
    Mirror(root->left);
    Mirror(root->right);
    

    output(root);
}


// ====================测试代码====================
int main()
{
    TreeNode* tree =new TreeNode(10);       // 树的根节点
    TreeNode* treeresult;

    treeresult = insert(tree, 6);         // 输入n个数并创建这个树
    treeresult = insert(tree, 4);
    treeresult = insert(tree, 8);
    treeresult = insert(tree, 14);
    treeresult = insert(tree, 12);
    treeresult = insert(tree, 16);
    //output(treeresult);         //  输出图形二叉树

    TreeNode* result;

    Mirror(treeresult);

    //output(result);         //  输出图形二叉树

}








