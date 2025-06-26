#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

// 力扣53 最大子数组和

/**************  动态规划 *****************/ 
// int maxSubArray(const vector<int>& nums)
// {
//     if (nums.size() == 0)   return 0;

//     // 动态规划
//     vector<int> dp(nums.size()); // 以nums[i]结尾(包括)的最大连续子序列和为dp[i]
//     dp[0] = nums[0];

//     int result = dp[0];

//     for (int i = 1; i < nums.size(); i++)
//     {
//         dp[i] = max(dp[i - 1] + nums[i], nums[i]);
//         result = max(result, dp[i]);
//     }

//     return result;
// }


/**************  贪心 *****************/ 
int maxSubArray(const vector<int>& nums)
{
    int result = INT32_MIN;
    int count = 0;

    // 记录连续和count，如果count < 0，舍弃，再从下一个数开始计和 (负的只会减小后面的加和)
    for (int i = 0; i < nums.size(); i++)
    {
        count += nums[i];
        if (result < count) result = count;
        if (count <= 0)  count = 0; // 舍弃，从下一个数nums[i + 1]重新加和
    }

    return result;
}


int main()
{
    int n;
    cin >> n; // 输入数组元素个数

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // 输入数组
    }

    int result = maxSubArray(nums);
    cout << result << endl;

    return 0;
}
