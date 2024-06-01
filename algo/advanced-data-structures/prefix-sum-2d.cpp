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

int n, m, q;
int a[1024][1024], psum[1024][1024];

void prefix_sum_2d() {
	psum[1][1] = a[1][1];
	
	for(int i=2; i<=n; i++){
		psum[i][1] = psum[i-1][1] + a[i][1];
	}
	for(int i=2; i<=m; i++){
		psum[1][i] = psum[1][i-1] + a[1][i];
	}
	for(int i=2; i<=n; i++){
		for(int j=2; j<=m; j++){
			psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + a[i][j];
		}
	}
}

void solve() {
	cin >> n >> m;
	
	for(int i=0; i<=n; i++){
		a[i][0] = 0;
		psum[i][0] = 0;
	}
	
	for(int i=0; i<=m; i++){
		a[0][i] = 0;
		psum[0][i] = 0;
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> a[i][j];
		}
	}
	
	prefix_sum_2d();
	
	cin >> q;
	
	for(int i=0; i<q; i++){
		int a, b, c, d; cin >> a >> b >> c >> d;
		
		cout << psum[c][d] - psum[c][b-1] - psum[a-1][d] + psum[a-1][b-1] << endl;
	}
		 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
}
