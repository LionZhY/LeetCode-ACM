#include <iostream>
#include <stack>

using namespace std;

// 155 最小栈

class MinStack 
{

    stack<pair<int, int>> st;

public:
    // 初始化
    MinStack() {
        // 添加栈底哨兵 INT_MAX
        // 这里的 0 写成任意数都可以，反正用不到
        st.emplace(0, INT_MAX); 
    }
    
    void push(int val) {
        st.emplace(val, min(getMin(), val)); // <val, 前缀最小值>       
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first; // val
    }
    
    // 最小值
    int getMin() {
        return st.top().second; // 前缀最小值  
    }
};


int main()
{
    MinStack mt;
    mt.push(-2);
    mt.push(0);
    mt.push(-3);
    cout << "min: " << mt.getMin() << endl;
    mt.pop();
    cout << "st_top: " << mt.top() << endl;

    return 0;

}