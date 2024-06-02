#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

const int N = 1e4 + 5;
string X, Y;
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
	memset(dp, 0, sizeof(dp));
    getline(cin, X);
    getline(cin, Y);
    cout << lcs(X, Y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
}
