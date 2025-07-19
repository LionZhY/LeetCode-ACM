#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 108 将有序数组转换为二叉搜索树

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* ArrayToBstTraversal(vector<int>& nums, int left, int right)
{
    if (left > right)   return nullptr;

    int mid = left + ((right - left) / 2);
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = ArrayToBstTraversal(nums, left, mid - 1);
    root->right = ArrayToBstTraversal(nums, mid + 1, right);

    return root;
}


// 层序遍历（用于输出）
vector<int> levelOrder(TreeNode* root) 
{
    vector<int> result;
    if (!root)  return result;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        result.push_back(node->val);

        if (node->left)     q.push(node->left);
        if (node->right)    q.push(node->right);

    }

    return result;
}



int main()
{
    // nums = [-10,-3,0,5,9]
    vector<int> nums = {-10, -3, 0, 5, 9};

    TreeNode* root = ArrayToBstTraversal(nums, 0, nums.size() - 1);

    // 层序输出
    vector<int> output = levelOrder(root);
    for (auto val : output)
    {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}




