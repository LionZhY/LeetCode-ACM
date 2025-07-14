#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 102 二叉树的层序遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> result;

    queue<TreeNode*> que;
    if (root)   que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        vector<int> vec;

        for (int i = 0; i < size; i++)
        {
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);

            if (node->left)     que.push(node->left);
            if (node->right)    que.push(node->right);
        }

        result.push_back(vec);
    }

    return result;
}



int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);


    vector<vector<int>> result = levelOrder(root);
    for (const auto& level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }



    return 0;
}
















