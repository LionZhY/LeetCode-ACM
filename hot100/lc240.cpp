#include <iostream>
#include <vector>

using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {

    // 比较右上角，target大删行，target小删列

    int m = matrix.size(), n = matrix[0].size();
    
    int i = 0, j = n - 1; // 右上角

    while (i < m && j >= 0)
    {
        if (target == matrix[i][j]) return true; // 找到
        
        if (target > matrix[i][j])  i++; // target大，去下一行
        else                        j--; // target小，去前一列
    }
    
    return false;
}


int main()
{
    int m, n, target;
    cin >> m >> n >> target; // 输入矩阵行数，列数，目标值

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j]; // 输入矩阵元素
        }
    }

    bool found = searchMatrix(matrix, target);
    cout << (found ? "true" : "false") << endl;


    return 0;
}