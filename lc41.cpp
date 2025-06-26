#include <iostream>
#include <vector>


using namespace std;




int firstMissingPositive(vector<int>& nums)
{
    int n = nums.size();

    // 把每个数放到正确的位置上（即 nums[i] 应该在 下标为nums[i] - 1 位置上）
    for (int i = 0; i < n; i++)
    {
        while (nums[i] != i + 1)
        {
            if (nums[i] < 0 || nums[i] > n || nums[i] == nums[nums[i] - 1]) 
            {
                break; // 非法数字或重复，不处理
            }

            // 把nums[i]交换到正确位置
            int idx = nums[i] - 1;
            swap(nums[i], nums[idx]);
        }
    }

    // 查找第一个不满足 nums[i] == i + 1 的位置
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)   return i + 1;
    }

    // 所有都满足，返回 n + 1
    return n + 1;
}

int main()
{
    int n;
    cin >> n; // 输入nums元素个数

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // 输入数组
    }

    int result = firstMissingPositive(nums);
    cout << result << endl;

}