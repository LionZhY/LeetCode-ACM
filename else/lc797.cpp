#include <iostream>
#include <vector>
#include <list>
using namespace std;


/* 797 图论 所有可能路径 */

vector<int> path;
vector<vector<int>> res;

void dfs(const vector<list<int>>& graph, int x, int n)
{
    // x: 目前遍历的节点
    // n: 终点

    // 终止条件，遍历到了终点
    if (x == n)
    {
        res.push_back(path);
        return;
    }

    for (int i : graph[x])
    {
        path.push_back(i);
        dfs(graph, i, n);
        path.pop_back();
    }
}

/* 邻接表 */

int main()
{
    int n = 0, m = 0; // n 个节点，m 条边
    cin >> n >> m;

    int s = 0, t = 0; // 节点 s -> t 有连接

    vector<list<int>> graph(n + 1);
    while (m--)
    {
        cin >> s >> t;
        graph[s].push_back(t);
    }

    path.push_back(1);
    dfs(graph, 1, n); // 从 1 开始的，到 n


    // 输出
    if (res.size() == 0)    cout << -1 << endl;
    for (const vector<int>& pa : res)
    {
        for (int i = 0; i < pa.size(); i++)
        {
            cout << pa[i] << " ";
        }
        cout << endl;
    }


    return 0;
}