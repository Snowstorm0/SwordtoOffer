
// 面试题55（二）：平衡二叉树
// 题目：输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中
// 任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

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


// 平衡二叉树：每个节点的左右子树的深度相差不超过1

//int TreeDepth(TreeNode* root) //判断二叉树深度
//{
//    if (root == NULL)
//        return 0;
//    int lef = TreeDepth(root->left);
//    int rig = TreeDepth(root->right);
//    if (lef > rig)
//        return lef + 1;
//    else
//        return rig + 1;
//}

bool IsBalan(TreeNode* root, int *dep) //判断平衡二叉树
{
    if (root == NULL)
    {
        *dep = 0;
        return true;
    }
    int ldep, rdep;
    if (IsBalan(root->left, &ldep) && IsBalan(root->right, &rdep)) // 后序遍历
    {
        int diff = ldep - rdep;
        if (diff >= -1 && diff <= 1)
        {
            if (ldep > rdep)
                *dep = ldep + 1; // dep指向的位置对应的值+1
            else
                *dep = rdep + 1;
            return true;
        }
        return false;
    }
    return false;
}
bool IsBalanced_Solution(TreeNode* pRoot)   // 主函数
{
    int depth = 0;
    return IsBalan(pRoot, &depth);
}




// ====================测试代码====================
int main()
{
    TreeNode* tree = new TreeNode(10);       // 树的根节点
    TreeNode* treeresult;
    treeresult = insert(tree, 6);            // 输入n个数并创建这个树
    treeresult = insert(tree, 4);
    treeresult = insert(tree, 8);
    treeresult = insert(tree, 14);
    treeresult = insert(tree, 12);
    treeresult = insert(tree, 16);

    bool result = IsBalanced_Solution(tree);
    //output(treeresult);         //  输出图形二叉树
    cout << result << endl;
    system("pause");

}














