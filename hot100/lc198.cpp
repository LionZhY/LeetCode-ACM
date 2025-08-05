#include <vector>
#include <iostream>
using namespace std;

// 198 打家劫舍

int rob(vector<int>& nums)
{
    if (nums.size() == 0)   return 0;
    if (nums.size() == 1)   return nums[0];

    // dp[i]: 考虑下标i（包括i）以内的房屋，最多可以偷窃的金额为dp[i]
    vector<int> dp(nums.size());

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++)
    {
        // 决定dp[i]的因素 -- 第i间偷还是不偷
        dp[i] = max(dp[i - 2] + nums[i], // 偷第i间
                    dp[i - 1]); // 不偷第i间
    }

    return dp[nums.size() - 1];        
}


int main()
{
    vector<int> nums = {1, 2, 3, 1};
    int ans = rob(nums);
    cout << ans << endl;

    return 0;
}