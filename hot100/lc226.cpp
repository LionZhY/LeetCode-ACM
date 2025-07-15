#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 226 反转二叉树
// 时间复杂度： O(n)
// 空间复杂度： O(h)，最坏情况下递归栈深度为树高 h，最坏 O(n)，平均 O(log n)（平衡树）。

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// 递归 前序
TreeNode* invertTree(TreeNode* root) 
{
    if (root == nullptr)    return root;

    swap(root->left, root->right);      // 中
    invertTree(root->left);             // 左
    invertTree(root->right);            // 右

    return root;
}



// 层序遍历（用于输出）
vector<int> levelOrder(TreeNode* root) 
{
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front(); 
        q.pop();
        result.push_back(node->val);

        if (node->left)  q.push(node->left);
        if (node->right) q.push(node->right);
    }

    return result;
}



int main()
{
    // 构建测试树结构
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    invertTree(root); // 反转
    vector<int> output = levelOrder(root);

    // 输出
    for (auto val : output)
    {
        cout << val << " ";
    }

    cout << endl;


    return 0;
}