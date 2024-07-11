#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 11; // Number of vertices
int num[N], low[N], parent[N] = {-1}, counter = 0;
bool isAP[N] = {false}; // Articulation points
vector<vector<int>> adj = {
    {1, 2},       // Node 0
    {0, 2},       // Node 1
    {0, 1, 3},    // Node 2
    {2, 5, 8},    // Node 3
    {5, 7, 10},   // Node 4
    {3, 4, 6, 8}, // Node 5
    {5, 8, 9},    // Node 6
    {4, 10},      // Node 7
    {3, 5, 6},    // Node 8
    {6},          // Node 9
    {4, 7}        // Node 10
};

vector<vector<int>> scc; // Vector to store SCCs

stack<int> stk;
bool inStack[N] = {false};
int sccIndex[N], sccCounter = 0;

void dfs(int u)
{
    num[u] = low[u] = ++counter; // Discovery time and low value
    stk.push(u);
    inStack[u] = true;

    for (int v : adj[u])
    {
        if (v == parent[u])
            continue;
        if (num[v])
        {
            if (inStack[v])
                low[u] = min(low[u], num[v]);
        }
        else // If v is not visited
        {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }

    // Check if u is a root of an SCC
    if (low[u] == num[u])
    {
        vector<int> current_scc;
        int v;
        do
        {
            v = stk.top();
            stk.pop();
            inStack[v] = false;
            current_scc.push_back(v);
            sccIndex[v] = sccCounter;
        } while (v != u);

        scc.push_back(current_scc);
        sccCounter++;
    }
}

void findSCCs()
{
    // Initialize num, low, and parent arrays
    fill_n(num, N, 0);
    fill_n(low, N, 0);
    fill_n(parent, N, -1);
    fill_n(sccIndex, N, -1);

    // Perform DFS for each component
    for (int i = 0; i < N; i++)
    {
        if (!num[i])
            dfs(i);
    }

    // Output SCCs
    cout << "Strongly Connected Components (SCCs):" << endl;
    for (int i = 0; i < (int)scc.size(); ++i)
    {
        cout << "SCC " << i << ": ";
        for (int v : scc[i])
            cout << v << " ";
        cout << endl;
    }
}

int main()
{
    findSCCs();

    return 0;
}
