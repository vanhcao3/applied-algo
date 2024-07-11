// C++
#include <bits/stdc++.h>
using namespace std;
int n, a[32] = {0};
bool m[32] = {false};

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void Try(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (!m[i])
        {
            a[k] = i;
            m[i] = true;
            if (k == n)
                solution();
            else
                Try(k + 1);
            m[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    Try(1);
    return 0;
}
