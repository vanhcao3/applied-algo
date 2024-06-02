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

int n, sum, a[1000];

int dp[10000];

int min_coin(int n, int sum){
	if (sum == 0)
		return 0;
		
	if(dp[sum] != -1)
		return dp[sum];
		
	int res = INT_MAX;
	
	for(int i=0; i<n; i++){
		if(sum - a[i] >= 0){
			int sub_res = min_coin(n, sum-a[i]);
			
			if(sub_res != INT_MAX && sub_res + 1 < res)
				res = sub_res + 1;
		}
	}
	return dp[sum] = res;
}

void solve() {
    cin >> n >> sum;
    for(int i=0; i<n; i++)
		cin >> a[i];
		
	memset(dp, -1, sizeof(dp));
		
	cout << min_coin(n, sum);
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
