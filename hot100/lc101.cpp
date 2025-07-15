#include <iostream>
using namespace std;

// 101 对称二叉树
// 时间复杂度： O(n)
// 空间复杂度：
// 		最坏情况下为递归栈深度 O(h)，h 为树高；
// 		平衡二叉树时 O(log n)，最坏退化为 O(n)。

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// 递归比较两棵子树是否镜像对称
bool compare(TreeNode* left, TreeNode* right)
{
    // 排除节点空
    if      (left == nullptr && right == nullptr)       return true;
    else if (left == nullptr || right == nullptr)       return false;
    // 排除节点不空，但值不同的情况
    else if (left->val != right->val)                   return false;

    // 比较外侧和内侧
    return compare(left->left, right->right) && compare(left->right, right->left);
}

// 判断整棵树是否对称
bool isSymmetric(TreeNode* root) 
{
    if (!root) return true;
    return compare(root->left, root->right);
}



int main()
{
    // 构建对称二叉树：
    //         1
    //       /   \
    //      2     2
    //     / \   / \
    //    3   4 4   3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    bool result = isSymmetric(root);
    cout << (result ? "true" : "false") << endl;

    return 0;
}