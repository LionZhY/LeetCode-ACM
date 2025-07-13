#include <iostream>
#include <vector>
using namespace std;

// 144 二叉树前序遍历

// 结构树
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归前序遍历 中-左-右
void preorderTraversal(TreeNode* cur, vector<int>& vec)
{
    if (!cur)   return;

    vec.push_back(cur->val);            // 中
    preorderTraversal(cur->left, vec);  // 左
    preorderTraversal(cur->right, vec); // 右
}



int main()
{
    // 构建如下二叉树：
    //           1
    //         /   \
    //        2     3
    //       / \     \
    //      4   5     8
    //         / \   /
    //        6   7 9

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);

    vector<int> result;
    preorderTraversal(root, result); // 1 2 4 5 6 7 3 8 9 

    // 输出
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
