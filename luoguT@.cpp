#include <iostream>
#include <algorithm>
#include <cstdio>
#define sqr(x) ((x) * (x))
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
using namespace std;
int a[400];
ll ans = 0;
int main()
{
	int n, l, r, p;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	l = 0;
	r = n;
	p = 1; 
	while (l != r)
	{
		ans += sqr(a[r] - a[l]);
		if (!p)
			--r;
		else
			++l;
		p = !p;
	}
	printf("%lld", ans);
	return 0;
}

