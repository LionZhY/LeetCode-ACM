#include <vector>
#include <iostream>
using namespace std;

// 75 颜色分类

void sortColors(vector<int>& nums) {

    int p0 = 0; // 维护0的个数（下标）
    int p1 = 0; // 维护1的个数（下标）

    
    for (int i = 0; i < nums.size(); i++)
    {
        int x = nums[i]; // 不断向nums的[0, i-1] 中插入当前 nums[i]

        nums[i] = 2;                // 直接最后一个位置改为2，2始终在最后
        if (x <= 1) nums[p1++] = 1; // 插入的是 0 或 1 
        if (x == 0) nums[p0++] = 0; // 插入的是 0
    }
    
}


int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    for (int val : nums)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

