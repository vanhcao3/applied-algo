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
vector<pair<int,int>> a;
vector<pair<int, int>> res;

void solve() {
    cin >> n;
    a.resize(n);
    for(int i=0; i<n; i++){
		cin >> a[i].first >> a[i].second;
	}
	
	sort(a.begin(), a.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    });
	
	
	res.push_back(a[0]);
	
	int r1 = a[0].second;
	
	for(int i=1; i<n; i++){
		int l1 = a[i].first;
		int r2 = a[i].second;
		
		if(l1 > r1){
			res.push_back(make_pair(l1, r2));
			r1 = r2;
		}
	}
	
	cout << res.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
}
