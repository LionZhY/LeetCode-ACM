#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 22 括号生成


vector<string> generateParenthesis(int n) 
{
    vector<string> ans;
    string path(n * 2, 0);

    // 输入已填的 左右括号数量
    auto dfs = [&](this auto&& dfs, int left, int right) ->void 
    {
        // 终止
        if (right == n)
        {
            ans.emplace_back(path);
            return;
        }
        if (left < n)
        {
            path[left + right] = '(';
            dfs(left + 1, right);
        }
        if (right < left)
        {
            path[left + right] = ')';
            dfs(left, right + 1);
        }
    };

    dfs(0, 0);
    return ans;
}

int main()
{
    int n = 3;
    vector<string> ans = generateParenthesis(n);

    for (string s : ans)
    {
        cout << s  << " , ";
    }
    cout << endl;
    
    return 0;
}