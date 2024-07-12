#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 10005;
vector<int> g[MAXN]; // Graph representation
int match[MAXN];     // Match of staffs to tasks
bool visited[MAXN];  // Visited tasks for DFS

bool dfs(int task)
{
    if (visited[task])
        return false;
    visited[task] = true;
    for (int staff : g[task])
    {
        if (match[staff] == -1 || dfs(match[staff]))
        {
            match[staff] = task;
            return true;
        }
    }
    return false;
}

int bipartiteMatching(int n, int m)
{
    memset(match, -1, sizeof(match));
    int result = 0;
    for (int i = 1; i <= n; ++i)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i))
            ++result;
    }
    return result;
}

int main()
{
    int n, m, k, staff;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> k;
        while (k--)
        {
            cin >> staff;
            g[i].push_back(staff);
        }
    }
    cout << bipartiteMatching(n, m) << endl;
    return 0;
}