#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 739 每日温度

vector<int> dailyTemperatures(vector<int>& temperatures) 
{
    // temperatures = [73,74,75,71,69,72,76,73]  找对于第 i 天，下一个更高温度出现在几天后

    int n = temperatures.size();
    vector<int> ans(n);
    stack<int> st; // 存的是下标 （没找到下一个最大值的数）

    // 从左往右，栈顶到栈底递增
    for (int i = 0; i < n; i++)
    {
        int t = temperatures[i];

        // 当前 t 大于栈顶，那 t 就是栈顶的下一个更大值
        while (!st.empty() && t > temperatures[st.top()])
        {
            int j = st.top();
            st.pop();
            ans[j] = i - j; // 注意这里收集的是栈顶那个元素对应的 ans[j]
        } 
        
        // t 入栈
        st.push(i);
    }

    return ans;       
}


int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(temperatures); // 1 1 4 2 1 1 0 0 
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}