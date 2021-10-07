#include <iostream>
#include <cstdio>
#define MAX 100005
#define MOD 1000000007
#define rt register int
using namespace std;
int read()
{
	int s = 0;
	char ch;
	ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0',
		ch = getchar();
	return s;
}
int a[MAX], b[MAX], c[MAX];
int main()
{
	long long ans;
	rt n = read(), q = read(), opt, x, y;
	for (rt  i = 1; i <= n; ++i)
	{
		a[i] = read();
		c[i] = max(c[i - 1], a[i]);
	}
	for (rt i = 1; i <= n; ++i)
	{
		b[i] = read();
	}
	for (rt i = 1; i <= q; ++i)
	{
		ans = 1;
		opt = read();
		x = read();
		y = read();
		if (opt == 0)
		{
			a[x] = y;
			while (x <= n && c[x] < y)
				c[x++] = y;
		}
		else
		{
			b[x] = y;
		}
		for (rt j = 1; j <= n; ++j)
		{
			ans = ans * min(b[j], c[j]) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

