#include <iostream>
#include <vector>
using namespace std;

int lcs(vector<int>& X, vector<int>& Y) {
    int n = X.size(), m = Y.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> X(n), Y(m);
    for (int i = 0; i < n; ++i)
        cin >> X[i];
    for (int i = 0; i < m; ++i)
        cin >> Y[i];

    int result = lcs(X, Y);
    cout << result << endl;

    return 0;
}

