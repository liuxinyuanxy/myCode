#include <iostream>
#include <cstdio>
#include <algorithm>
#define gc getchar
using namespace std;
template <typename T> void rd(T& s)
{
	s = 0;
	bool p = 0;
	char ch;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	s *= (p ? -1 : 1);
}
template <typename T, typename... Args> void rd(T& s, Args&... args)
{
	rd(s);
	rd(args...);
}
int cnt, tot;
#define LL long long
#define new_node(ls, rs, val) (st[++cnt] = node(ls, rs, val), cnt)
const int MAXN = 50050;
const int MAX = 50000000;
struct node
{
	int ls, rs, add;
	LL val;
	node(int ls = 0, int rs = 0, int add = 0, LL val = 0) : ls(ls), rs(rs), add(add), val(val) {}
}st[MAX];
struct que
{
	int opt, a, b;
	LL c;
	que(int opt, int a, int b, LL c) : opt(opt), a(a), b(b), c(c) {}
	que() {}
}qu[MAXN];
int n;
LL hs[MAXN];
int tree[MAXN << 2];
void modify(int& o, int l, int r, int ll, int rr)
{
	if (!o)
		o = new_node(0, 0, 0);
	st[o].val += (r - l + 1);
	if (l == ll && r == rr)
	{
		st[o].add += 1;
		return;
	}
	int mid = (ll + rr) >> 1;
	if (r <= mid)
		modify(st[o].ls, l, r, ll, mid);
	else
		if (l > mid)
			modify(st[o].rs, l, r, mid + 1, rr);
		else
			modify(st[o].ls, l, mid, ll, mid),
			modify(st[o].rs, mid + 1, r, mid + 1, rr);
}
LL query(int o, int l, int r, int ll, int rr, int ad)
{
	// cout << o << " " << l << " " << r << " " << ll << " " << rr << " " << st[o].val << endl;
	if (!o)
		return ad * 1ll * (r - l + 1);
	if (l == ll && r == rr)
		return st[o].val + ad * 1ll * (r - l + 1);
	int mid = (ll + rr) >> 1;
	if (r <= mid)
		return query(st[o].ls, l, r, ll, mid, ad + st[o].add);
	else
		if (l > mid)
			return query(st[o].rs, l, r, mid + 1, rr, ad + st[o].add);
		else
			return query(st[o].ls, l, mid, ll, mid, ad + st[o].add) + query(st[o].rs, mid + 1, r, mid + 1, rr, ad + st[o].add);
}
void add(int o, int k, int l, int r, int ll, int rr)
{
	// cout << k << endl;
	// cout << o << " " << l << " " << r << " " << k << endl;
	modify(tree[o], l, r, 1, n);
	if (ll == rr)
		return;
	int mid = (ll + rr) >> 1;
	if (k <= mid)
		add(o << 1, k, l, r, ll, mid);
	else
		add((o << 1) | 1, k, l, r, mid + 1, rr);
}
int midsearch(int o, int ll, int rr, int l, int r, int k)
{
	if (ll == rr)
		return ll;
	LL p = query(tree[o << 1], l, r, 1, n, 0);
	// cout << o << " " << ll << " " << rr << " " << l << " " << r << " " << k << " " << p << endl;
	if (p >= k)
		return midsearch(o << 1, ll, (ll + rr) >> 1, l, r, k);
	else
		return midsearch((o << 1) | 1, ((ll + rr) >> 1) + 1, rr, l, r, k - p);
}
int main()
{
	// freopen("in.txt", "r", stdin);
	int m = 0, opt, a, b;
	// cout << 1;
	LL c;
	rd(n, m);
	// cout << n << " " << m << endl;
	for (int i = 1; i <= m; ++i)
	{
		rd(opt, a, b);
		rd(c);
		// cout << a << " " << b << " ";
		// cout << c << endl;
		qu[i] = que(opt, a, b, c);
		if (opt == 1)
			hs[++tot] = -c;
	}
	// cout << 2;
	sort(hs + 1, hs + 1 + tot);
	tot = unique(hs + 1, hs + 1 + tot) - hs - 1;
	// cout << tot << endl;
	// cout << 3;
	for (int i = 1; i <= m; ++i)
	{
		if (qu[i].opt == 1)
		{
			add(1, lower_bound(hs + 1, hs + 1 + tot, -qu[i].c) - hs, qu[i].a, qu[i].b, 1, tot);
		}
		else
		{
			printf("%lld\n", -hs[midsearch(1, 1, tot, qu[i].a, qu[i].b, qu[i].c)]);
		}
		// cout << " " << query(tree[1], 1, n, 1, n) << endl;
		// cout << endl;
	}
	return 0;
}