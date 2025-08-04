#include <vector>
#include <iostream>
using namespace std;

// 215 数组中的第K个最大元素


// 基于快排的快速选择
int quickSelect(vector<int>& nums, int k)
{        
    // 随机选择基准数字
    int p = nums[rand() % nums.size()];

    // 将大于等于小于基准的元素，分别放入三个数组
    vector<int> big, equal, small;
    for (int a : nums)
    {
        if (a < p)      small.push_back(a);
        else if (a > p) big.push_back(a);
        else            equal.push_back(a);
    }

    // 第 k 大元素在big 中，按递归划分
    if (k <= big.size())    
    {
        return quickSelect(big, k);
    }
    // 第 k 大元素在 small 中，递归划分
    if (k > big.size() + equal.size())
    {
        return quickSelect(small, k - (big.size() + equal.size()));
        // 在small里面就是第 [k - (big.size() + equal.size())] 个大的元素
    }

    // 第 k 大元素在 equal 中，找到，返回p
    return p;
}

int main()
{
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    int ans = quickSelect(nums, k);
    cout << ans << endl;

    return 0;
}