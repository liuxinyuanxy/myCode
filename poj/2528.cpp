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
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
struct node{
	int l, r, val, tag;
	node* ls, *rs;
}*tree = NULL;
int hs[400005];
pii point[10005];
bool cnt[400005];
node* build(rt l, rt r)
{
	node* p = new node;
	p->l = l, p->r = r;
	p->tag = p->val = 0;
	p->ls = p->rs = NULL;
	if (l == r)
		return p;
	p->ls = build(l, mid(l, r));
	p->rs = build(mid(l, r) + 1, r);
	return p;
}
void clear(node* p)
{
	if (p == NULL)
		return;
	clear(p->ls);
	clear(p->rs);
	delete(p);
}
il void downdata(node* p)
{
	if (!p->tag)
		return;
	if (p->l == p->r)
		return;
	p->ls->val = p->rs->val = p->tag;
	p->ls->tag = p->rs->tag = p->tag;
	p->tag = 0;
}
void change(rt l, rt r, rt w, node* p)
{
	downdata(p);
	if (p->l == l && p->r == r)
	{
		p->val = p->tag = w;
		return;
	}
	rt m = mid(p->l, p->r);
	if (m < l)
		change(l, r, w, p->rs);
	else
		if (m >= r)
			change(l, r, w, p->ls);
		else
			change(l, m, w, p->ls),
			change(m + 1, r, w, p->rs);
}
int query(rt x, node* p)
{
	downdata(p);
	if (p->l == p->r)
		return p->val;
	rt m = mid(p->l, p->r);
	if (m >= x)
		return query(x, p->ls);
	else
		return query(x, p->rs);
}
int main()
{
	rt tot;
	rt t, n;
	sf(t);
	tree = NULL;
	while (t--)
	{
		tot = 0;
		rt ans = 0;
		clear(tree);
		sf(n);
		rep (i, 1, n)
			sf2(point[i].first, point[i].second),
			hs[++tot] = point[i].first,
			hs[++tot] = point[i].second; 
//			hs[++tot] = point[i].first + 1,
//			hs[++tot] = point[i].second - 1;
		sort(hs + 1, hs + 1 + tot);
		tot = unique(hs + 1, hs + tot + 1) - (hs + 1);
		tree = build(1, tot);
		rep (i, 1, n)
		{
			point[i].first = lower_bound(hs + 1, hs + tot + 1, point[i].first) - (hs),
			point[i].second = lower_bound(hs + 1, hs + tot + 1, point[i].second) - (hs);
		}
		rep (i, 1, n)
		{
			change(point[i].first, point[i].second, i, tree);
		}
		rep (i, 1, tot)
			cnt[query(i, tree)] = 1;
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

