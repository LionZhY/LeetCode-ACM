#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>



int longestConsecutive(const std::vector<int>& nums)
{
    int ans = 0;

    std::unordered_set<int> st(nums.begin(), nums.end()); // 无序不重复
    for (int x : st)
    {
        // 如果 x 不是连续序列的起点，跳过
        if (st.find(x - 1) != st.end())
        {
            continue;
        }
        // x 是连续序列的起点，不断向后寻找下一个数
        int y = x + 1;
        while (st.find(y) != st.end())
        {
            y++;
        }

        ans = std::max(ans, y - x); // 更新连续序列最大长度
    }

    return ans;
}


int main()
{
    int n;
    std::cin >> n; // 输入数字个数

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i]; // 输入数组 nums
    }

    int result = longestConsecutive(nums);
    std::cout << result << std::endl;

    return 0;
}
