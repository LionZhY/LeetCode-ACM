#include <iostream>
#include <vector>
using namespace std;

// 153 寻找旋转排序数组中的最小值


int findMin(vector<int>& nums) {

    int n = nums.size();
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + ((right - left) / 2);

        if (nums[mid] > nums[n - 1])    left = mid + 1;// mid在第一段，min在第二段
        else    right = mid - 1; // mid 和 min 在同一段，且 min 在左

    }

    return nums[left]; 
}


int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};
    int ans = findMin(nums);
    cout << ans << endl;

    return 0;
}