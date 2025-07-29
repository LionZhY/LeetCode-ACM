#include <iostream>
#include <vector>
using namespace std;

// 33 搜索旋转排序数组


int searchTarget(vector<int>& nums, int target) 
{
    int n = nums.size();
    int end = nums[n - 1];
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // target 和 mid 不在同一段
        if (target <= end && nums[mid] > end) // target在右半部分，mid在左
        {
            left = mid + 1;
        }
        else if (target > end && nums[mid] <= end) // target在左半部分，mid在右
        {
            right = mid - 1;
        }
        else // target 和 mid 在同一段（也包括了只有一段的情况）
        {
            if (target < nums[mid])         right = mid - 1;
            else if (target > nums[mid])    left = mid + 1;
            else    return mid;
        }
    }
    
    return -1;        
}




int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    int ans = searchTarget(nums, target);
    cout << ans << endl;

    return 0;
}