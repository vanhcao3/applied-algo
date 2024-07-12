#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int node, vector<bool> &visited, const vector<vector<int>> &adj, vector<int> &result)
{
    visited[node] = true;
    result.push_back(node);
    for (auto &neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, visited, adj, result);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> result;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Sort the adjacency list to ensure lexicographical order
    for (int i = 1; i <= n; ++i)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    // Assuming DFS starts from node 1
    dfs(1, visited, adj, result);

    for (auto &node : result)
    {
        cout << node << " ";
    }

    return 0;
}