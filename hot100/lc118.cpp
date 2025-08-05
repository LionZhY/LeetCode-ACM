#include <vector>
#include <iostream>
using namespace std;

// 118 杨辉三角

// [1]
// [1, 1]
// [1, 2, 1]
// [1, 3, 3, 1]
// [1, 4, 6, 4, 1]

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> c(numRows);
    
    for (int i = 0; i < numRows; i++)
    {
        c[i].resize(i + 1, 1);

        for (int j = 1; j < i; j++)
        {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }

    return c;
}


int main()
{
    int numRows = 5;
    vector<vector<int>> ans = generate(numRows);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int val : ans[i])  cout << val << " ";
        cout << endl;
    }
    
    return 0;
}
