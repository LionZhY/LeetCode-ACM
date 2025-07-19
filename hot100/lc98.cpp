#include <iostream>
using namespace std;

// 98 验证二叉搜索树


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// 判断是否为合法 BST
bool isValidBST(TreeNode* root, TreeNode* pre) 
{
    if (!root) return true;

    if (!isValidBST(root->left, pre)) return false;

    if (pre && pre->val >= root->val) return false;
    pre = root;

    if (!isValidBST(root->right, pre)) return false;

    return true;
}




int main()
{
    /* 构建如下二叉树：  
          5
        /   \
       1     4
            / \     
           3   6    
    */ 
    

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);

    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    TreeNode* pre = nullptr;
    cout << (isValidBST(root, pre) ? "true" : "false") << endl;

    return 0;
}