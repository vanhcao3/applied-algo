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

int H, W;
int n;
int h[100], w[100];

int cnt=0;
int x[100], y[100], o[100];
int mark[100][100];

bool check(int vo, int vx, int vy, int k){
	int wk=w[k], hk=h[k];
	if(vo == 1){
		wk=h[k], hk=w[k];
	}
	if(vx+wk>W)
		return false;
	if(vy+hk>H)
		return false;
	for(int i=vx; i<=vx+wk-1; i++)
		for(int j=vy; j<=vy+hk-1; j++)
			if(mark[i][j])
				return false;
	return true;
}

void doMark(int vx, int vy, int vo, int k, bool mark_value){
	int wk=w[k], hk=h[k];
	if(vo == 1){
		wk=h[k]; 
		hk=w[k];
	}
	for(int i=vx; i<vx+wk; i++)
		for(int j=vy; j<vy+hk; j++)
			mark[i][j] = mark_value;
}

void solution(){
	cnt++;
}

void Try(int k){
	for(int vo=0; vo<=1; vo++){
		int wk=w[k], hk=h[k];
		if(vo == 1) {
			wk=h[k]; 
			hk=w[k];
		}
		for(int vx=0; vx<=W-wk; vx++){
			for(int vy=0; vy<=H-hk; vy++){
				if(check(vo, vx, vy, k)){
					x[k]=vx; y[k]=vy; o[k]=vo;
					doMark(vx,vy,vo,k,true);
					if(k==n) 
						solution();
					else
						Try(k+1);
					doMark(vx,vy,vo,k,false);
				}
			}
		}
	}
}

void solve() {
    cin >> H >> W;
    cin >> n;
    for(int i=1; i<=n; i++){
		cin >> h[i] >> w[i];
	}
	for(int i=0; i<W; i++){
		for(int j=0; j<H; j++){
			mark[i][j]=false;
		}
	}
	
	Try(1);
	
	if(cnt > 0) cout << 1;
	else cout << 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
