
// 面试题28：对称的二叉树
// 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
// 它的镜像一样，那么它是对称的。



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



//void Mirror(TreeNode *root)    // 获得镜像
//{
//    if (root == nullptr)
//        return;
//    TreeNode* tem = nullptr;
//    if (root->left != nullptr || root->right != nullptr)
//    {
//        tem = root->left;           // 交换
//        root->left = root->right;
//        root->right = tem;
//    }
//    Mirror(root->left);
//    Mirror(root->right);
//}
//void CopyBiTree(TreeNode* root, TreeNode* newroot) //  复制二叉树
//{
//    if (root == nullptr)
//        return;
//    else
//    {
//        newroot->val = root->val;
//        if (root->left != nullptr)
//            newroot->left = new TreeNode(0);
//        if (root->right != nullptr)
//            newroot->right = new TreeNode(0);
//
//        CopyBiTree(root->left, newroot->left);
//        CopyBiTree(root->right, newroot->right);
//    }
//    //output(newroot);
//}
//bool isMirror(TreeNode* node1, TreeNode* node2) // 循环判断
//{
//    if (node1 == nullptr && node2 == nullptr)
//        return true;
//    else if (node1->val != node2->val)
//        return false;
//    else
//        return isMirror(node1->left, node2->left) && isMirror(node1->right, node2->right);
//}
//bool isSymmetrical(TreeNode* root)
//{
//    if (root == nullptr)
//        return false;
//
//    TreeNode* mirroot = new TreeNode(10);
//    CopyBiTree(root, mirroot); //  复制二叉树
//    Mirror(mirroot);   // 获得镜像
//    //output(root);
//    //output(mirroot);
//    bool result = isMirror(root, mirroot);
//    return result;
//}



bool isMirror(TreeNode* node1, TreeNode* node2) // 循环判断
{
    if (node1 == nullptr && node2 == nullptr)
        return true;
    if (node1 == nullptr || node2 == nullptr)
        return false;

    if (node1->val != node2->val)
        return false;
    else
        return isMirror(node1->left, node2->right) && isMirror(node1->right, node2->left);
}
bool isSymmetrical(TreeNode* root)
{
    if (root == nullptr)
        return true;

    bool result = isMirror(root, root);
    return result;
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

    bool result;
    result = isSymmetrical(treeresult);
    printf("%d", result);
    system("pause");

}





