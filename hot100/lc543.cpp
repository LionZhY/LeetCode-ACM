#include <iostream>
#include <algorithm>
using namespace std;

// 543 二叉树的直径


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


int dfs (TreeNode* node, int& maxDiameter)
{
    if (node == nullptr) return -1;
    int left = dfs(node->left, maxDiameter) + 1;
    int right = dfs(node->right, maxDiameter) + 1;

    maxDiameter = max(maxDiameter, left + right); // 两条链拼成路径（直径）

    return max(left, right); // 递归返回的是当前子树的最大链长
}


int main()
{
    // 构建如下二叉树：
    //           1
    //         /   \
    //        2     3
    //       / \     
    //      4   5     

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int maxDiameter = 0;
    dfs(root, maxDiameter);

    cout << maxDiameter << endl;



    return 0;
}