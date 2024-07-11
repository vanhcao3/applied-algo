#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 11; // Number of vertices
int num[N], low[N], parent[N], counter = 0;
bool isAP[N]; // Articulation points
vector<pair<int, int>> edgeList = {
    {0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 5}, {3, 8}, {4, 5}, {4, 7}, {4, 10}, {5, 6}, {5, 8}, {6, 8}, {6, 9}, {7, 10}};
vector<vector<int>> adj(N);

void createAdjList()
{
    for (auto edge : edgeList)
    {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u)
{
    num[u] = low[u] = ++counter; // Discovery time and low value
    int children = 0;            // Number of children in DFS tree

    for (int v : adj[u])
    {
        if (v == parent[u])
            continue;
        if (num[v])
        {
            low[u] = min(low[u], num[v]);
        }
        else // If v is not visited
        {
            children++;
            parent[v] = u;
            dfs(v);

            // Check if the subtree rooted at v has a connection back to one of u's ancestors
            low[u] = min(low[u], low[v]);

            // If the lowest vertex reachable from subtree under v is below u in DFS tree, then u-v is a bridge
            if (low[v] > num[u])
            {
                cout << "Bridge: " << u << " - " << v << endl;
            }
            if (low[v] >= num[u] && parent[u] != -1)
            {
                cout << "Articulation point: " << u << endl;
                isAP[u] = true;
            }
        }
    }

    if (parent[u] == -1 && children > 1)
    {
        cout << "Articulation point: " << u << endl;
        isAP[u] = true;
    }
}

int main()
{
    // Initialize num, low, and parent arrays
    fill_n(num, N, 0);
    fill_n(low, N, 0);
    fill_n(parent, N, -1);
    fill_n(isAP, N, false);

    // Create adjacency list
    createAdjList();

    // Perform DFS for each component
    for (int i = 0; i < N; i++)
    {
        if (!num[i])
            dfs(i);
    }

    // Print the num array
    cout << "Num array: ";
    for (int i = 0; i < N; i++)
        cout << num[i] << " ";
    cout << endl;

    // Print the low array
    cout << "Low array: ";
    for (int i = 0; i < N; i++)
        cout << low[i] << " ";
    cout << endl;

    // Print the articulation points
    cout << "Articulation points: ";
    for (int i = 0; i < N; i++)
    {
        if (isAP[i])
            cout << i << " ";
    }
    cout << endl;

    return 0;
}
