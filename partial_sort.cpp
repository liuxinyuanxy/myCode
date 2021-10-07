#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
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
il int rd()
{
	rt s = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s;
}
int a[200000000];
int main()
{
	freopen("in.txt","r", stdin);
	ll ans = 0;
	rt n, p;
	n = rd(), p = rd();
	for (rt i = 1; i <= n; ++i)
		a[i] = rd();
	partial_sort(a + 1, a + 1 + p, a + 1 + n);
	for (rt i = 1; i <= p; ++i)
		ans += a[i];
	printf("%lld", ans);
	return 0;
}


