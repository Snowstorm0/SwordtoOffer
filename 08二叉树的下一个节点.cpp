
// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。


#include <stdio.h>
#include <stdlib.h>
//#include <cstdio>
#include <vector>
#include<iostream>
#include <stack> 
#include<cstdlib>
#include <string>
using namespace std;



struct TreeNode         // 定义二叉树
{
    int val;             // 当前节点值用val表示
    TreeNode *left;      // 指向左子树的指针用left表示
    TreeNode *right;     // 指向右子树的指针用right表示
    TreeNode *next;
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) { }    // 初始化当前结点值为x,左右子树为空
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



TreeNode* GetNext(TreeNode* pNode)
{
    if (pNode == nullptr)
        return nullptr;

    TreeNode *node = new TreeNode(0);
    if (pNode->right != nullptr)
    {
        pNode = pNode->right;
        while(pNode->left != nullptr)
            pNode = pNode->left;
        node = pNode;
    }

    else if (pNode->next != nullptr && pNode->next->left == pNode)
    {
        node = pNode->next;
    }

    else if (pNode->next == nullptr)
    {
        node = nullptr;
    }
    else
    {
        pNode = pNode->next;
        while(pNode->next != nullptr && pNode->next->left != pNode)
            pNode = pNode->next;

        if (pNode->next == nullptr)
            node = nullptr;
        else if (pNode->next->left == pNode)
            node = pNode->next;
    }

    return node;
}






// ====================测试代码====================
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

    //print_inorder(result);  //  树的中序遍历输出
    output(result);         //  输出图形二叉树


    vector<int> pre = { 1,2,4,7,3,5,6,8 };
    vector<int> vin = { 4,7,2,1,5,3,8,6 };

    result = GetNext(result->left);

    output(result);         //  输出图形二叉树

}









