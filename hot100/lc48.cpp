#include <iostream>
#include <vector>
#include <algorithm> // for std::swap, std::ranges::reverse

using namespace std;

// 将矩阵原地顺时针旋转90度
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // 第一步：主对角线翻转 (i, j) -> (j, i)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // 第二步：每行左右翻转 (j, i) -> (j, n-1-i)
    for (auto& row : matrix) {
        reverse(row.begin(), row.end());  // 使用 std::reverse 替代 ranges::reverse
    }
}

int main() {
    int n;
    cin >> n; // 输入矩阵大小（n x n）

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> matrix[i][j]; // 输入矩阵
        }
    }

    rotate(matrix);

    // 输出旋转后的矩阵
    for (const auto& row : matrix) 
    {
        for (int x : row) 
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
