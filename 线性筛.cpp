#include <iostream>
#include <cstdio>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define _ 10000002
using namespace std;
int prime[_], primecnt;
int phi[_], vis[_];
int main()
{
	int n, m;
	scanf ("%d%d", &n, &m);
	vis[1] = 1;
	for (rt i = 2; i <= n; ++i)
	{
		if (!vis[i])
		{
			prime[++primecnt] = i;
			phi[i] = i - 1;
		}
		for (rt j = 1; j <= primecnt && prime[j] * i <= n; ++j)
		{
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)
			{
				phi[i * prime[j]] = prime[j] * phi[i];
				break;
			}
			phi[i * prime[j]] = phi[i] * phi[prime[j]];
		}
	}
	rt q;
	for (rt i = 1; i <= m; ++i)
	{
		scanf ("%d", &q);
		puts(vis[q] ? "No" : "Yes");
	}
	return 0;
}


