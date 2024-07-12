#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

typedef struct Graph
{
    int node;
    vector<vector<pair<int, int>>> adj;

    Graph(int V) : node(V), adj(V) {}

    void addEdge(int u, int v, int w)
    {
        adj[u].emplace_back(v, w);
    }

    int min_distance(int source, int destination)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(node + 1, INF);

        distance[source] = 0;
        pq.push({0, source});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (const auto &edge : adj[u])
            {
                int v = edge.first;
                int w = edge.second;

                if (distance[u] + w < distance[v])
                {
                    distance[v] = distance[u] + w;
                    pq.push({distance[v], v});
                }
            }
        }
        return distance[destination];
    }

} Graph;

int main()
{
    int n, m, s, t;
    int u, v, w;
    cin >> n >> m;

    Graph graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    cin >> s >> t;

    cout << graph.min_distance(s, t);

    return 0;
}
