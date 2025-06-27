#include <iostream>
#include <vector>
#include <climits>

using namespace std;


// 54 螺旋矩阵


static constexpr int DIRS[4][2] = {
    {0, 1},   // 向右
    {1, 0},   // 向下
    {0, -1},  // 向左
    {-1, 0}   // 向上
};

// 返回矩阵的螺旋遍历顺序
vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    int m = matrix.size();        // 行数
    int n = matrix[0].size();     // 列数

    vector<int> ans(m * n);

    int i = 0, j = 0, di = 0;     // 当前坐标 (i, j)，方向索引 di

    for (int k = 0; k < m * n; k++) 
    {
        ans[k] = matrix[i][j];      // 收集当前元素
        matrix[i][j] = INT_MAX;     // 标记访问

        int x = i + DIRS[di][0];    // 下一行
        int y = j + DIRS[di][1];    // 下一列

        // 出界或已访问，右转
        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == INT_MAX) {
            di = (di + 1) % 4;
        }

        // 实际移动
        i += DIRS[di][0];
        j += DIRS[di][1];
    }

    return ans;
}



int main() {
    int m, n;
    cin >> m >> n; // 输入矩阵行列数

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            cin >> matrix[i][j]; // 输入矩阵
        }
    }

    vector<int> result = spiralOrder(matrix);
    for (int x : result) 
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
