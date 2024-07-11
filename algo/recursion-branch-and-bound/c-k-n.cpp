// C/C++
#include <bits/stdc++.h>
using namespace std;
const int X = 1E9 + 7;

int a[1000][1000];

int C(int k, int n)
{
    if (k == 0 || k == n)
    {
        a[k][n] = 1;
    }
    else if (k == 1)
    {
        a[k][n] = n;
    }
    else
    {
        if (a[k][n] < 0)
            a[k][n] = (C(k - 1, n - 1) % X + C(k, n - 1) % X) % X;
    }
    return a[k][n];
}

int main()
{
    int k, n;
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            a[i][j] = -1;
    cin >> k >> n;
    cout << C(k, n) << endl;
}
