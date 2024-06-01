#include <bits/stdc++.h>
#define MAX 2000
using namespace std;
int N, K1, K2;
void solve(){
    int S0[MAX], S1[MAX];
    for(int i = 1; i <= N; i++){     S0[i] = 0; S1[i] = 0;    }
    S0[1] = 1;    S1[K1] = 1;   S0[0] = 1;

    for(int i = K1+1; i <= N; i++){
        S0[i] = S1[i-1];        S1[i] = 0;
        for(int j = K1; j <= K2; j++){
            if(i-j >= 0)
                S1[i] = S1[i] + S0[i-j];
        }
    }
    int rs = S0[N] + S1[N];
    cout << rs;
}

void input(){
    cin >> N >> K1 >> K2;
}

int main(){
    input();
    solve();
}
