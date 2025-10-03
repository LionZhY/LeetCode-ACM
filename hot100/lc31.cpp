#include <vector>
#include <iostream>
using namespace std;

// 31 下一个排列


void nextPermutation(vector<int>& nums) {

    int n = nums.size();

    // [1, 3, 5, 4, 2] 排列组合里面的数字，找下一个比13542大的组合

    // 1. 从右向左找到第一个小于右侧相邻数字的数 nums[i] (3)
    int i = n - 2;
    while (i >=0 && nums[i] >= nums[i + 1]) i--;


    // 找到，进入第2步；否则(i < 0)跳过第2步，说明现在排列递减，是最大数        
    if (i >= 0) 
    {
        // 2. 从右向左，找到 i 右侧第一个大于 nums[i](3) 的数 nums[j](4)，交换
        int j = n - 1;
        while (j > i && nums[i] >= nums[j])  j--;

        swap(nums[i], nums[j]); // [1, 4, 5, 3, 2]
    }


    // 3 反转 新nums[i] 后面的数 -  [1, 4, 2, 3, 5]
    reverse(nums.begin() + i + 1, nums.end());
    
}


int main()
{
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    for (int val : nums)    cout << val << " ";
    cout << endl;

    return 0;
}