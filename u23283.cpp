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
	int l, r;
	ll val;
	node* ls,* rs,* fa;
}*tree, *leave[500005];
ll gcd(rll a, rll b)
{
	return !b ? a : gcd(b, a % b);
}
node* build(rt l, rt r, node* fa)
{
	node* p = new node;
	p->l = l, p->r = r;
	p->fa = fa;
	if (l == r)
	{
		leave[l] = p;
		p->ls = p->rs = NULL;
		sfl(p->val);
		return p;
	}
	p->ls = build(l, mid(l, r), p);
	p->rs = build(mid(l, r) + 1, r, p);
	p->val = gcd(p->ls->val, p->rs->val);
	return p;
}
il void updata(node* x)
{
	x->val = gcd(x->ls->val, x->rs->val);
}
il void change(node* p)
{
	if (p == NULL)
		return;
	updata(p);
	change(p->fa);
}
il int check(rll x, node* p)
{
	if (p->val % x == 0)
		return 0;
	if (p->l == p->r)
		return 1;
	if (p->ls->val % x == 0)
		return check(x, p->rs);
	if (p->rs->val % x == 0)
		return check(x, p->ls);
	return 2;
}
int query(rt l, rt r, rll x, node* p)
{
	if (p->l == l && p->r == r)
		return check(x, p);
	rt m = mid(p->l, p->r);
	if (m < l)
		return query(l, r, x, p->rs);
	else
		if (m >= r)
			return query(l, r, x, p->ls);
		else
			return query(l, m, x, p->ls) + query(m + 1, r, x, p->rs);
}
int main()
{
	rc opt;
	rt n, q, l, r;
	rll x;
	sf2(n, q);
	tree = build(1, n, NULL);
	while (q--)
	{
		cin >> opt;
		sf2(l, r);
		if (opt == 'G')
		{
			sfl(x);
			puts(query(l, r, x, tree) <= 1 ? "mia" : "aimu");
		}
		else
		{
			leave[l]->val = r;
			change(leave[l]->fa);
		}
	}
	return 0;
}

