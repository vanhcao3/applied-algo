#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 20;
int N, M;
vector<vector<int>> adj(MAXN, vector<int>(MAXN, 0));
vector<vector<int>> laplacian(MAXN, vector<int>(MAXN, 0));

void createLaplacianMatrix()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i == j)
            {
                laplacian[i][j] = adj[i][j];
            }
            else
            {
                laplacian[i][j] = -adj[i][j];
                laplacian[i][i] += adj[i][j];
            }
        }
    }
}

int determinant(vector<vector<int>> matrix, int n)
{
    int det = 0;
    if (n == 1)
    {
        return matrix[0][0];
    }
    vector<vector<int>> submatrix(n - 1, vector<int>(n - 1));
    int sign = 1;
    for (int x = 0; x < n; x++)
    {
        int subi = 0;
        for (int i = 1; i < n; i++)
        {
            int subj = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == x)
                    continue;
                submatrix[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }
        det += sign * matrix[0][x] * determinant(submatrix, n - 1);
        sign = -sign;
    }
    return det;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v; // Adjusting for 0-based indexing
        adj[u][v]++;
        adj[v][u]++;
    }
    createLaplacianMatrix();
    cout << abs(determinant(laplacian, N - 1)) << endl;
    return 0;
}