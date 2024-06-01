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

int n, q;
vector<int> a, psum;

void solve() {
	int sum = 0;
    cin >> n;
    for(int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		sum += tmp;
		a.push_back(tmp);
		psum.push_back(sum);
	}
	
	cin >> q;
	for(int k=0; k<q; k++){
		int i, j;
		cin >> i >> j;
		if(i == 1){
			cout << psum[j-1] << endl;
		} else {
			cout << psum[j-1] - psum[i-2] << endl;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
}
