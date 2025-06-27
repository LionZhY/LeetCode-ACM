#include <vector>
#include <iostream>

using namespace std;


// 原地将矩阵中包含0的行列全置0
void setZeroes(vector<vector<int>>& matrix)
{
    if (matrix.size() == 0) return;

    const int m = matrix.size();    // 行数
    const int n = matrix[0].size(); // 列数

    bool firstRow = false; // 第一行是否包含0
    bool firstCol = false; // 第一列是否包含0

    // 标记行列
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (i == 0) firstRow = true; // 第一行的元素
                if (j == 0) firstCol = true; // 第一列的元素
                matrix[0][j] = 0; // 标记列
                matrix[i][0] = 0; // 标记行
            }
        }
    }

     // 遍历非首行首列，使用首行首列的0标记清零
     for (int i = 1; i < m; i++)
     {
        for (int j = 1; j < n; j++)
        {
            if (matrix[0][j] == 0 || matrix[i][0] == 0)     matrix[i][j] = 0;
        }
     }

     // 根据 firstRow firstCol 处理第一行和第一列
     if (firstRow)
     {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
     }
     if (firstCol)
     {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
     }

}



int main()
{
    int m, n;
    cin >> m >> n; // 输入行列数

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j]; // 输入矩阵
        }
    }

    cout << endl;
    
    setZeroes(matrix);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " "; // 输出结果
        }
        cout << endl;
    }

    return 0;
}