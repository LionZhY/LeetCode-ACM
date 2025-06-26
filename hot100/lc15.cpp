#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> result;
    
    // 排序nums
    sort(nums.begin(), nums.end());

    // a = nums[i]  b = nums[left]   c = nums[right]
    for (int i = 0; i < nums.size(); i++)
    {
        // 排序后第一个元素已经大于0，不可能凑成三元组
        if (nums[i] > 0)    break;
        
        // 去重 a
        if (i > 0 && nums[i] == nums[i - 1])    continue;

        // 移动left right 判断三数之和
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right)
        {
            if (nums[i] + nums[left] + nums[right] > 0) right--;
            else if (nums[i] + nums[left] + nums[right] < 0) left++;
            else // 三数之和 = 0，找到一个三元组
            {
                // 收集三元组
                result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                // 去重b和c，向里收缩
                while (right > left && nums[right] == nums[right - 1])
                {
                    right--;
                }
                while (right > left && nums[left] == nums[left + 1])
                {
                    left++;
                }
                // 找到一组三元组后，left和right同时向里收缩，寻找下一组
                right--;
                left++;
            }
        }
    }
    return result;        
}



int main()
{
    int n;
    cin >> n; // nums数组长度

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // 输入nums数组
    }

    vector<vector<int>> result = threeSum(nums);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}