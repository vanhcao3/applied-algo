#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int disc[MAXN], low[MAXN], parent[MAXN];
bool visited[MAXN], ap[MAXN];
int timeCounter, apCount, bridgeCount;

void dfs(int u) {
    visited[u] = true;
    disc[u] = low[u] = ++timeCounter;
    int children = 0;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            parent[v] = u;
            dfs(v);

            low[u] = min(low[u], low[v]);

            if (parent[u] == -1 && children > 1) ap[u] = true;
            if (parent[u] != -1 && low[v] >= disc[u]) ap[u] = true;
            if (low[v] > disc[u]) bridgeCount++;
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }

    fill(parent, parent + N + 1, -1);
    fill(visited, visited + N + 1, false);
    fill(ap, ap + N + 1, false);
    timeCounter = apCount = bridgeCount = 0;

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) dfs(i);
    }

    for (int i = 1; i <= N; i++) {
        if (ap[i]) apCount++;
    }

    cout << apCount << " " << bridgeCount << endl;

    return 0;
}