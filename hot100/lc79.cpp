#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


// 79 单词搜索

const int DIRS[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

bool existWord(vector<vector<char>>& board, string word)
{
    unordered_map<char, int> board_cnt;
    for (int i = 0; i < board.size(); i++)
    {
        for (char c : board[i])     board_cnt[c]++;
    }

    unordered_map<char, int> word_cnt;
    for (char c : word)
    {
        word_cnt[c]++;
    }

    for (char c : word)
    {
        if (word_cnt[c] > board_cnt[c]) return false;
    }     

    if (board_cnt[word.back()] < board_cnt[word[0]])    reverse(word.begin(), word.end());


    int m = board.size();
    int n = board[0].size();

    auto dfs = [&](this auto&& dfs, int i, int j, int k)->bool
    {
        if (board[i][j] != word[k]) return false;
        if (k == word.size() - 1)   return true;

        board[i][j] = 0;
        for (auto& [dx, dy] : DIRS)
        {
            int x = i + dx, y = j + dy;
            if (0 <= x && x < m && 0 <= y && y < n && dfs(x, y, k + 1))     return true;
        }

        board[i][j] = word[k];
        
        return false;
    };

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dfs(i, j, 0))   return true;
        }
    }

    return false;
}


int main()
{
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}};
    
    string word = "ABCCED";
    bool ans = existWord(board, word);
    cout << (ans ? "true" : "false") << endl;

    return 0;
}