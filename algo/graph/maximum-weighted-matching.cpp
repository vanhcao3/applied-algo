#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 500; // Assuming the maximum number of nodes in one part is 500
int n, m, k;
int cost[MAXN][MAXN];   // cost matrix
int lx[MAXN], ly[MAXN]; // labels of X and Y parts
int xy[MAXN];           // xy[x] - vertex that is matched with x
int yx[MAXN];           // yx[y] - vertex that is matched with y
bool S[MAXN], T[MAXN];  // sets S and T in algorithm
int slack[MAXN];        // as in the algorithm description
int slackx[MAXN];       // slackx[y] such a vertex, that l(slackx[y]) + l(y) - w(slackx[y],y) = slack[y]
int prevMatch[MAXN];    // array for memorizing alternating paths

void init_labels()
{
    memset(lx, 0, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++)
            lx[x] = max(lx[x], cost[x][y]);
}

void update_labels()
{
    int x, y, delta = INT_MAX;
    for (y = 0; y < m; y++)
        if (!T[y])
            delta = min(delta, slack[y]);
    for (x = 0; x < n; x++)
        if (S[x])
            lx[x] -= delta;
    for (y = 0; y < m; y++)
        if (T[y])
            ly[y] += delta;
    for (y = 0; y < m; y++)
        if (!T[y])
            slack[y] -= delta;
}

void add_to_tree(int x, int prevx)
{
    S[x] = true;
    prevMatch[x] = prevx;
    for (int y = 0; y < m; y++)
        if (lx[x] + ly[y] - cost[x][y] < slack[y])
        {
            slack[y] = lx[x] + ly[y] - cost[x][y];
            slackx[y] = x;
        }
}

void augment()
{
    if (k == n)
        return;
    int x, y, root;
    int q[MAXN], wr = 0, rd = 0;
    memset(S, false, sizeof(S));
    memset(T, false, sizeof(T));
    memset(prevMatch, -1, sizeof(prevMatch));
    for (x = 0; x < n; x++)
        if (xy[x] == -1)
        {
            q[wr++] = root = x;
            prevMatch[x] = -2;
            S[x] = true;
            break;
        }
    for (y = 0; y < m; y++)
    {
        slack[y] = lx[root] + ly[y] - cost[root][y];
        slackx[y] = root;
    }
    while (true)
    {
        while (rd < wr)
        {
            x = q[rd++];
            for (y = 0; y < m; y++)
                if (cost[x][y] == lx[x] + ly[y] && !T[y])
                {
                    if (yx[y] == -1)
                        break;
                    T[y] = true;
                    q[wr++] = yx[y];
                    add_to_tree(yx[y], x);
                }
            if (y < m)
                break;
        }
        if (y < m)
            break;
        update_labels();
        wr = rd = 0;
        for (y = 0; y < m; y++)
            if (!T[y] && slack[y] == 0)
            {
                if (yx[y] == -1)
                {
                    x = slackx[y];
                    break;
                }
                else
                {
                    T[y] = true;
                    if (!S[yx[y]])
                    {
                        q[wr++] = yx[y];
                        add_to_tree(yx[y], slackx[y]);
                    }
                }
            }
        if (y < m)
            break;
    }
    if (y < m)
    {
        for (int cx = x, cy = y, ty; cx != -2; cx = prevMatch[cx], cy = ty)
        {
            ty = xy[cx];
            yx[cy] = cx;
            xy[cx] = cy;
        }
        augment();
    }
}

int hungarian()
{
    int ret = 0;
    memset(xy, -1, sizeof(xy));
    memset(yx, -1, sizeof(yx));
    init_labels();
    k = 0;
    augment();
    for (int x = 0; x < n; x++)
        ret += cost[x][xy[x]];
    return ret;
}

int main()
{
    cin >> n >> m >> k;
    memset(cost, 0, sizeof(cost));
    for (int i = 0; i < k; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--; // converting to 0-based indexing
        cost[u][v] = w;
    }
    cout << hungarian() << endl;
    return 0;
}