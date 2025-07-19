#include <iostream>
#include <algorithm>
using namespace std;

// 124 二叉树中的最大路径和


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


int maxPathSum(TreeNode* root) 
{
    int ans = INT_MIN;

    auto dfs = [&] (this auto&& dfs, TreeNode* node) ->int {

        if (node == nullptr)    return 0;// 没有节点，和为0

        int l_val = dfs(node->left); // 左树最大链和
        int r_val = dfs(node->right); // 右树最大链和

        ans = max(ans, l_val + r_val + node->val); // 两条链拼成路径（加上当前节点）
        return max(max(l_val, r_val) + node->val, 0); // 当前子树最大链和
                                                        // 和0比较，不取负数
    };

    dfs(root);
    return ans;
}


int main()
{
    /* 构建如下二叉树：  
        -10
        /   \
       9     20
             / \     
           15    7    
    */ 
    

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int ans = maxPathSum(root); // 42
    cout << ans << endl;


    return 0;
}