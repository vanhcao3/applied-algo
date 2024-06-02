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

int n;

const int N = 1e4+5;
int a[N], dp[N];


int LIS(int i) {
	if(dp[i] != -1)
		return dp[i];
	int res = 1;
	for(int j=1; j<i; j++){
		if(a[j] < a[i])
			res = max(res, 1 + LIS(j));
	}
	dp[i] = res;
	return res;
}

void Trace(int i){
	for(int j = i-1; j>=1; j--){
		if(a[j] < a[i] && dp[i] == 1 + dp[j]){
			Trace(j);
			break;
		}
	}
	cout << a[i] << " ";
}

void solve() {
	memset(dp, -1, sizeof(dp));
	
    cin >> n;
    for(int i=1; i <=n; i++){
		cin >> a[i];
	}
	
	LIS(n);
	
	int ans = 0, pos = 0;
	for(int i = 1; i<=n; i++){
		if(ans < dp[i]){
			ans = dp[i];
			pos = i;
		}
	}
	cout << ans << endl;
	Trace(pos);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
}
