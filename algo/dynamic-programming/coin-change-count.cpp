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

int n, a[10000];
int sum;

int dp[10000][10000];

int count_change(int a[], int n, int sum){
	if(sum == 0)
		return dp[n][sum] = 1;
		
	if(sum < 0 || n <= 0)
		return 0;
		
	if(dp[n][sum] != -1)
		return dp[n][sum];
		
		
	return dp[n][sum] = count_change(a, n, sum - a[n-1]) + count_change(a, n-1, sum);
}

void solve() {
	cin >> n >> sum;
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	memset(dp, -1, sizeof(dp));
	
	cout << count_change(a, n, sum);
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
