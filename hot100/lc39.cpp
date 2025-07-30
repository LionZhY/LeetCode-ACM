#include <vector>
#include <iostream>
using namespace std;

// 39 组合总和


vector<int> path;
vector<vector<int>> result;

void backtracking(vector<int>& candidates, int target, int sum, int startIndex)
{
    if (sum > target)   return;
    if (sum == target)
    {
        result.push_back(path);
        return;
    }

    for (int i = startIndex; i < candidates.size(); i++)
    {
        sum += candidates[i];
        path.push_back(candidates[i]);

        backtracking(candidates, target, sum, i); // 注意可以重复取当前的数

        sum -= candidates[i];
        path.pop_back();
    }
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // candidates = [2,3,6,7], target = 7
    // [[2,2,3],[7]]

    backtracking(candidates, target, 0, 0);
    return result;  
}



int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates, target);
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