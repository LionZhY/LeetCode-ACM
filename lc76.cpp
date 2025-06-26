#include <string>
#include <iostream>

using namespace std;

// 判断子串是否覆盖 t 中所有字符
bool is_covered(int cnt_s[], int cnt_t[])
{
    for (int i = 'A'; i <= 'Z'; i++) 
    {
        if (cnt_s[i] < cnt_t[i]) return false;
    }

    for (int i = 'a'; i <= 'z'; i++) 
    {
        if (cnt_s[i] < cnt_t[i]) return false;
    }

    return true;
}

// 求最小覆盖子串
string minWindow(const string& s, const string& t)
{
    int m = s.length();

    int ans_left = -1, ans_right = m;

    int cnt_s[128] = {0};
    int cnt_t[128] = {0};
    for (char c : t)
    {
        cnt_t[c]++;
    }

    // 遍历 s
    int left = 0;
    for (int right = 0; right < m; right++)
    {
        cnt_s[s[right]]++;

        // 如果符合覆盖，更新最短子串端点，左移left
        while (is_covered(cnt_s, cnt_t))
        {
            if (right - left < ans_right - ans_left)
            {
                ans_left = left;
                ans_right = right;
            }

            cnt_s[s[left]]--;
            left++;
        }
    }

    return (ans_left < 0) ? "" : s.substr(ans_left, ans_right - ans_left + 1);
}


int main()
{
    string s, t;
    cin >> s >> t;

    string result = minWindow(s, t);
    cout << result << endl;

    return 0;
}