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
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
int MIN, MAX;
ll ans;
int main()
{
	int n, p, l1, l2; 
	scanf ("%d", &n);
	scanf ("%d", &p);
	MIN = MAX = p;
	l1 = l2 = 1;
	for (rt i = 2; i <= n; ++i)
	{
		scanf ("%d", &p);
		if (p < MIN)
		{
			MIN = p;
			l1 = i;
			if (l1 > l2)
			{
				MAX = p;
			}
		}
		if (p > MAX)
		{
			MAX = p;
			l2 = i;
		}
		ans = max(ans, MAX - MIN);
	}
	printf("%lld", ans);
	return 0;
}


