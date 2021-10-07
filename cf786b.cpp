#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
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
#define _ 100005
#define pll pair <ll, ll>
#define plll pair <pll, ll>
#define pllll pair <pll, pll>
#define add(u, v, w) edge[u].push_back(mp(v, w))
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
vector<pll> edge[_ << 4];
ll dis[10000000];
bool done[10000000];
ll tot = 0;
bool k;
p_q<pll, vector<pll>, greater<pll> > pq; 
struct node{
	int l, r;
	ll cnt;
	node* ls;
	node* rs;
}leaf[_];
node* treeIn,* treeOut;
// v -> u
il void add1(rt v, rt u, rt w)
{
	add(leaf[v].cnt, leaf[u].cnt, w);
}
// v -> [l, r]
il void add2(rt v, rt l, rt r, rt w, node* p)
{
	if (p->l == l && p->r == r)
	{
		add(leaf[v].cnt, p->cnt, w);
		return;
	}
	rt m = mid(p->l, p->r);
	if (l > m)
		add2(v, l, r, w, p->rs);
	else
		if (r <= m)
			add2(v, l, r, w, p->ls);
		else
			add2(v, l, m, w, p->ls),
			add2(v, m + 1, r, w, p->rs);
}
// [l, r] -> v
il void add3(rt v, rt l, rt r, rt w, node* p)
{
	if (p->l == l && p->r == r)
	{
		add(p->cnt, leaf[v].cnt, w);
		return;
	}
	rt m = mid(p->l, p->r);
	if (l > m)
		add3(v, l, r, w, p->rs);
	else
		if (r <= m)
			add3(v, l, r, w, p->ls);
		else
			add3(v, l, m, w, p->ls),
			add3(v, m + 1, r, w, p->rs);
}
node* build(rt l, rt r)
{
	if (l == r)
	{
		return &leaf[l];
	}
	++tot;
	node* p = new node;
	p->l = l, p->r = r;
	p->cnt = tot;
	p->ls = build(l, mid(l, r));
	p->rs = build(mid(l, r) + 1, r);
	k ? (add(p->ls->cnt, p->cnt, 0), add(p->rs->cnt, p->cnt, 0)) : (add(p->cnt, p->ls->cnt, 0), add(p->cnt, p->rs->cnt, 0));
	return p;
}
int main()
{
	rt n, q, s, opt, v, l, r, w, id;
	sf(n),
	sf2(q, s);
	rep (i, 1, n)
		leaf[i].l = leaf[i].r = i,
		leaf[i].cnt = i,
		leaf[i].ls = leaf[i].rs = NULL;
	tot = n + 1;
	k = 0;
	treeIn = build(1, n);
	k = 1;
	treeOut = build(1, n);
	while (q--)
	{
		sf3(opt, v, l),
		sf(r);
		if (opt == 1)
			add1(v, l, r);
		else
		{
			sf(w);
			if (opt == 2)
				add2(v, l, r, w, treeIn);
			else
				add3(v, l, r, w, treeOut);
		}
	}
//	rep (i, 1, tot)
//	{
//		cout << i << ":";
//		for (auto& x : edge[i])
//			cout << x.first << " " << x.second << "\t";
//		cout << endl;
//	}
	pll temp;
	dis[s] = 1;
	pq.push(mp(1, s));
	while (!pq.empty())
	{
		temp = pq.top();
		pq.pop();
		w = temp.first;
		id = temp.second;
		if (done[id])
			continue;
		done[id] = 1;
		for (const auto& x : edge[id])
		{
			if (done[x.first])
				continue;
			if (!dis[x.first] || dis[x.first] > dis[id] + x.second)
			{
				dis[x.first] = dis[id] + x.second;
				pq.push(mp(dis[x.first], x.first));
			}
		}
	}
	rep (i, 1, n)
	{
		pfl(dis[i] - 1);
		putchar(' ');
	}
	return 0;
}
