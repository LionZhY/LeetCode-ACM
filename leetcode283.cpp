#include <iostream>
#include <vector>

using namespace std;


void moveZero(vector<int>& nums)
{
    int slowIndex = 0;
    int fastIndex = 0;

    for (fastIndex = 0; fastIndex < nums.size(); fastIndex++)
    {
        if (nums[fastIndex] != 0)
        {
            nums[slowIndex++] = nums[fastIndex]; // 原地向前覆盖0
        }
    }

    for (int i = slowIndex; i < nums.size(); i++)
    {
        nums[i] = 0;
    }
}



int main() 
{
    int n;
    cin >> n; // 输入数组个数

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // 输入数组元素
    }

    moveZero(nums); // 移动 0

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " "; // 输出移动0后的nums
    }
    cout << endl;

    return 0;
}