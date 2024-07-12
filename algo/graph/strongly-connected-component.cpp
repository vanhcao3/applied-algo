#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN], adjRev[MAXN];
bool visited[MAXN];
stack<int> finishOrder;
int sccCount = 0, N, M;
vector<vector<int>> sccComponents;

void dfs1(int node)
{
    visited[node] = true;
    for (int next : adj[node])
    {
        if (!visited[next])
        {
            dfs1(next);
        }
    }
    finishOrder.push(node);
}

void dfs2(int node)
{
    visited[node] = true;
    sccComponents.back().push_back(node);
    for (int next : adjRev[node])
    {
        if (!visited[next])
        {
            dfs2(next);
        }
    }
}

void findSCCs()
{
    // Step 1: DFS on original graph to fill finishOrder
    for (int i = 1; i <= N; ++i)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }

    // Step 2: Reverse directions of all arcs
    // Note: This is implicitly done by having adjRev filled during input reading

    // Step 3: DFS on reversed graph in the order of decreasing finish times
    fill_n(visited, N + 1, false); // Reset visited array
    while (!finishOrder.empty())
    {
        int node = finishOrder.top();
        finishOrder.pop();
        if (!visited[node])
        {
            sccComponents.push_back(vector<int>());
            dfs2(node);
            sccCount++;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjRev[v].push_back(u); // Reverse graph
    }

    findSCCs();

    cout << sccCount << endl;

    return 0;
}