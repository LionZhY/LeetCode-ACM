#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 105 从前序与中序遍历序列构造二叉树

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, 
                    vector<int>& preorder, int preorderBegin, int preorderEnd) 
{
    
    if (preorderBegin == preorderEnd)   return nullptr;

    // 根节点
    int rootValue = preorder[preorderBegin]; // 注意用preorderBegin，不要用0
    TreeNode* root = new TreeNode(rootValue);

    if (preorderEnd - preorderBegin == 1)   return root; // 叶子节点

    // 找中序的切割点
    int delimiterIndex = inorderBegin;
    for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++)
    {
        if (inorder[delimiterIndex] == rootValue)   break;
    }

    // 中序切割 左闭右开
    // 左中序 [inorderBegin, delimiterIndex)
    int leftInorderBegin = inorderBegin, leftInorderEnd = delimiterIndex;
    // 右中序 [delimiterIndex, inorderEnd]
    int rightInorderBegin = delimiterIndex + 1, rightInorderEnd = inorderEnd;

    // 前序切割 左闭右开
    // 左前序
    int leftPreorderBegin = preorderBegin + 1; // 分离出root
    int leftPreorderEnd = preorderBegin + 1 + (delimiterIndex - inorderBegin);
    // 右前序
    int rightPreorderBegin = preorderBegin + 1 + (delimiterIndex - inorderBegin);
    int rightPreorderEnd = preorderEnd;
    
    
    // 递归 更新区间索引
    root->left = traversal(inorder, leftInorderBegin, leftInorderEnd,
                            preorder, leftPreorderBegin, leftPreorderEnd);
    root->right = traversal(inorder, rightInorderBegin, rightInorderEnd,
                            preorder, rightPreorderBegin, rightPreorderEnd);

    return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    if (inorder.size() == 0 || preorder.size() == 0)    return nullptr;
    // 左闭右开
    return traversal(inorder, 0, inorder.size(),  
                        preorder, 0, preorder.size());
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
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);

    // 输出打印
    vector<int> output = levelOrder(root);
    for (auto val : output)
    {
        cout << val << " ";
    }


    return 0;
}
