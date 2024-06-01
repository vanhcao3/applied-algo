#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e4 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int n, a[1000001], q;
int lookup[1000001][20];

void preprocess(){
	for(int i=0; i<n; i++){
		lookup[i][0] = i;
	}
	
	for(int j=1; (1<<j)<= n; j++){
		for(int i=0; i+(1<<j)-1<n; i++){
			if(a[lookup[i][j-1]] < a[lookup[i+(1<<(j-1))][j-1]]){
				lookup[i][j] = lookup[i][j-1];
			} else {
				lookup[i][j] = lookup[i+(1<<(j-1))][j-1];
			}
		}
	}
}

void query(){
	int sum = 0;
	cin >> q;
	for(int k=0; k<q; k++){
		int L, R;
		cin >> L >> R;
		int j = floor(log2(R-L+1));
		if(a[lookup[L][j]] < a[lookup[R-(1<<j)+1][j]]){
			sum += a[lookup[L][j]]; 
		} else {
			sum += a[lookup[R-(1<<j)+1][j]];
		}
	}
	cout << sum;
}

void solve() {
    cin >> n;
    for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	preprocess();
	query();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
}
