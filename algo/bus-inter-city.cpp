#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge
{
    int to;
};

struct State
{
    int city, cost, steps;
};

vector<vector<Edge>> graph;
vector<int> C, D;

int bfs(int n)
{
    vector<vector<int>> minCost(n + 1, vector<int>(n + 1, INF));
    queue<State> q;
    minCost[1][0] = 0;
    q.push({1, 0, 0});

    while (!q.empty())
    {
        State current = q.front();
        q.pop();

        if (current.city == n)
            return current.cost;

        for (const auto &edge : graph[current.city])
        {
            int nextCity = edge.to;
            int nextSteps = current.steps + 1;
            int nextCost = current.cost;

            // Check if we need to pay for a new bus fare
            if (nextSteps > D[current.city] || nextSteps == 1)
            {
                nextCost += C[current.city - 1];
                nextSteps = 1; // Reset steps after paying for the bus
            }

            if (nextCost < minCost[nextCity][nextSteps])
            {
                minCost[nextCity][nextSteps] = nextCost;
                q.push({nextCity, nextCost, nextSteps});
            }
        }
    }

    // Find the minimum cost to reach city n with any number of steps
    return *min_element(minCost[n].begin(), minCost[n].end());
}

int main()
{
    int n, m;
    cin >> n >> m;
    C.resize(n);
    D.resize(n);
    graph.resize(n + 1);

    for (int i = 0; i < n; ++i)
    {
        cin >> C[i] >> D[i];
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v});
        graph[v].push_back({u});
    }

    cout << bfs(n) << endl;

    return 0;
}