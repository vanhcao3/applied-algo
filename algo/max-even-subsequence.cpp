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

int n, a[1000001];

int max_even_sub(){
	int pos_sum = 0;
	
	for(int i=0; i<n; i++){
		if(a[i] > 0)
			pos_sum += a[i];
	}
	
	if(pos_sum % 2 == 0)
		return pos_sum;
		
	int ans = INT_MIN;
	
	for(int i=0; i<n; i++){
		if(a[i] % 2 != 0){
			if(a[i] > 0){
				ans = max(ans, pos_sum - a[i]);
			} else {
				ans = max(ans, pos_sum + a[i]);
			}
		}
	}
	return ans;
}

void solve() {
    cin >> n;
    for(int i=0; i<n; i++)
		cin >> a[i];
		
	cout << max_even_sub();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
}
