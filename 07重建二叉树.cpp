 
// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。


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



TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) 
{
    int len = pre.size(); 
    if (len == 0)
        return NULL;

    int i, rootmid = 0;
    vector<int> preleft, preright, vinleft, vinright;
    TreeNode* root = new TreeNode(pre[0]);

    for (i = 0; i < len; i++)  //找到根节点
    {
        if (vin[i] == pre[0])
        {
            rootmid = i;
            break;
        }
    }
    for (i = 0; i < rootmid; i++)  // 根节点的左子树赋值
    {
        preleft.push_back(pre[i + 1]);
        vinleft.push_back(vin[i]);
    }
    for (i = rootmid + 1; i < len; i++)  // 根节点的右子树赋值
    {
        preright.push_back(pre[i]);
        vinright.push_back(vin[i]);
    }
    root->left = reConstructBinaryTree(preleft, vinleft);
    root->right = reConstructBinaryTree(preright, vinright);

    return root;
}


// ====================测试代码====================
int main()
{

    //TreeNode tree = TreeNode(10);       // 树的根节点
    //TreeNode* result;

    //result = insert(&tree, 6);         // 输入n个数并创建这个树
    //result = insert(&tree, 4);
    //result = insert(&tree, 8);
    //result = insert(&tree, 14);
    //result = insert(&tree, 12);
    //result = insert(&tree, 16);

    ////print_inorder(result);  //  树的中序遍历输出
    //output(result);         //  输出图形二叉树


    vector<int> pre = { 1,2,4,7,3,5,6,8 };
    vector<int> vin = { 4,7,2,1,5,3,8,6 };
    TreeNode* result;

    result = reConstructBinaryTree(pre, vin);

    output(result);         //  输出图形二叉树

}









