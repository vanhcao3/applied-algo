#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int v, const vector<vector<int>> &tree, vector<int> &weights, vector<vector<int>> &dp, int p = -1)
{
    dp[v][0] = 0;
    dp[v][1] = weights[v];
    for (int u : tree[v])
    {
        if (u == p)
            continue;
        dfs(u, tree, weights, dp, v);
        dp[v][0] += max(dp[u][0], dp[u][1]);
        dp[v][1] += dp[u][0];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> weights(n + 1);
    vector<vector<int>> tree(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = 1; i <= n; ++i)
        cin >> weights[i];
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, tree, weights, dp); // Assuming vertex 1 is the root
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}