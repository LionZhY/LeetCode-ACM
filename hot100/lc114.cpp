#include <iostream>

using namespace std;

// 114 二叉树展开为链表

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



void flatten(TreeNode* root, TreeNode*& head) {

    if (root == nullptr)    return;
    
    // 遍历顺序是 右 - 左 - 中
    flatten(root->right, head); 
    flatten(root->left, head);

    // 中：处理节点，左置空，右接上一个head
    root->left = nullptr;
    root->right = head; // 头插法，相当于链表的 root->next = head

    head = root; // 更新head，现在链表头节点是 root
}

int main()
{
    /* 构建如下二叉树：  
                1
              /   \
             2     5
            / \     \   
           3   4     6
   
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);


    TreeNode* head = nullptr;
    flatten(root, head);
    while (root)
    {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;


    return 0;
}
