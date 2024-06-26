#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 11;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

int n, adj[MAX_N][MAX_N], dp[1 << MAX_N][MAX_N];

int tsp(int mask, int u) {
    if (mask == (1 << n) - 1) return adj[u][0]; // finish all nodes (bitmask == 11...11)
    if (dp[mask][u] != -1) return dp[mask][u];

    int ans = INF;
    // Visit all the unvisited nodes and take the best route
    for (int v = 0; v < n; v++) {
        if (!(mask & (1 << v))) { // this node is unvisited
            int cur = adj[u][v] + tsp(mask | (1 << v), v);
            ans = min(ans, cur);
        }
    }
    return dp[mask][u] = ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];
    
    memset(dp, -1, sizeof dp);
    // start from node 0 (bitmask = 00...01)
    cout << "The shortest path has length " << tsp(1, 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}
