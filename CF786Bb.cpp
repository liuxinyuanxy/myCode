#include <algorithm>
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
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
struct node{
	int l, r, val, tag;
}tree[400005];
int hs[400005];
pii point[10005];
bool cnt[400005];
void build(rt l, rt r, rt i)
{
	tree[i].l = l, tree[i].r = r;
	tree[i].tag = tree[i].val = 0;
	if (l == r)
		return;
	build(l, mid(l, r), ls(i));
	build(mid(l, r) + 1, r, rs(i));
}
il void downdata(int p)
{
	if (!tree[p].tag)
		return;
	if (tree[p].l == tree[p].r)
		return;
	tree[ls(p)].val = tree[rs(p)].val = tree[ls(p)].tag = tree[rs(p)].tag = tree[p].tag;
	tree[p].tag = 0;
}
void change(rt l, rt r, rt w, rt p)
{
	downdata(p);
	if (tree[p].l == l && tree[p].r == r)
	{
		tree[p].val = tree[p].tag = w;
		return;
	}
	rt m = mid(tree[p].l, tree[p].r);
	if (m < l)
		change(l, r, w, rs(p));
	else
		if (m >= r)
			change(l, r, w, ls(p));
		else
			change(l, m, w, ls(p)),
			change(m + 1, r, w, rs(p));
}
int query(rt x, rt p)
{
	downdata(p);
	if (tree[p].l == tree[p].r)
		return tree[p].val;
	rt m = mid(tree[p].l, tree[p].r);
	if (m >= x)
		return query(x, ls(p));
	else
		return query(x, rs(p));
}
int main()
{
	rt tot;
	rt t, n;
	sf(t);
	while (t--)
	{
		tot = 0;
		rt ans = 0;
		sf(n);
		rep (i, 1, n)
			sf2(point[i].first, point[i].second),
			hs[++tot] = point[i].first,
			hs[++tot] = point[i].second,
			hs[++tot] = point[i].first + 1,
			hs[++tot] = point[i].second - 1;
		sort(hs + 1, hs + 1 + tot);
		tot = unique(hs + 1, hs + tot + 1) - (hs + 1);
		build(1, tot, 1);
		rep (i, 1, n)
		{
			point[i].first = lower_bound(hs + 1, hs + tot + 1, point[i].first) - (hs),
			point[i].second = lower_bound(hs + 1, hs + tot + 1, point[i].second) - (hs);
		}
		rep (i, 1, n)
		{
			change(point[i].first, point[i].second, i, 1);
		}
		rep (i, 1, tot)
			cnt[query(i, 1)] = 1;
		rep (i, 1, n)
		{
//			cout << i << "\t" << cnt[i] << endl;
			ans += cnt[i],
			cnt[i] = 0;
		}
		pf(ans);
		putchar('\n');
	}
	return 0;
}

