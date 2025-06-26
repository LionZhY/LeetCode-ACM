#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height)
{
    int ans = 0;

    int left = 0;
    int right = height.size() - 1;

    while (left < right)
    {
        int area = (right - left) * min(height[left], height[right]);
        ans = max(ans, area);

        // 移动短边
        height[left] < height[right] ? left++ : right--;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n; // height数组长度（柱子数量）

    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i]; // 输入每根柱子的高度
    }

    int result = maxArea(height);
    cout << result << endl; // 输出最大盛水面积

    return 0;
}