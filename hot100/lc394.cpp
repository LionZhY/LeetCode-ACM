#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 394 字符串解码
// 输入：s = "3[a2[c]]"
// 输出："accaccacc"

string decodeString(string s) {
    
    int num = 0;
    stack<int> nums;    // 存数字
    string res = "";
    stack<string> strs; // 存字母

    for (int i = 0; i < s.size(); i++)
    {
        // 遇到数字，存在num
        if (s[i] >= '0' && s[i] <= '9') 
        {
            num = num * 10 + s[i] - '0';// 考虑数字可能不只是个位数，比如150[a]
        }
        // 字母直接拼到res
        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res = res + s[i]; 
        }
        // 遇到'['，将 '[' 前的数字放进nums栈，字母字符放入strs栈
        else if (s[i] == '[') 
        {
            nums.push(num);
            num = 0;
            strs.push(res);
            res = "";
        }
        // 遇到 ']' 开始处理这一组 [] 拼接
        else 
        {
            int times = nums.top(); // 拼接几次res
            nums.pop();
            for (int j = 0; j < times; j++)
            {
                strs.top() += res; // strs顶的字符，拼接res
            }
            res = strs.top(); // 这里res就是暂时拼接完的这一组字符了
            strs.pop();
        }
    }
    return res; 
}

int main()
{
    string s = "3[a2[c]]";
    string ans = decodeString(s);
    cout << ans << endl;

    return 0;
}