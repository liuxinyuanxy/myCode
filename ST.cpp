#include <iostream>
#include <cstdio>
#include <cmath>
#define MAX 1000000
#define rt register int
using namespace std;
long long k;
int t, ans[MAX][20];
int n;
int read()
{
	char ch;
	int a = 0;
	ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		a = a * 10 + ch - '0',
		ch = getchar();
	return a;
}
void done()
{
	long long p = 1;
	for (int i = 1; i <= k; ++i, p <<= 1)
	{
		for (int j = 1; j + (p << 1) - 1 <= n; ++j)
		{
			ans[j][i] = max(ans[j][i - 1], ans[j + p][i - 1]);
		}
	}
}
int main()
{
	int m;
	int l, r;
	n = read(), m = read();
	for (rt i = 1; i <= n; ++i)
		t = read(),
		ans[i][0] = t;
	k = 1;
	while (1 << (k + 1) <= n)
		++k;
	done();
	for (int i = 1; i <= m; ++i)
	{
		l = read(), r = read();
		k = 1;
		while (1 << (k + 1) <= (r - l + 1))
			++k;
		printf("%d\n", max(ans[l][k], ans[r - (1 << k) + 1][k]));
	}
	return 0;
}
