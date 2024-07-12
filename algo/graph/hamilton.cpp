#include <bits/stdc++.h>
using namespace std;

typedef struct Graph
{
    int node;
    int edge;
    map<int, vector<int>> adj;
    map<int, bool> visited;
    queue<int> q;

    Graph(int node, int edge) : node(node), edge(edge)
    {
        for (int i = 1; i <= node; i++)
        {
            visited[i] = false;
        }
    }

    void resetVisited()
    {
        for (int i = 1; i <= node; i++)
        {
            visited[i] = false;
        }
    }

    bool check_hamilton()
    {
        for (int i = 1; i <= node; i++)
        {
            resetVisited();
            if (check_hamilton_util(i, i, 1))
            {
                return true;
            }
        }
        return false;
    }

    bool check_hamilton_util(int start, int current, int count)
    {
        visited[current] = true;

        if (count == node)
        {
            visited[current] = false;
            return find(adj[current].begin(), adj[current].end(), start) != adj[current].end();
        }

        for (int next_node : adj[current])
        {
            if (!visited[next_node])
            {
                if (check_hamilton_util(start, next_node, count + 1))
                {
                    return true;
                }
            }
        }

        visited[current] = false;
        return false;
    }

} Graph;

int main()
{
    int t, n, m;
    int u, v;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        Graph graph(n, m);

        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            graph.adj[u].push_back(v);
            graph.adj[v].push_back(u);
        }

        if (graph.check_hamilton())
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}
