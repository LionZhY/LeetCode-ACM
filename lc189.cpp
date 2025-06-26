#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 轮转数组函数
void rotate(vector<int>& nums, int k)
{
    if (nums.size() == 0)   return;

    k = k % nums.size();

    // 三次反转
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}


int main()
{
    int n, k;
    cin >> n >> k; // 输入数组长度 和轮转步数k

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // 输入数组元素
    }

    rotate(nums, k);

    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}