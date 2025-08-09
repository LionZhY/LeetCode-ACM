#include <iostream>
#include <vector>
using namespace std;

// 279 完全平方数


int numSquares(int n) {
    // dp[j] 和为j的完全平方数的最少数量为dp[j]
    vector<uint64_t>  dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i * i <= n; i++) // 先物品（完全平方数 1,4,9,...）
    {
        for (int j = i * i; j <= n; j++) // 后背包
        {
            dp[j] = min(dp[j], dp[j - i * i] + 1); 
        }
    }

    return dp[n];        
}

int main()
{
    int n = 13;
    int ans = numSquares(n);
    cout << ans << endl;

}