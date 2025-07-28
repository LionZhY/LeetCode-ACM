#include <iostream>
#include <vector>
using namespace std;

// 74 搜索二维矩阵

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int m = matrix.size();
    int n = matrix[0].size();

    int left = 0;
    int right = m * n - 1; // 相当于遍历拼接成的 a[i] 从 0 到 m*n 
    while (left <= right)
    {
        int mid = left + ((right - left) / 2);
        int midNum = matrix[mid / n][mid % n];//取出a[mid] = matrix[mid/n][mid%n]
        
        if (midNum < target)    left = mid + 1;
        else if (midNum > target)   right = mid - 1;
        else    return true;
    }

    return false;
}


int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    bool found = searchMatrix(matrix, target);
    cout << (found ? "true" : "false") << endl;

    return 0;
}