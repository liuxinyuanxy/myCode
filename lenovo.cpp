#include <iostream>
#include <cstdio>
#define sf(x) scanf ("%d", &x)
#define sf2(x, y) scanf ("%d%d", &x, &y)
#define sf3(x, y, z) scanf ("%d%d%d", &x, &y, &z)
#define pf(x) printf ("%d", x)
#define pf2(x, y) printf("%d%d", x, y)
#define pf3(x, y, z) printf("%d%d%d", x, y, z)
#define sfl(x) scanf ("%lld", &x)
#define sfl2(x, y) scanf ("%lld%lld", &x, &y)
#define sfl3(x, y, z) scanf ("%lld%lld%lld", &x, &y, &z)
#define pfl(x) printf ("%lld", x)
#define pfl2(x, y) printf("%lld%lld", x, y)
#define pfl3(x, y, z) printf("%lld%lld%lld", x, y, z)
#define rep(i, a, b) for (rt i = (a); i <= (b); ++i)
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define p_q priority_queue
#define pii pair <int, int>
#define piii pair <pii, int>
#define piiii pair <pii, pii>
#define pll pair <ll, ll>
#define plll pair <pll, ll>
#define pllll pair <pll, pll>
#define ls(i) ((i) << 1)
#define rs(i) ((i) << 1 | 1)
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
struct node{
	int l, r;
	ll val, lzy, sum;
	bool nd;
}tree[4000000];
ll del[1000000], a[1000000];
il ll rd()
{
	rll s = 0, p = 1; rc ch;
	while (ch = gc(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') p = -1, ch = gc();
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s * p;
}
ll gcd(rll a, rll b)
{
	return b ? gcd(b, a % b) : a;
}
il void updata(rt i)
{
	tree[i].val = gcd(tree[ls(i)].val, tree[rs(i)].val);
}
void build(rt l, rt r, rt i)
{
	tree[i].l = l,
	tree[i].r = r;
	if (l == r)
	{
		tree[i].val = rd();
		return;
	}
	build(l, mid(l, r), ls(i));
	build(mid(l, r) + 1, r, rs(i));
	updata(i);
}
il void downdata(rt i)
{
	if (tree[i].lzy)
	{
		tree[ls(i)].lzy += tree[i].lzy;
		tree[rs(i)].lzy += tree[i].lzy;
		tree[ls(i)].nd = tree[rs(i)].nd = 1;
		tree[i].lzy = 0;
	}
}
void change(rt l, rt r, rt i, rt w)
{
	tree[i].nd = 1;
	if (tree[i].l == l && tree[i].r == r)
	{
		tree[i].lzy += w;
		return;
	}
	rt m = mid(tree[i].l, tree[i].r);
	if (m < l)
		change(l, r, rs(i), w);
	else
		if (m >= r)
			change(l, r, ls(i), w);
		else
			change(l, m, ls(i), w),
			change(m + 1, r, rs(i), w);
}
ll query(rt l, rt r, rt i)
{
	if (l == r)
	{
		tree[i].val += tree[i].lzy;
		tree[i].lzy = 0;
	}
	downdata(i);
	if (tree[i].l == l && tree[i].r == r)
		return ask(i);
	rt m = mid(tree[i].l, tree[i].r);
	if (m < l)
		return query(l, r, rs(i));
	else
		if (m >= r)
			return query(l, r, ls(i));
		else
			return gcd(query(l, m, ls(i)), query(m + 1, r, rs(i)));
}
int main()
{
	rt n = rd(), m = rd(), l, r;
	rll d;
	rc ch;
	rep (i, 1, n)
	{
		a[i] = rd();
		del[i] = a[i] - a[i - 1];
	}
	build(1, n, 1);
	rep (i, 1, m)
	{
		while (ch = gc(), ch != 'Q' && ch != 'C');
		l = rd(), r = rd();
		if (ch == 'Q')
			pfl(query(l, r, 1)),
			putchar('\n');
		else
		{
			d = rd();
			change(l, r, 1, d);
		}
	}
	return 0;
}
