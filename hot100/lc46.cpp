#include <vector>
#include <iostream>
using namespace std;


vector<int> path;
vector<vector<int>> result;

void backtracking(vector<int>& nums, vector<bool>& used)
{
    if (path.size() == nums.size())
    {
        result.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i])    continue;

        path.push_back(nums[i]);
        used[i] = true;

        backtracking(nums, used);

        path.pop_back();
        used[i] = false;
    }
}


int main()
{
    vector<int> nums = {1, 2, 3};
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);

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


