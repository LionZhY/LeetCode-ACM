#include <vector>
#include <iostream>
using namespace std;

// 45 跳跃游戏 II (最小跳跃次数)

int jumpCount(vector<int>& nums)
{
    if (nums.size() == 1)   return 0;

    int ans = 0;
    int curDistance = 0;
    int nextDistance = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        nextDistance = max(nextDistance, i + nums[i]);

        if (i == curDistance)
        {
            ans++;
            curDistance = nextDistance;

            if (curDistance >= nums.size() - 1) break;
        }
    }

    return ans;
}




int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    int ans = jumpCount(nums);
    cout << ans << endl;

    return 0;
}