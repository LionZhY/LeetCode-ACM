#include <iostream>
#include <vector>
using namespace std;


int uniquePaths(int m, int n) 
{
    // dp[i][j]: 从(0,0)到(i,j)一共有dp[i][j]条路径
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // 初始化  第一行和第一列需要初始化，都只有一条路径
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;
    
    // 递推
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // 两个方向的路径数相加
        }
    }

    return dp[m - 1][n - 1];
}


int main()
{
    int m = 3, n = 7;
    int ans = uniquePaths(m, n);
    cout << ans << endl;
    
    return 0;
}