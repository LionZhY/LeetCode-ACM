#include <iostream>
using namespace std;

// 230 二叉搜索树中第 K 小的元素


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// 中序递归
void dfs(TreeNode* root, int& k, int& ans)
{
    if (root == nullptr)    return;

    dfs(root->left, k, ans);
    
    if (k == 0)     return; // 已经走过k个，后面不用遍历了，直接return
    if (--k == 0)   ans = root->val; // 记录递归到的第k个，且 k-- 计数

    dfs(root->right, k, ans);
}


int main()
{
    /* 构建如下二叉树：  
                    5
                  /   \
                 3     6
                / \        
               2   4   
              /
             1   
    */ 
    

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->left->left->left = new TreeNode(1);

    int k = 3;
    int ans = 0;
    dfs(root, k, ans);

    cout << ans << endl; // 3

    return 0;
}