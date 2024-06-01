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

void solve() {
    cin >> n;
	unordered_set<int> a;
	
	for(int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		if(a.count(tmp)){
			cout << '1' << endl;
		} else {
			a.insert(tmp);
			cout << '0' << endl;
		}
	}	
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
}
