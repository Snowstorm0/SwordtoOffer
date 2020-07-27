
// 面试题36：二叉搜索树与双向链表
// 题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求
// 不能创建任何新的结点，只能调整树中结点指针的指向。



#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string>
using namespace std;


struct TreeNode         // 定义二叉树
{
    int val;             // 当前节点值用val表示
    TreeNode *left;      // 指向左子树的指针用left表示
    TreeNode *right;     // 指向右子树的指针用right表示
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }    // 初始化当前结点值为x,左右子树为空
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

//  树的中序遍历输出
void print_inorder(TreeNode* node)
{
    if (node != NULL)
    {
        print_inorder(node->left);
        printf("%d ", node->val);
        system("pause");
        print_inorder(node->right);
    }
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
//  ***************************************








void Convert2(TreeNode* root, TreeNode* &p)
{
    if (root == nullptr)
        return;

    Convert2(root->left, p);

    root->left = p;
    if(p != nullptr)
        p->right = root;
    p = root;

    Convert2(root->right, p);

}

TreeNode* Convert(TreeNode* root)
{
    if (root == nullptr)
        return root;

    TreeNode* p = nullptr;

    Convert2(root, p);

    while (p->left != nullptr)
        p = p->left;
    return p;
}










int main()
{

    TreeNode tree = TreeNode(10);     
    TreeNode* result;

    result = insert(&tree, 6);      
    result = insert(&tree, 4);
    result = insert(&tree, 8);
    result = insert(&tree, 14);
    result = insert(&tree, 12);
    result = insert(&tree, 16);

    //output(result);     

    result = Convert(result);

    output(result);      


}





