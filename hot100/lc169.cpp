#include <vector>
#include <iostream>
using namespace std;

// 169 多数元素

int majorityElement(vector<int>& nums) {

    // 摩尔投票

    int candidate = 0; // 候选众数
    int votes = 0; // 投票

    for (int num : nums)
    {
        if (votes == 0) candidate = num; // 每当votes=0，更新候选众数
        votes += (num == candidate ? 1 : -1); // num = candidate 投票+1，否则-1
    }

    return candidate;
}


int main()
{
    vector<int> nums = {2,2,1,1,1,2,2};
    int ans = majorityElement(nums);

    cout << ans << endl;

    return 0;
}