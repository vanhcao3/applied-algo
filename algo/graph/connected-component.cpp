#include <iostream>
#include <vector>
using namespace std;

// Function to add an edge to the graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// DFS function to visit nodes of a component
void DFSUtil(int u, vector<int> adj[], vector<bool> &visited)
{
    visited[u] = true;
    for (int i = 0; i < (int)adj[u].size(); i++)
    {
        if (!visited[adj[u][i]])
            DFSUtil(adj[u][i], adj, visited);
    }
}

// Function to return the number of connected components in an undirected graph
int connectedComponents(vector<int> adj[], int N)
{
    vector<bool> visited(N + 1, false);
    int count = 0;
    for (int v = 1; v <= N; v++)
    {
        if (!visited[v])
        {
            DFSUtil(v, adj, visited);
            count++;
        }
    }
    return count;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> adj[N + 1];
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    cout << connectedComponents(adj, N) << endl;
    return 0;
}