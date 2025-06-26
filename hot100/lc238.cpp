#include <iostream>
#include <vector>

using namespace std;


vector<int> productExceptSelf(const vector<int>& nums)
{
    int n = nums.size();

    // nums[i]前的乘积 * nums[i]后的乘积

    // pre[i] = nums[0]*nums[1]*...*nums[i-1]
    vector<int> pre(n, 1);
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] * nums[i - 1];
    }

    // suf[i] = nums[i+1]*nums[i+2]*...*nums[n-1]
    vector<int> suf(n, 1);
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i]  = suf[i + 1] * nums[i + 1]; // 从后向前乘
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = pre[i] * suf[i];
    }

    return ans;
}




int main()
{
    int n;
    cin >> n;// nums元素个数

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];// 输入数组
    }

    vector<int> result = productExceptSelf(nums);
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}