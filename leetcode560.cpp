#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int subarraySum(const vector<int>& nums, int k)
{
    int n = nums.size();

    vector<int> s(n + 1, 0); // 前缀和
    for (int i = 0; i < n; i++)
    {
        s[i + 1] = s[i] + nums[i];
    }

    // s[j] - s[i] = k => s[i] = s[j] - k

    int ans = 0;
    unordered_map<int, int> cnt; // <s[i], s[i]出现的次数>
    for (int sj : s)
    {
        if (cnt.count(sj - k))
        {
            ans += cnt[sj - k];
        }
        cnt[sj]++;
    }

    
    return ans;
}


int main() 
{
    int n, k;
    cin >> n >> k; // 输入nums长度 和 k

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // 输入nums
    }

    int result = subarraySum(nums, k);
    cout << result << endl;

    return 0;
}