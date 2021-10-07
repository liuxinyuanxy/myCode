#include <iostream>
#include <cstdio>
#define MOD 1000000007 
#define ll long long
using namespace std;
struct node{
	int n, m;
	ll ma[200][200];
};
node operator * (const node& a, const node& b)
{
	node c;
	c.n = a.n;
	c.m = b.m;
	for (int i = 1; i <= c.n; ++i)
	{
		for (int j = 1; j <= c.m; ++j)
		{
			c.ma[i][j] = 0;
		}
	}
	for (int i = 1; i <= c.n; ++i)
	{
		for (int j = 1; j <= c.m; ++j)
		{
			for (int k = 1; k <= a.m; ++k)
			{
				c.ma[i][j] += a.ma[i][k] * b.ma[k][j] % MOD;
				c.ma[i][j] %= MOD;
			}
		}
	}
	return c;
}
int main()
{ 
	int n;
	ll k;
	node t, s;
	scanf ("%d%lld", &n, &k);
	t.n = t.m = s.m = s.n = n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			s.ma[i][j] = t.ma[i][j] = 0;
	for (int i = 1; i <= n; ++i)
		s.ma[i][i] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf ("%lld", &t.ma[i][j]);
	for (; k; k >>= 1, t = t * t)
		if (k & 1)
			s = s * t;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			printf("%lld ", s.ma[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
