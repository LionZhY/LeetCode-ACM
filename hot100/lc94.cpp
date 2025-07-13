#include <iostream>
#include <vector>
using namespace std;

// 93 二叉树中序遍历

// 结构树
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归中序遍历 左-中-右
void inorderTraversal(TreeNode* cur, vector<int>& vec)
{
    if (!cur)   return;

    inorderTraversal(cur->left, vec);  // 左
    vec.push_back(cur->val);           // 中
    inorderTraversal(cur->right, vec); // 右
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
    inorderTraversal(root, result); // 4 2 6 5 7 1 3 9 8

    // 输出
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
