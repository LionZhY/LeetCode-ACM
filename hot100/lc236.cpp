#include <iostream>
#include <unordered_map>
using namespace std;

// 236 二叉树的最近公共祖先

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    if (root == p || root == q || root == nullptr)  return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);   // 往左找
    TreeNode* right = lowestCommonAncestor(root->right, p, q); // 往右找

    // 返回
    if (left && right)  return root;          // 左右树都找到，返回当前的root
    else if (!left && right)    return right; // 只有右树找到
    else if (left && !right)    return left;  // 只有左树找到
    else                        return nullptr; // 都没找到
    // return left ? left : right;
}




int main()
{
    /* 构建如下二叉树：  
                  3
                /    \
              5        1
            /  \      /  \   
           6    2    0    8
               / \    
              7   4        
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
 
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);


    TreeNode* p = root->left;  // 5
    TreeNode* q = root->right; // 1

    TreeNode* node = lowestCommonAncestor(root, p, q);
    cout << node->val << endl;

    return 0;
}
