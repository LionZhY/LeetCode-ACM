#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(const string& s)
{
    int ans = 0;
    
    int left = 0;
    int right = 0;

    unordered_map<char, int> cnt; // <字符，字符出现的次数>

    for (right = 0; right < s.size(); right++)
    {
        char c = s[right];
        cnt[c]++;

        while (cnt[c] > 1)
        {
            cnt[s[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}


int main()
{
    string s;
    cin >> s;

    int result = lengthOfLongestSubstring(s);
    cout << result << endl;

    return 0;
}


