#include <iostream>
#include <vector>
using namespace std;


// 70 爬楼梯

int climbStairs(int n) {
    
    if (n <= 1) return n;
    
    vector<int> dp(n + 1); // dp[i] 爬到第i个台阶，有多少种方法

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
    
}

int main()
{
    int n = 3;
    int ans = climbStairs(n);
    cout << ans << endl;

    return 0;
}