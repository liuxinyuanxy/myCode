#include <iostream>
#include <cstdio>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define lowbit(x) ((x) & -(x))
#define _ 100005
#define MOD 1000000007
using namespace std;
ll a1[_], a2[_];
ll tree1[_], tree2[_];
il ll rd()
{
	rll s = 0, p = 1; rc ch;
	while (ch = gc(), ch !='-' && (ch < '0' || ch > '9'));
	if (ch == '-') p = -1, ch = gc();
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s * p;
}
il ll qpow(rll a, rll b, rll m)
{
	rll s = 1;
	for (; b; b >>= 1, a = a * a % m)
		if (b & 1)
			s = s * a % m;
	return s;
}
int n = rd(), m = rd();
il void add(ll* tree, rll x, rll y)
{
	while (x <= n)
		tree[x] = (tree[x] + y + MOD) % MOD,
		x += lowbit(x);
}
il ll query(ll* tree, rll x)
{
	rll s = 0;
	while (x)
		s = (s + tree[x] + MOD) % MOD,
		x -= lowbit(x);
	return s;
}
il void ask(rll x, rll y)
{
	rll len = y - x + 1;
	rll s = (query(tree1, y) - query(tree1, x - 1) + MOD) % MOD;
	rll _a = (s * (qpow(len, MOD - 2, MOD)) % MOD + MOD) % MOD;
	rll ans = (((query(tree2, y) - query(tree2, x - 1) + MOD) % MOD - 2 * _a * s + MOD) % MOD + (_a * _a % MOD * len) % MOD + MOD) % MOD;
	ans = ((ans * qpow(len, MOD - 2, MOD)) % MOD + MOD) % MOD;
	printf("%lld\n", ans);
}
int main()
{
	rll c, x, y;
	for (rt i = 1; i <= n; ++i)
	{
		a1[i] = rd();
		a2[i] = (a1[i] * a1[i]) % MOD;
		add(tree1, i, a1[i]);
		add(tree2, i, a2[i]);
	}
	for (rt i = 1; i <= m; ++i)
	{
		c = rd(), x = rd(), y = rd();
		if (c == 1)
			y %= MOD,
			add(tree1, x, -a1[x]),
			add(tree2, x, -a2[x]),
			add(tree1, x, y),
			add(tree2, x, (y * y) % MOD),
			a1[x] = y,
			a2[x] = (y * y) % MOD;
		else
			ask(x, y);
	}
	return 0;
}


