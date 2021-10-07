#include <iostream>
#include <cstdio>
#define ll long long
#define MAX 1000000
using namespace std;
ll s1[MAX], s2[MAX];
ll a[MAX];
ll n, m;
inline ll lowbit(ll x)
{
	return x & -x;
}
inline void add(ll* s, ll p, ll x)
{
	while (p <= n)
		s[p] += x,
		p += lowbit(p);
}
inline void change(ll l, ll r, ll x)
{
	add(s1, l, x),
	add(s1, r + 1, -x),
	add(s2, l, x * l),
	add(s2, r + 1, -x * (r + 1));
}
inline ll ask(ll* d, ll x)
{
	ll s = 0;
	while (x)
		s += d[x],
		x -= lowbit(x);
	return s;
}
inline ll query(ll l, ll r)
{
	return (a[r] + (r + 1) * ask(s1, r) - ask(s2, r)) - (a[l - 1] + l * ask(s1, l - 1) - ask(s2, l - 1));
}
int main()
{
	ll x, y, k, p;
	scanf ("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; ++i)
	{
		scanf ("%lld", &p);
		a[i] = a[i - 1] + p;
	}
	for (ll i = 1; i <= m; ++i)
	{
		scanf ("%lld%lld%lld", &p, &x, &y);
		if (p == 1)
		{
			scanf ("%lld", &k);
			change(x, y, k);
		}
		else
		{
			printf("%lld\n", query(x, y));
		}
	}
	return 0;
}

