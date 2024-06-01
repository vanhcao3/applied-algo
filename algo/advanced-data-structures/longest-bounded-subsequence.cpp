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

int n, Q;
vector<int> a;

void solve() {
    cin >> n >> Q;
    a.push_back(0);
    for(int i=1; i<=n; i++){
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	
	int L=1, res=0, sum=0;
	
	for(int R=1; R<=n; R++){
		sum += a[R];
		
		while(sum > Q){
			sum -= a[L];
			L++;
		}

		res = max(res, R-L+1);
	}
	
	if(res == 0)
		cout << -1;
	else
		cout << res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
}
