#include <string>
#include <iostream>
#include <stack>
using namespace std;

// 20 有效的括号


bool isValid(string s) 
{
    if (s.size() % 2 != 0)  return false; // 如果 s 的长度是奇数，一定不匹配

    stack<char> st; // 根据 s 的左括号，放入相应的右括号
    
    // 三种情况：
    // 1 左括号多余 -- s遍历完，栈不为空
    // 2 括号不匹配 -- s遍历过程中，栈顶括号不匹配
    // 3 右括号多余 -- s遍历过程中，栈已经空

    for (int i = 0; i < s.size(); i++)
    {
        // 根据 s 里的左括号，往栈里加入对应的右括号
        if (s[i] == '(')        st.push(')');
        else if (s[i] == '[')   st.push(']');
        else if (s[i] == '{')   st.push('}');

        // 第3种 和 第2种 情况，直接false （注意if里顺序不能换）
        else if (st.empty() || st.top() != s[i])    return false; 

        // st.top() == s[i] 遍历到对应的右括号就弹出栈顶
        else    st.pop();
    }

    // 第1种 情况，遍历完s，但栈不为空，这里就返回false
    // 如果为空，说明符合要求，返回的是true
    return st.empty();
}


int main()
{
    string s = "()[]{(}";
    bool result = isValid(s);
    cout << (result ? "true" : "false") << endl;

    return 0;
}