
// 面试题32（三）：之字形打印二叉树
// 题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺
// 序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
// 其他行以此类推。



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


vector<vector<int>> Print(TreeNode* root)
{
    vector<vector<int>> vec;
    vector<int> vec1;
    stack<TreeNode*> stack1, stack2; // 分别存放奇偶行
    TreeNode* top;                   // 栈顶元素
    if (root == nullptr)
        return vec;

    vec1.push_back(root->val);   // 放入根元素，奇数行
    vec.push_back(vec1);
    vec1.clear();

    stack1.push(root);
    while (!stack1.empty() || !stack2.empty())
    {
        while (!stack1.empty())           // 偶数行
        {
            top = stack1.top();           // 栈顶元素
            if (top->right != nullptr)    // 子树送入偶数行栈，从右往左
            {
                stack2.push(top->right);
                vec1.push_back(top->right->val);
            }
            if (top->left != nullptr)
            {
                stack2.push(top->left);
                vec1.push_back(top->left->val);
            }

            stack1.pop();             // 弹出栈顶元素
        }
        if (!vec1.empty())
            vec.push_back(vec1);
        vec1.clear();

        while (!stack2.empty())          // 奇数行
        {
            top = stack2.top();          // 栈顶元素
            if (top->left != nullptr)    // 子树送入偶数行栈，从右往左
            {
                stack1.push(top->left);
                vec1.push_back(top->left->val);
            }
            if (top->right != nullptr)
            {
                stack1.push(top->right);
                vec1.push_back(top->right->val);
            }

            stack2.pop();             // 弹出栈顶元素
        }
        if (!vec1.empty())
            vec.push_back(vec1);
        vec1.clear();
    }
    return vec;
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

    vector<vector<int>> result;
    result = Print(treeresult);

    int i,j;
    for (i = 0; i < result.size(); i++)
        for(j = 0; j < result[i].size(); j++)
            cout << result[i][j] << endl;
    system("pause");
}




