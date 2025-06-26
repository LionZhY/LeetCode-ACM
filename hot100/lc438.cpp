#include <vector>
#include <string>
#include <iostream>

using namespace std;

// s = "cbaebabacd", p = "abc"
vector<int> findAnagrams(const string& s, const string& p)
{
    vector<int> ans;

    vector<int> cnt_s(26);
    vector<int> cnt_p(26);

    for (char c : p)
    {
        cnt_p[c - 'a']++;
    }

    for (int right = 0; right < s.size(); right++)
    {
        cnt_s[s[right] - 'a']++;
        int left = right - p.size() + 1;

        if(left < 0)    continue;

        if (cnt_s == cnt_p)
        {
            ans.push_back(left);
        }

        cnt_s[s[left] - 'a']--;
    }

    return ans;
}


int main()
{
    string s;
    string p;
    cin >> s >> p; // 输入字符串 s p

    vector<int> result = findAnagrams(s, p);
    for (int idx : result)
    {
        cout << idx << " ";
    }
    cout << endl;
    
    return 0;
}