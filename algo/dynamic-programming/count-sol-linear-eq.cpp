#include <bits/stdc++.h>
using namespace std;

int count_sol(vector<int> &a, int m, int n)
{
    vector<int> dp(m + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = a[i]; j <= m; j++)
            dp[j] += dp[j - a[i]];
    }

    return dp[m];
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int count = count_sol(a, m, n);

    cout << count << endl;

    return 0;
}
