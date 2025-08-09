#include <vector>
#include <iostream>

using namespace std;

// 136 只出现一次的数字

int singleNumber(vector<int>& nums) {
    
    // 异或 消除相同的数字

    int ans = 0;
    for (int val : nums)
    {
        ans ^= val; // 遍历nums 执行异或，最后留下的就是出现一次的数字
    }

    return ans;
}

int main()
{
    vector<int> nums = {2, 2, 3, 3, 4};
    int ans = singleNumber(nums);
    cout << ans << endl;
    
    return 0;
}