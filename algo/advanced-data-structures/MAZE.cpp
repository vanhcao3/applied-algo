#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<vector<int>> a(n+1, vector<int>(m+1));
    vector<vector<bool>> visited(n+1, vector<bool>(m+1, false));
    vector<vector<pair<int, int>>> predecessor(n+1, vector<pair<int, int>>(m+1, {-1, -1}));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;

    pair<int, int> lastCell = {-1, -1};
    bool reachedBoundary = false;

    while (!q.empty()) {
        pair<int, int> cell = q.front();
        q.pop();

        int x = cell.first, y = cell.second;
        if (x == 1 || y == 1 || x == n || y == m) {
            lastCell = cell;
            reachedBoundary = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int adj_x = x + dx[i], adj_y = y + dy[i];

            if (!(adj_x < 1 || adj_y < 1 || adj_x > n || adj_y > m) && !visited[adj_x][adj_y] && a[adj_x][adj_y] == 0) {
                q.push({adj_x, adj_y});
                visited[adj_x][adj_y] = true;
                predecessor[adj_x][adj_y] = cell; 
            }
        }
    }

    if (!reachedBoundary) {
        cout << -1 << endl; 
        return 0;
    }
	
	int count = 0;
    for (pair<int, int> at = lastCell; at != make_pair(-1, -1); at = predecessor[at.first][at.second]) {
        count++;
    }
    
    cout << count << endl;

    return 0;
}

