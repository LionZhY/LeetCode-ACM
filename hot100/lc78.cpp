#include <vector>
#include <iostream>
using namespace std;


// 78 子集


vector<int> path;
vector<vector<int>> result;

void backtracking(vector<int>& nums, int startIndex)
{
    if (startIndex > nums.size())  return;

    for (int i = startIndex; i < nums.size(); i++)
    {
        path.push_back(nums[i]);
        result.push_back(path); // 处理节点的时候直接放进result

        backtracking(nums, i + 1);

        path.pop_back();
    }
}


vector<vector<int>> subsets(vector<int>& nums) {

    result.push_back(path); // 提前放一个空path进去
    backtracking(nums, 0);
    return result; 
}


int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);
    for (int i = 0; i < result.size(); i++)
    {
        for (int val : result[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}