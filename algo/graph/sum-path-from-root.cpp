#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Edge
{
    int v, w;
};

vector<vector<Edge>> adj;
vector<int> subtree_size;
vector<long long> distance_sum;
vector<long long> max_f;

void DFS1(int u, int parent, int depth)
{
    subtree_size[u] = 1;
    for (const Edge &edge : adj[u])
    {
        if (edge.v != parent)
        {
            DFS1(edge.v, u, depth + edge.w);
            subtree_size[u] += subtree_size[edge.v];
            distance_sum[u] += distance_sum[edge.v] + edge.w * subtree_size[edge.v];
        }
    }
}

void DFS2(int u, int parent)
{
    if (parent != -1)
    {
        // Correct calculation of distance_sum[u] considering the entire tree
        distance_sum[u] = distance_sum[parent] + (subtree_size[0] - subtree_size[u] * 2);
        for (const Edge &edge : adj[u])
        {
            if (edge.v == parent)
            {
                distance_sum[u] += edge.w * (subtree_size[0] - subtree_size[u]);
                break;
            }
        }
    }
    max_f[u] = max(max_f[u], distance_sum[u]);
    for (const Edge &edge : adj[u])
    {
        if (edge.v != parent)
        {
            DFS2(edge.v, u);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    adj.resize(n + 1);
    subtree_size.resize(n + 1, 0);
    distance_sum.resize(n + 1, 0);
    max_f.resize(n + 1, 0);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    DFS1(1, -1, 0);
    DFS2(1, -1);

    cout << *max_element(max_f.begin() + 1, max_f.end()) << endl;

    return 0;
}
