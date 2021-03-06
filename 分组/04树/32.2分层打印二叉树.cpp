
// 面试题32（二）：分行从上到下打印二叉树
// 题目：从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层
// 打印到一行。



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


vector<vector<int> > Print(TreeNode* root)
{
    vector<vector<int>> vec;
    vector<int> vec1;
    queue<TreeNode*> queue1, queue2;
    TreeNode* top;                   // 队首元素
    if (root == nullptr)
        return vec;

    vec1.push_back(root->val);   // 放入根元素
    vec.push_back(vec1);
    vec1.clear();

    queue1.push(root);
    while (!queue1.empty() || !queue1.empty())
    {
        while (!queue1.empty())
        {
            top = queue1.front();         // 队首元素
            if (top->left != nullptr)     // 子树放入另一个队列
            {
                queue2.push(top->left);
                vec1.push_back(top->left->val);
            }
            if (top->right != nullptr)
            {
                queue2.push(top->right);
                vec1.push_back(top->right->val);
            }
            queue1.pop();             // 弹出队首元素
        }

        if (!vec1.empty())
            vec.push_back(vec1);
        vec1.clear();

        while (!queue2.empty())
        {
            top = queue2.front();         // 队首元素
            if (top->left != nullptr)     // 子树放入另一个队列
            {
                queue1.push(top->left);
                vec1.push_back(top->left->val);
            }
            if (top->right != nullptr)
            {
                queue1.push(top->right);
                vec1.push_back(top->right->val);
            }
            queue2.pop();             // 弹出队首元素
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





