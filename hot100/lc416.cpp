#include <vector>
#include <iostream>
using namespace std;

// 416 分割等和子集（01背包）


bool canPartition(vector<int>& nums) {
    int sum = 0;
    // 注意：物品的重量和价值都是【元素数值】

    // 背包的体积为 sum/2  -- 对应物品的重量是 元素数值
    // 物品的价值也是 元素数值

    // dp[j] 背包容量(能装的总重量)是j，放进物品后背包的最大重量为dp[j]
    vector<int> dp(10001, 0);

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum % 2 == 1)   return false;
    int target = sum / 2; // 找dp[target] == target


    // 递推填补dp
    for (int i = 0; i < nums.size(); i++) // 先物品
    {
        for (int j = target; j >= nums[i]; j--) // 后背包，从大到小
        {
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }

    // sum/2体积的背包，正好装了sum/2重量
    if (dp[target] == target)   return true; 
    
    return false;
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    bool ans = canPartition(nums);
    cout << (ans ? "true" : "false") << endl;

    return 0;
}