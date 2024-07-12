#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
const int K = 25; // K should be chosen such that 2^K >= MAXN
int lg[MAXN + 1];
int st[MAXN][K + 1];
int a[MAXN];

void preprocess(int n)
{
	lg[1] = 0;
	for (int i = 2; i <= MAXN; i++)
		lg[i] = lg[i / 2] + 1;

	for (int i = 0; i < n; i++)
		st[i][0] = a[i];

	for (int j = 1; j <= K; j++)
		for (int i = 0; i + (1 << j) <= n; i++)
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int L, int R)
{
	int j = lg[R - L + 1];
	return min(st[L][j], st[R - (1 << j) + 1][j]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	preprocess(n);

	cin >> m;
	long long sumQ = 0;
	for (int i = 0; i < m; i++)
	{
		int L, R;
		cin >> L >> R;
		sumQ += query(L, R);
	}

	cout << sumQ << "\n";
	return 0;
}