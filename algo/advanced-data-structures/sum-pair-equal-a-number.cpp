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

int n, M, cnt = 0;
vector<int> a;

void solve() {
	cin >> n >> M;
	a.push_back(0);
    for(int i=1; i<=n; i++){
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	
	sort(a.begin(), a.end());
	
	int i=1, j=n;
	while(i<j){
		if(a[i] + a[j] == M){
			cnt++;
			i++; j--;
		} else if(a[i] + a[j] < M) {
			i++;
		} else {
			j--;
		}
	}
	cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
}
