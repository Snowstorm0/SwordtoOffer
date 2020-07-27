
// 面试题34：二叉树中和为某一值的路径
// 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
// 有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。


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




vector<vector<int>> res;
vector<int> vec;

void SumequalNum(TreeNode* root, int num)
{
    if (root == nullptr)
        return;
    vec.push_back(root->val);

    if (root->left == nullptr && root->right == nullptr && root->val == num)
        res.push_back(vec);

    SumequalNum(root->left, num - root->val);
    SumequalNum(root->right, num - root->val);

    vec.pop_back();
}

vector<vector<int> > FindPath(TreeNode* root, int num)
{
    if (root == nullptr)
        return res;
    SumequalNum(root, num);
    return res;
}







int main()
{
    TreeNode tree = TreeNode(10);       // 树的根节点
    TreeNode* result;

    result = insert(&tree, 5);         // 输入n个数并创建这个树
    result = insert(&tree, 12);
    result = insert(&tree, 4);
    result = insert(&tree, 7);

    //print_inorder(result);  
    //output(result);         

    vector<vector<int> > res;
    int num = 22;
    res = FindPath(result, num);

    for(int i=0; i<res.size(); i++)
        for (int j = 0; j<res[0].size(); j++)
            cout << res[i][j] << endl;
    system("pause");

}





