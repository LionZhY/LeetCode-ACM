#include <iostream>
#include <queue>

using namespace std;

// 104 二叉树的最大深度
// 时间复杂度：O(n)
// 空间复杂度：O(n)


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


int maxDepth(TreeNode* root)
{
    if (!root)  return 0;

    queue<TreeNode*> que;
    que.push(root);

    int depth = 0;

    while (!que.empty())
    {
        int size = que.size();
        depth++;

        for (int i = 0; i < size; i++)
        {
            TreeNode* node = que.front();
            que.pop();
            if (node->left)     que.push(node->left);
            if (node->right)    que.push(node->right);
        }
    }

    return depth;
}



int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);


    int depth = maxDepth(root);
    cout << depth << endl;


    return 0;
}
















