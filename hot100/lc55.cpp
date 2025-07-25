#include <vector>
#include <iostream>
using namespace std;

// 55 跳跃游戏

bool canJump(vector<int>& nums)
{
    if (nums.size() == 1) return true;

    int cover = 0;
    for (int i = 0; i <= cover; i++)
    {
        cover = max(cover, i + nums[i]); // 更新最大覆盖范围
        if (cover >= nums.size() - 1)   return true;
    }

    return false;
}



int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    bool ans = canJump(nums);
    cout << (ans ? "true" : "false") << endl;

    return 0;
}