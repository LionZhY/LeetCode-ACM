#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 131 分割回文串


// 判断回文
bool isPalindrome(const string& s, int start, int end)
{
    for (int i = start, j = end; i < j; i++, j--)
    {
        if (s[i] != s[j])   return false;
    }
    return true;
}


vector<string> path;
vector<vector<string>> result;

// 递归
void backtracking(const string& s, int startIndex) 
{
    // startIndex 下一轮递归遍历的起始位置
    // 终止：如果起始位置已经超出s，说明已经找到一组分割方案
    if (startIndex >= s.size())
    {
        result.push_back(path);
        return;
    }
    for (int i = startIndex; i < s.size(); i++)
    {
        if (isPalindrome(s, startIndex, i)) // 判断[startIndex, i]部分是否回文
        {
            // 是回文，截取[startIndex, i]
            string str = s.substr(startIndex, i - startIndex + 1);
            path.push_back(str);
        }
        else    continue; // 不是回文，直接跳过这一分支
        backtracking(s, i + 1);
        path.pop_back();
    }
}


vector<vector<string>> partition(string s) {
    backtracking(s, 0);
    return result;        
}


int main()
{
    string s = "aab";
    vector<vector<string>> ans = partition(s);
    for (int i = 0; i < ans.size(); i++)
    {
        for (string s : ans[i])     cout << s << " , ";
        cout << endl;
    }


    return 0;
}
