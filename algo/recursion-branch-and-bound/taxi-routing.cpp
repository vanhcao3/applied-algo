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

int n, c_min=INF;
int c[100][100], x[200], load;
int best = INF;
int curr = 0;
bool visited[200];
vector<int> best_route;
vector<int> current_route;

bool check(int v, int k) {
    if (visited[v] == true)
        return false;
    if (v > n) {
        if (visited[v-n] == false) {
            return false;
        }
    } else {
        // No need to check load if K constraint is removed
    }
    return true;
}

void update_best() {
    if (curr + c[x[2 * n]][x[0]] < best) {
        best = curr + c[x[2 * n]][x[0]];
        best_route = current_route;
    }
}

void Try(int k) {
    for (int v = 1; v <= 2*n; v++) {
        if (check(v, k)) {
            x[k] = v;
            current_route.push_back(x[k]);
            curr += c[x[k-1]][x[k]];
            visited[v] = true;
            if (v <= n)
                load += 1;
            else 
                load -= 1;
            if (k == 2*n)
                update_best();
            else {
                if (curr + c_min * (2*n + 1 - k) < best) {
                    Try(k + 1);
                }
            }
            if (v <= n)
                load -= 1;
            else 
                load += 1;
            curr -= c[x[k-1]][x[k]];
            visited[v] = false;
            current_route.pop_back();
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i <= 2*n; i++) {
        for (int j = 0; j <= 2*n; j++) {
            cin >> c[i][j];
            if (c[i][j] < c_min)
                c_min = c[i][j];
        }
        visited[i] = false;
    }


    x[0] = 0;
    visited[0] = true;
    Try(1);
    cout << best;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}
