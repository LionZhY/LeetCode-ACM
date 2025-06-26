#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    if (intervals.size() == 0)  return intervals;

    // 按左边界排序 从小到大
    sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];} );

    vector<vector<int>> result;
    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (result.back()[1] >= intervals[i][0]) // 有重叠，更新右边界
        {
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
        else // 无重叠，直接放进result
        {
            result.push_back(intervals[i]);
        }
    }

    return result;
}




int main()
{
    int n;
    cin >> n; // intervals数组元素个数 (区间个数)

    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i][0] >> intervals[i][1];// 输入每个区间左右端点
    }

    vector<vector<int>> result = merge(intervals);
    for (const auto& interval : result)
    {
        cout << interval[0] << " " << interval[1] << endl;
    }

    return 0;
}