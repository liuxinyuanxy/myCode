#include <iostream>
#include <cstdio>
#define MOD 1000000007
using namespace std;
int a[20000002];
int ans[20000002];
int to = 2;
int main()
{
	int t, n;
	scanf("%d", &t);
	a[1] = ans[1] = 26;
	for (int i = 1; i <= t; ++i)
	{
		scanf("%d", &n);
		if (n - (int)!(n & 1) <= to)
			printf("%d\n", ans[n - (int)!(n & 1)]);
		else
		{
			for (int i = to; i <= n; ++i)
			{
				if (i & 1)
				{
					a[i] = a[i - 2] * 26 % MOD;
					ans[i] = ans[i - 2] + a[i] * i % MOD;
				}
			}
			to = n;
			printf("%d\n", ans[n - (int)!(n & 1)]);
		}
	}
	return 0;
}
