// C++
#include <bits/stdc++.h>
using namespace std;
int n, a[32];

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    cout << "\n";
}

void Try(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        if (a[k - 1] + i < 2)
        {
            a[k] = i;
            if (k == n)
                solution();
            else
                Try(k + 1);
        }
    }
}

int main()
{
    cin >> n;
    Try(1);
}
