#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<pair<int, int>> adj[MAXN]; // Adjacency list: node -> (neighbor, weight)
int p[MAXN], N[MAXN];
long long d[MAXN], f[MAXN];
int n;

void DFS1(int u)
{
    for (auto &edge : adj[u])
    {
        int v = edge.first, w = edge.second;
        if (p[v] == 0)
        {
            p[v] = u;
            DFS1(v);
            d[u] += d[v] + N[v] * w;
            N[u] += N[v];
        }
    }
}

void Phase1()
{
    fill(p, p + n + 1, 0);
    fill(d, d + n + 1, 0);
    fill(N, N + n + 1, 1);
    fill(f, f + n + 1, 0);
    p[1] = 1;
    DFS1(1);
}

void DFS2(int u)
{
    for (auto &edge : adj[u])
    {
        int v = edge.first, w = edge.second;
        if (p[v] == 0)
        {
            long long F = f[u] - (d[v] + N[v] * w);
            f[v] = F + d[v] + w * (n - N[v]);
            p[v] = u;
            DFS2(v);
        }
    }
}

void Phase2()
{
    fill(p, p + n + 1, 0);
    f[1] = d[1];
    p[1] = 1;
    DFS2(1);
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Phase1();
    Phase2();

    cout << *max_element(f + 1, f + n + 1) << endl;
    return 0;
}
