#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[100005]; // Adjacency list: node -> (neighbor, weight)

// DFS function to find the farthest node and its distance from the start node
pair<int, int> dfs(int node, int parent)
{
    pair<int, int> maxDist = {0, node}; // (distance, node)
    for (auto &edge : adj[node])
    {
        int next = edge.first, weight = edge.second;
        if (next != parent)
        {
            pair<int, int> dist = dfs(next, node);
            dist.first += weight; // Add the weight of the current edge
            if (dist.first > maxDist.first)
            {
                maxDist = dist;
            }
        }
    }
    return maxDist;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i < N; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // First DFS to find the farthest node from an arbitrary node (e.g., 1)
    pair<int, int> farthest = dfs(1, -1);

    // Second DFS from the farthest node found in the first DFS
    pair<int, int> diameter = dfs(farthest.second, -1);

    cout << diameter.first << endl; // Output the diameter of the tree
    return 0;
}
