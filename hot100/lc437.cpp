#include <iostream>
#include <unordered_map>
using namespace std;

// 437 路径总和III

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// 路径和
int pathSum(TreeNode* root, int targetSum) {

    int ans = 0;
    unordered_map<long long, int> cntmap{{0, 1}}; // <路径和，出现次数>

    // 递归
    auto dfs = [&](this auto&& dfs, TreeNode* node, long long s)
    {
        if (node == nullptr)    return;

        s += node->val; // 当前节点的路径和（前缀和）

        // 把node当做路径终点，统计有多少个起点 (560里的si = sj - k出现的次数)
        ans += cntmap[s - targetSum]; 

        cntmap[s]++; // 路径和s出现次数++

        // 递归左右
        dfs(node->left, s);
        dfs(node->right, s);


        // 回溯 恢复现场（去掉当前节点自身的信息）
        cntmap[s]--; 
        // 当前节点只能影响它下层的节点，这些情况在上面的递归中已经处理完毕
        // 在退出本层递归时，当前节点前缀和与其他分支无关，删除记录消除对其他分支的影响

        return;
    };


    dfs(root, 0);// 传入当前node = root, 前缀和 0
    return ans;
}




int main()
{
    /* 构建如下二叉树：  
                 10
               /    \
              5      -3
            /   \      \   
           3     2      11
          / \     \
         3  -2     1   
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
 
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    int targetSum = 8;
    int ans = pathSum(root, targetSum);
    cout << ans << endl;

    return 0;
}
