#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define il inline
#define re register
#define ll long long
#define rt register int
#define rc register char
#define rll register long long
#define pf(x) printf("%d", x)
#define pf2(x, y) printf("%d %d", x, y)
#define sf(x) scanf ("%d", &x)
#define sf2(x, y) scanf ("%d%d", &x, &y)
#define pfl(x) printf("%lld", x)
#define pfl2(x, y) printf("%lld%lld", x, y)
#define sfl(x) scanf ("%lld", &x)
#define sfl2(x, y)	scanf ("%lld%lld", &x, &y)
#define jia(a, b) (((a) + (b)) % MOD)
#define jian(a, b) (((a) - (b)) % MOD)
#define cheng(a, b) (((a) * (b)) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfjian(a, b) (a) = ((a) - (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b)) % MOD
#define selfmax(x, y) (x) = max((x), (y))
#define mid(x, y) (((x) + (y)) >> 1)
#define m_p make_pair
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
typedef vector<int>::iterator vi;
int blo;
int n, m;
int a[100005];
int st[100005];
vector<int> v[10000];
pii pos(rt x)
{
	rt d = 1;
	while (v[d].size() < x)
		x -= v[d].size(), ++d;
	return m_p(d, x - 1);
}
il void reset()
{
	rt top = 0;
	rep (i, 1, m)
	{
		for (vi j = v[i].begin(); j != v[i].end(); ++j)
			st[++top] = *j;
		v[i].clear();
	}
	blo = sqrt(top);
	rep (i, 1, top)
		v[(i - 1) / blo + 1].push_back(st[i]);
	m = (n - 1) / blo + 1;
}
il void change(rt l, rt c)
{
	pii t = pos(l);
	v[t.first].insert(v[t.first].begin() + t.second, c);
	if (v[t.first].size() > blo * 5)
		reset();
}
il void query(rt r)
{
	pii t = pos(r);
	pf(v[t.first][t.second]);
	putchar('\n');
}
int main()
{
	rt opt, l, r, c;
	sf(n);
	blo = sqrt(n);
	rep(i, 1, n)
		sf(a[i]),
		v[(i - 1) / blo + 1].push_back(a[i]);
	m = (n - 1) / blo + 1;
	rep (i, 1, n)
	{
		sf2(opt, l),
		sf2(r, c);
		if (opt)
			query(r);
		else
			change(l, r);
	}
	return 0;
}

