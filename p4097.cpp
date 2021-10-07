#include <iostream>
#include <cstdio>
#include <cmath>
#define gc getchar
#define re register
#define il inline
using namespace std;
const int MOD = 39989;
template <typename T> void rd(T& s)
{
	s = 0;
	char ch;
	bool p = 0;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	s *= (p ? -1 : 1);
}
template <typename T, typename... Args> void rd(T& s, Args&... args)
{
	rd(s);
	rd(args...);
}
const int MAX = 40000;
int cnt = 0;
struct node
{
	int l, r;
	int id;
}tree[MAX << 4];
struct segment
{
	int l, r, yl, yr;
	double k()
	{
		return (double)(yr - yl) / (r - l);
	}
	segment(int l, int r, int yl, int yr) : l(l), r(r), yl(yl), yr(yr) {}
	segment() {}
}se[MAX];
void build(int l, int r, int o)
{
	tree[o].l = l;
	tree[o].r = r;
	tree[o].id = 0;
	if (l != r)
		build(l, (l + r) >> 1, o << 1), build(((l + r) >> 1) + 1, r, (o << 1) | 1);
}
double get_y(int id, int x)
{
	if (se[id].l == se[id].r)
		return max(se[id].yl, se[id].yr);
	return se[id].yl + se[id].k() * (x - se[id].l);
}
void updata(re int id, re int o)
{
	if (!tree[o].id)
	{
		tree[o].id = id;
		return;
	}
	int mid = (tree[o].l + tree[o].r) >> 1;
	if (get_y(id, mid) > get_y(tree[o].id, mid))
	{
		if (tree[o].l != tree[o].r)
			get_y(id, tree[o].l) > get_y(tree[o].id, tree[o].l) ? updata(tree[o].id, (o << 1) | 1) : updata(tree[o].id, o << 1);
		tree[o].id = id;
	}
	else
	{
		if (tree[o].l != tree[o].r)
			get_y(id, tree[o].l) > get_y(tree[o].id, tree[o].l) ? updata(id, o << 1) : updata(id, (o << 1) | 1);
	}
}
void modify(re int id, re int o, re int l, re int r)
{
	if (tree[o].l == l && tree[o].r == r)
	{
		updata(id, o);
		return;
	}
	int mid = (tree[o].l + tree[o].r) >> 1;
	if (r <= mid)
		modify(id, o << 1, l, r);
	else
		if (l > mid)
			modify(id, (o << 1) | 1, l, r);
		else
			modify(id, o << 1, l, mid),
			modify(id, (o << 1) | 1, mid + 1, r);
}
void query(int k, int o, double ans, int& a)
{
	double p = get_y(tree[o].id, k);
	if (p > ans)
	{
		ans = p;
		a = tree[o].id;
	}
	else
		if (fabs(p - ans) <= 1e-8 && tree[o].id < a)
			a = tree[o].id;
	if (tree[o].r != tree[o].l)
		query(k, k <= ((tree[o].r + tree[o].l) >> 1) ? o << 1 : (o << 1) | 1, ans, a);
}
int main()
{
	int n, lst = 0, opt, k, x0, y0, x1, y1, ans;
	build(1, 39989, 1);
	rd(n);
	for (int i = 1; i <= n; ++i)
	{
		rd(opt);
		if (!opt)
		{
			rd(k);
			k = ((lst + k - 1) % MOD + 1);
			ans = 0;
			query(k, 1, 0, ans);
			printf("%d\n", lst = ans);
		}
		else
		{
			rd(x0, y0, x1, y1);
			x0 = ((lst + x0 - 1) % MOD + 1);
			y0 = ((lst + y0 - 1) % 1000000000 + 1);
			x1 = ((lst + x1 - 1) % MOD + 1);
			y1 = ((lst + y1 - 1) % 1000000000 + 1);
			if (x1 < x0)
				swap(x1, x0),
				swap(y1, y0);
			se[++cnt] = segment(x0, x1, y0, y1);
			modify(cnt, 1, x0, x1);
		}
	}
	return 0;
}