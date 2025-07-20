#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 199 二叉树的右视图


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


vector<int> rightSideView(TreeNode* root)
{
    vector<int> result;

    queue<TreeNode*> que;
    if (root != nullptr)    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = que.front();
            que.pop();

            // 将每层最后一个元素放进result
            if (i == (size - 1))    result.push_back(node->val);

            if (node->left)     que.push(node->left);
            if (node->right)    que.push(node->right);
        }
    }

    return result;
}


int main()
{
    /* 构建如下二叉树：  
                1
              /   \
             2     3
            /        
           4      
          /
         5   
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);

    vector<int> result = rightSideView(root); // 1 3 4 5
    for (int val : result)
    {
        cout << val << " ";
    }

    cout << endl;


    return 0;
}
