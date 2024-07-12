#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // Define infinity as a large enough value

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, INF)); // Initialize distance matrix with infinity

    // Set the distance from a node to itself to 0
    for (int i = 0; i < n; ++i)
    {
        dist[i][i] = 0;
    }

    // Read the edges and update the distance matrix
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;                             // Adjusting 1-based indexing to 0-based
        dist[u][v] = min(dist[u][v], w); // In case of multiple edges, keep the smallest weight
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the distance matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (dist[i][j] == INF)
            {
                cout << "-1 ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}