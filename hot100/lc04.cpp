#include <vector>
#include <iostream>
using namespace std;


// 4 寻找两个正序数组中的中位数


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    if (nums1.size() > nums2.size())    swap(nums1, nums2); // 保证nums1是少的那个

    // m < n 
    int m = nums1.size(), n = nums2.size(); 

    // 左右插上负无穷，和正无穷
    nums1.insert(nums1.begin(), INT_MIN);
    nums1.push_back(INT_MAX);
    nums2.insert(nums2.begin(), INT_MIN);
    nums2.push_back(INT_MAX);

    // 枚举 nums1 有 i 个数在第一组
    // 那么 nums2 有 j = (m + n + 1) / 2 - i 个数在第一组 
    int i = 0;
    int j = (m + n + 1) / 2;
    while (true)
    {
        // 找到第一组都小于第二组的情况
        if (nums1[i] <= nums2[j + 1] && nums1[i + 1] > nums2[j])// 写 >= 也可以
        {
            int max1 = max(nums1[i], nums2[j]);         // 第一组的最大值
            int min2 = min(nums1[i + 1], nums2[j + 1]); // 第二组的最小值

            if ( (m + n) % 2) // 奇数个，第一组多一个，max1就是中位数
            {
                return max1; 
            }
            else // 偶数个，接缝处区均值
            {
                return (max1 + min2) / 2.0;
            }
        }

        // 继续枚举
        i++;
        j--;
    }        
}


int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    double result = findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
}