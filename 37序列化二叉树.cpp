
// 面试题37：序列化二叉树
// 题目：请实现两个函数，分别用来序列化和反序列化二叉树。


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


vector<int> vec;
void TreeToVector(TreeNode* root)  // 二叉树的值放入vector中
{
    if (root == nullptr)
        vec.push_back(0xFFFFFFFF); // 空指针填入
    else
    {
        vec.push_back(root->val);
        TreeToVector(root->left);
        TreeToVector(root->right);
    }
}
TreeNode* IntpToTree(int* &intp)  // int的值放入二叉树中
//TreeNode* IntpToTree(int* intp)  // 注意 int* &intp 和 int* intp 的区别
{
    if (*intp == 0xFFFFFFFF)    // 读取空指针
    {
        intp++;
        return nullptr;
    }

    TreeNode* result = new TreeNode(*intp);   // 读取intp的值，转为TreeNode类型
    intp++;
    result->left = IntpToTree(intp);
    result->right = IntpToTree(intp);
    
    return result;
}

char* Serialize(TreeNode *root) 
{
    vec.clear();
    TreeToVector(root);  // 二叉树的值放入vector中

    int len = vec.size(), i;
    int* res = new int[len];       // new int[len] 是创建一个维度长度为len的一维数组

    for (i = 0; i < len; i++)
    {
        res[i] = vec[i];
    }

    //for (int a=0; a<len; a++)
    //{
    //    cout << res[a] << endl;
    //}
    //system("pause");

    char* reschar = (char*) res;  // 将res转为指向char类型的指针

    //for (int a=0; a<len; a++)
    //{
    //    cout << *reschar << endl;
    //    reschar++;
    //}
    //system("pause");

    return reschar;
    //return (char*)res;
}
TreeNode* Deserialize(char *str) 
{
    int* intp = (int*) str;       // 将str转为指向int类型的指针
    TreeNode* result = new TreeNode(0);
    result = IntpToTree(intp);
    return result;
}

// ====================测试代码====================
int main()
{
    TreeNode* tree = new TreeNode(10);       // 树的根节点
    TreeNode* treeresult;
    treeresult = insert(tree, 6);         // 输入n个数并创建这个树
    treeresult = insert(tree, 4);
    treeresult = insert(tree, 8);
    treeresult = insert(tree, 14);
    treeresult = insert(tree, 12);
    treeresult = insert(tree, 16);
    //output(treeresult);         //  输出图形二叉树

    char* resultchar;
    resultchar = Serialize(treeresult);

    //for (int a=0; a<7; a++)
    //{
    //    cout << *resultchar << endl;
    //    resultchar++;
    //}
    //system("pause");

    TreeNode* result;
    result = Deserialize(resultchar);

    output(result);    

}






