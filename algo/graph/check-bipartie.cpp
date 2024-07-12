#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100001]; // Adjacency list representation of the graph
int color[100001];       // Stores the color of each vertex, 0 if not colored, 1 or -1 for different colors

// Function to check if the graph is bipartite
bool isBipartite(int N)
{
    for (int i = 1; i <= N; ++i)
    {
        if (color[i] == 0)
        { // If the vertex is not colored
            queue<int> q;
            q.push(i);
            color[i] = 1; // Color the vertex with color 1

            while (!q.empty())
            {
                int v = q.front();
                q.pop();

                for (int u : adj[v])
                {
                    if (color[u] == 0)
                    { // If the adjacent vertex is not colored, color it with opposite color
                        color[u] = -color[v];
                        q.push(u);
                    }
                    else if (color[u] == color[v])
                    { // If the adjacent vertex has the same color, graph is not bipartite
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since the graph is undirected
    }

    cout << isBipartite(N);

    return 0;
}