#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

// Returns number of ways to write n as sum of
// two or more positive integers
long long countWays(int n)
{
    // table[i] will be storing the number of
    // solutions for value i. We need n+1 rows
    // as the table is constructed in bottom up
    // manner using the base case (n = 0)
    long long table[n + 1];

    // Initialize all table values as 0
    memset(table, 0, sizeof(table));

    // Base case (If given value is 0)
    table[0] = 1;

    // Pick all integer one by one and update the
    // table[] values after the index greater
    // than or equal to n
    for (int i = 1; i < n; i++)
        for (int j = i; j <= n; j++)
            table[j] = (table[j] + table[j - i]) % MOD;

    return table[n];
}

// Driver program
int main()
{
    int n;
    cin >> n;
    cout << (countWays(n) + 1) % MOD;
    return 0;
}
