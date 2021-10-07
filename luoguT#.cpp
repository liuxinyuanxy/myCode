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
#define MOD 998244353
using namespace std;
int dp[2000000];
int two[30];
int a[2000000];
int count[2000000];
ll ans[2000000];
ll sum[2000000];
il int rd(rt k)
{
	rt s = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * k + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s;
}
int main()
{
	int n = rd(10), m = rd(10), u, v;
	for (rt i = 1; i <= m; ++i)
	{
		u = rd(2);
		v = rd(10);
		a[u] = v;
	}
	two[0] = 1;
	ans[0] = a[0];
	sum[0] = 1;
//	a[7] = 0;
	for (rt i = 1; i <= n; ++i)
		two[i] = two[i - 1] << 1;
	for (rt i = 1; i < two[n]; ++i)
		count[i] = count[i >> 1] + (i & 1);
	for (rt k = 1; k <= n; ++k)		
		for (rt i = 1; i < two[n]; ++i)
		{
			if (count[i] != k)
				continue;
			for (rt j = 0; j < two[n]; ++j)
			{
				if (i != j && ((i | j) == i))
				{
					sum[i] = (sum[i] + sum[j]) % MOD;
					ans[i] = (ans[i] + ans[j] + a[i] * sum[j]) % MOD;
				}
//				cout << i << "\t" << j << endl;
			}
		}
	printf("%lld", ans[two[n] - 1]);
	return 0;
}
