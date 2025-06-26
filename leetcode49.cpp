#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(const vector<string>& strs)
{
    unordered_map<string, vector<string>> umap;

    for (const string& s : strs)
    {
        string sorted_s = s;
        // 排序 分组
        sort(sorted_s.begin(), sorted_s.end()); // 或者ranges::sort(sorted_s);
        umap[sorted_s].push_back(s);
    }

    vector<vector<string>> ans;
    ans.reserve(umap.size());
    for (auto& [_, value] : umap) 
    {
        ans.push_back(value);
    }

    return ans;
}

int main()
{
    int n; // 字符串数量
    cin >> n;
    vector<string> inputStr(n); // 字符串
    for (int i = 0; i < n; i++)
    {
        cin >> inputStr[i];
    }

    // 调用函数
    vector<vector<string>> result = groupAnagrams(inputStr);

    // 输出
    for (const auto& group : result)
    {
        for (const string& word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }


    return 0;
}