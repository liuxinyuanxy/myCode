#include <iostream>
#include <cstdio>
#include <algorithm>
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
#define tru(x) (hs[(x)])
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
using namespace std;
typedef pair<double, double> P;
typedef pair<P, P> ma;
ma mat[20000];
struct EDGE{
	int l, r, x;
	int val;
}edge[100000];
struct node{
	int l, r;
	int tag;
	double len;
}tree[100000];
int n;
double hs[100000];
bool cmp(EDGE a, EDGE b)
{
	return a.x < b.x;
}
void build(rt l, rt r, rt i)
{
	tree[i].l = l;
	tree[i].r = r;
	tree[i].len = tree[i].tag = 0;
	if (l == r - 1)
		return;
	build(l, mid(l, r), ls(i));
	build(mid(l, r), r, rs(i));
}
il void updata(rt i)
{
	if (tree[i].tag > 0)
		tree[i].len = tru(tree[i].r) - tru(tree[i].l);
	else
		if (tree[i].r == tree[i].l + 1)
			tree[i].len = 0;
		else
			tree[i].len = tree[ls(i)].len + tree[rs(i)].len;
}
void add(rt l, rt r, rt v, rt i)
{
	if (tree[i].l == l && tree[i].r == r)
	{
		tree[i].tag += v;
		updata(i); 
		return;
	}
	rt m = mid(tree[i].l, tree[i].r);
	if (m <= l)
		add(l, r, v, rs(i));
	else
		if (m >= r)
			add(l, r, v, ls(i));
		else
			add(l, m, v, ls(i)),
			add(m, r, v, rs(i));
	updata(i); 
}
int main()
{
	double ans = 0;
	int NOW = 0;
	while (sf(n), n != 0)
	{
		ans = 0;
		rt tot = 0;
		rep (i, 1, n)
			scanf ("%lf%lf%lf%lf", &mat[i].first.first, &mat[i].first.second, &mat[i].second.first, &mat[i].second.second),
			hs[++tot] = mat[i].first.first,
			hs[++tot] = mat[i].first.second,
			hs[++tot] = mat[i].second.first,
			hs[++tot] = mat[i].second.second;
		sort(hs + 1, hs + tot + 1);
		tot = unique(hs + 1, hs + tot + 1) - (hs + 1);
		rt cnt = 0;
		build(1, tot, 1);
		rep (i, 1, n)
			edge[++cnt].val = 1,
			edge[cnt + 1].l = edge[cnt].l = lower_bound(hs + 1, hs + tot + 1, mat[i].first.second) - hs,
			edge[cnt + 1].r = edge[cnt].r = lower_bound(hs + 1, hs + tot + 1, mat[i].second.second) - hs,
			edge[cnt].x = lower_bound(hs + 1, hs + tot + 1, mat[i].first.first) - hs,
			edge[++cnt].x = lower_bound(hs + 1, hs + tot + 1, mat[i].second.first) - hs,
			edge[cnt].val = -1;
		sort(edge + 1, edge + 1 + cnt, cmp);
		rep (i, 1, cnt)
		{
			ans += (tru(edge[i].x) - tru(edge[i - 1].x)) * tree[1].len;
			add(edge[i].l, edge[i].r, edge[i].val, 1);
		}
		printf("Test case #%d\n", ++NOW);
		printf("Total explored area: %.2lf\n", ans);
		puts("");
	}	
	return 0;
}

