#include <iostream>
#include <vector>
using namespace std;


// 34. 在排序数组中查找元素的第一个和最后一个位置


// nums = [5,  7,  7,  8,  8,  10], target = 8
//                 |            |
//            leftBorder     rightBorder


// 找第一个比 target 大的位置 rightBorder
int getRightBorder(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    
    // 当前第一个大于 target 的位置
    int rightBorder = -2; // -2 记录rightBorder没有被赋值的情况
    while (left <= right)
    {
        int mid = left + ((right - left) / 2);
        if (nums[mid] <= target) // 向右缩小范围
        {
            left = mid + 1;
            rightBorder = left;// 新的left就是下一个可能大于target的位置
        }
        else 
        {
            right = mid - 1; 
        }
    }
    return rightBorder;
}


// 找最后一个比 target 小的位置 leftBorder
int getLeftBorder(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    
    // 最后一个比 target 小的位置
    int leftBorder = -2; 
    while (left <= right)
    {
        int mid = left + ((right - left) / 2); 
        if (target <= nums[mid]) // 向左缩小范围
        {
            right = mid - 1;
            leftBorder = right; // 新right 就是下一个可能小于 target 的位置
        }
        else 
        {
            left = mid + 1;
        }
    }
    return leftBorder;
}


vector<int> searchRange(vector<int>& nums, int target) 
{
    int leftBorder = getLeftBorder(nums, target);
    int rightBorder = getRightBorder(nums, target);

    // 情况一：target 在数组范围的右边或者左边，不再数组范围中
    if (leftBorder == -2 || rightBorder== -2)   return {-1, -1};
    
    // 情况三：target 在数组范围中，且数组中存在target
    if (rightBorder - leftBorder > 1)   return {leftBorder + 1, rightBorder - 1};
    
    
    // 情况二：target 在数组范围中，且数组中不存在target
    return {-1, -1};
    
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> ans = searchRange(nums, target); // [3, 4]
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}