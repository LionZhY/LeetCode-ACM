#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 51 N皇后

// 验证棋盘是否合法
// 不能同行 同列 同斜线（45度和135度角）
bool isValid(int row, int col, vector<string>& chessboard, int n)
{
    // chessboard - n * n 棋盘
    // 检查列
    for (int i = 0; i < row; i++)
    {
        if (chessboard[i][col] == 'Q')  return false;
    }
    // 检查 45度
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (chessboard[i][j] == 'Q')    return false;
    }
    // 检查 135度
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (chessboard[i][j] == 'Q')    return false;
    }
    
    return true;
}



vector<vector<string>> result;
// 递归
void backtracking(int n, int row, vector<string>& chessboard)
{
    // n - 棋盘大小
    // row - 当前遍历到棋盘第几层了
    // chessboard - n * n 棋盘
    if (row == n) // 终止：遍历到最后一行
    {
        result.push_back(chessboard);
        return;
    }
    for (int col = 0; col < n; col++) // col 遍历每一列 往右走
    {
        if (isValid(row, col, chessboard, n))// 当前棋盘合法，继续放 Q
        {
            chessboard[row][col] = 'Q';
            backtracking(n, row + 1, chessboard); // 递归 往下走 row + 1
            chessboard[row][col] = '.'; // 回溯
        }

        // 棋盘不合法，放弃当前分支，直接往右走
    }
}


vector<vector<string>> solveNQueens(int n) {
    vector<string> chessboard(n, string(n, '.')); // 初始棋盘
    backtracking(n, 0, chessboard);
    return result;        
}

int main()
{
    int n = 4;
    vector<vector<string>> ans = solveNQueens(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (string s : ans[i])     cout << s << endl;
        cout << endl;
    }

    return 0;
}