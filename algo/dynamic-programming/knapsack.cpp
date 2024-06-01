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

int n, w;
int weight[1000], val[1000];

void solve() {
    cin >> n >> w;
    for(int i=0; i<n; i++) cin >> weight[i];
    for(int i=0; i<n; i++) cin >> val[i];
    
    int dp[w+1] = {};
    
    for(int i=0; i<=n; i++){
		for(int j=w; j>=weight[i]; j--){
			dp[j]=max(dp[j], dp[j-weight[i]]+val[i]);
		}
	}
	cout << dp[w];
	
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
}
