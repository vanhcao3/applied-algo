#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> d(n + 1), inDegree(n + 1, 0), completionTime(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    for (int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    // Topological sort using Kahn's algorithm
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            completionTime[i] = d[i]; // Start time is the duration itself for tasks with no dependencies
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            completionTime[v] = max(completionTime[v], completionTime[u] + d[v]);
            if (--inDegree[v] == 0)
                q.push(v);
        }
    }

    cout << *max_element(completionTime.begin(), completionTime.end()) << endl;
    return 0;
}