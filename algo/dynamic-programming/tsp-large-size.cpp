#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ld EPS = 1e-9;

const int N = 20;
int n;
int C[N][N], mem[N][1 << N];

int TSP(int i, int S){
	if(S == (1 << n) - 1)
		return mem[i][S] = C[i][0];
		
	if(mem[i][S] != -1)
		return mem[i][S];
	
	int res = INF;
	for(int j = 1; j <= n; j++){
		if(S & (1 << j))
			continue;
		res = min(res, C[i][j] + TSP(j, S | (1 << j)));
	}
	return mem[i][S] = res;
}

void Trace(int i, int S){
	//cout << 0 << " ";
	cout << 1 << " ";
	for(int k = 1; k < n; k++){
		for(int j = 1; j < n; j++){
			if(S & (1 << j))
				continue;
			if(mem[i][S] == C[i][j] + mem[j][S | (1 << j)]){
				i = j;
				S |= (1 << j);
				break;
			}	
		}
		//cout << i << " ";
		cout << i + 1 << " ";
	}
	//cout << 0 << endl;
}

void solve() {
	memset(mem, -1, sizeof(mem));
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> C[i][j];
    TSP(0,1);
    cout << n << endl;
    Trace(0, 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
}
