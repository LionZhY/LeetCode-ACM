#include <iostream>
#include <vector>
using namespace std;

// 145 二叉树后序遍历

// 结构树
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归后序遍历 左-右-中
void postorderTraversal(TreeNode* cur, vector<int>& vec)
{
    if (cur == nullptr) return;

    postorderTraversal(cur->left, vec);  // 左
    postorderTraversal(cur->right, vec); // 右
    vec.push_back(cur->val);             // 中
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
    postorderTraversal(root, result); // 4 6 7 5 2 9 8 3 1 

    // 输出
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
