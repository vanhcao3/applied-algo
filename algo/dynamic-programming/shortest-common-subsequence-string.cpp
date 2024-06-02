#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int dp[N][N];

int lcs(string t1, string t2) {
    int m = t1.length(), n = t2.length();
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (t1[i - 1] == t2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[m][n];
}

void solve() {
    string X, Y;
    getline(cin, X);
    getline(cin, Y);
    int lcs_length = lcs(X, Y);
    int m = X.length(), n = Y.length();
    int scs_length = m + n - lcs_length;
    cout << scs_length << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
