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

int n, sum, a[500];

int dp[500][10000];

int count_change(int n, int sum){
	dp[0][0] = 1;
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<=sum; j++){
			dp[i][j] += dp[i-1][j];
			
			if((j - a[i-1]) >= 0){
				dp[i][j] += dp[i][j - a[i-1]];
			}
		}
	}
	return dp[n][sum];
}

void solve() {
	cin >> n >> sum;
	for(int i=0; i<n; i++)
		cin >> a[i];
		
	memset(dp, 0, sizeof(dp));
	
	int change = count_change(n, sum);
	cout << change;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
