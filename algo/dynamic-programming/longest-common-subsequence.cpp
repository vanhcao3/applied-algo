#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestCommonSubsequence(vector<int> &X, vector<int> &Y)
{
    int n = X.size(), m = Y.size();
    vector<int> dp(m + 1, 0);
    int prev;

    for (int i = 1; i <= n; ++i)
    {
        prev = 0;
        for (int j = 1; j <= m; ++j)
        {
            int temp = dp[j];
            if (X[i - 1] == Y[j - 1])
                dp[j] = prev + 1;
            else
                dp[j] = max(dp[j], dp[j - 1]);
            prev = temp;
        }
    }

    return dp[m];
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> X(n), Y(m);
    for (int i = 0; i < n; ++i)
        cin >> X[i];
    for (int i = 0; i < m; ++i)
        cin >> Y[i];

    int result = longestCommonSubsequence(X, Y);
    cout << result << endl;

    return 0;
}
