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

int n, a[100001];

int st[4*100001]; 

void build(int id, int l, int r) {
	if(l == r){
		st[id] = a[l];
		return;
	}
	
	int mid = (l+r)>>1;
	build(2*id, l, mid);
	build(2*id+1, mid+1, r);
	
	st[id] = max(st[2*id], st[2*id+1]);
}

void update(int id, int l, int r, int i, int val) {
	if(l > i || r < i)
		return;
		
	if(l == r){
		st[id] = val;
		return;
	}
	
	int mid = (l+r)>>1;
	update(2*id, l, mid, i, val);
	update(2*id+1, mid+1, r, i, val);
	
	st[id] = max(st[2*id], st[2*id+1]);
}

int query(int id, int l, int r, int i, int j) {
	if(l > j || r < i)
		return -INF;
	
	if(l >= i && r <= j)
		return st[id];
		
	int mid = (l+r)>>1;
	int maxL = query(2*id, l, mid, i, j);
	int maxR = query(2*id+1, mid+1, r, i, j);
	
	return max(maxL, maxR);
}

void solve() {
	
    cin >> n;
    a[0] = 0;
    for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	
	string input;
	int m; cin >> m;
	cin.ignore();
	for(int k=0; k<m; k++){
		getline(cin, input);
		stringstream stream(input);
		string cmd;
		int i, j;
		stream >> cmd; 
		if(cmd == "get-max"){
			stream >> i >> j;
			cout << query(1, 1, n, i, j) << endl;
		} else if(cmd == "update") {
			stream >> i >> j;
			update(1, 1, n, i, j);
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
}
