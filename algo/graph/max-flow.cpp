#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge
{
    int to, capacity, flow;
    Edge *res;
    Edge(int to, int capacity) : to(to), capacity(capacity), flow(0), res(nullptr) {}
    int remaining() { return capacity - flow; }
    void addFlow(int f)
    {
        flow += f;
        res->flow -= f;
    }
};

vector<vector<Edge *>> adj;
vector<int> level;

bool bfs(int s, int t)
{
    level.assign(adj.size(), -1);
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (Edge *e : adj[u])
        {
            if (level[e->to] == -1 && e->remaining() > 0)
            {
                level[e->to] = level[u] + 1;
                q.push(e->to);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int u, int t, int flow)
{
    if (u == t)
        return flow;
    for (Edge *e : adj[u])
    {
        if (level[e->to] == level[u] + 1 && e->remaining() > 0)
        {
            int minFlow = dfs(e->to, t, min(flow, e->remaining()));
            if (minFlow > 0)
            {
                e->addFlow(minFlow);
                return minFlow;
            }
        }
    }
    return 0;
}

int maxFlow(int s, int t)
{
    int flow = 0;
    while (bfs(s, t))
    {
        while (int f = dfs(s, t, INT_MAX))
        {
            flow += f;
        }
    }
    return flow;
}

int main()
{
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    adj.resize(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        Edge *e1 = new Edge(v, c);
        Edge *e2 = new Edge(u, 0); // reverse edge with 0 capacity initially
        e1->res = e2;
        e2->res = e1;
        adj[u].push_back(e1);
        adj[v].push_back(e2);
    }
    cout << maxFlow(s, t) << endl;
    return 0;
}