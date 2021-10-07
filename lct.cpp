#include <cstdio>
#include <iostream>
#define re register
#define rt re long long
#define rc re char
#define gc getchar
#define il inline
#define ll long long
#define _ 300000
#define mid(l, r) ((l + r) >> 1)
long long n, m, r, p;
long long cnt, tot;
long long opt, x, y, z;
long long head[_], nxt[_], to[_];
long long ed[_];
long long val[_], fa[_], dep[_], sze[_], son[_], id[_], rk[_], top[_];
namespace init
{
	il long long rd()
	{
		rt s = 0, p = 0;
		rc ch;
		while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9')
			;
		while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9')
			;
		return s * (p ? -1 : 1);
	}
	il void add(long long u, long long v)
	{
		++tot;
		to[tot] = v;
		nxt[tot] = head[u];
		head[u] = tot;
	}
	il void input()
	{
		n = rd(), m = rd(), r = rd(), p = rd();
		for (rt i = 1; i <= n; ++i)
			val[i] = rd();
		for (rt i = 1; i < n; ++i)
		{
			long long u = rd(), v = rd();
			add(u, v);
			add(v, u);
		}
	}
	il void inquery()
	{
		opt = rd();
		x = rd();
		if (opt <= 3)
		{
			y = rd();
			if (opt == 1)
				z = rd();
		}
	}
} // init

namespace fenwickTree
{
	#define lowbit(x) ((x) & -(x))
	const long long N = 1000000;
	long long tree[N];
	long long del1[N], del2[N];
	long long sum[N];
	long long tot;
	void add(long long *d, long long x, long long k)
	{
		while (x <= tot)
			d[x] = (d[x] + k + p) % p,
			x += lowbit(x);
	}
	long long query(long long* d, long long x)
	{
		long long ans = 0;
		while (x)
			ans = (ans + d[x] + p) % p,
			x -= lowbit(x);
		return ans;
	}
	//单点修改 区间查询
	void add_point_normal(long long x, long long k)
	{
		add(tree, x, k);
	}
	long long query_interval_normal(long long l, long long r)
	{
		return ((query(tree, r) - query(tree, l - 1)) % p + p) % p;
	}
	//区间修改 单点查询
	void add_interval_normal(long long l, long long r, long long k)
	{
		add(tree, l, k);
		add(tree, r + 1, p - k);
	}
	long long query_point_normal(long long x)
	{
		return query(tree, x);
	}
	//区间修改 区间查询
	void add_interval_special(long long l, long long r, long long k)
	{
		add(del1, l, k);
		add(del1, r + 1, p - k);
		add(del2, l, k * l);
		add(del2, r + 1, -k * (r + 1) % p);
	}
	long long query_interval_special(long long l, long long r)
	{
		return ((sum[r] + (r + 1) * 1ll * query(del1, r) % p - query(del2, r) - (sum[l - 1] + l * 1ll * query(del1, l - 1) % p - query(del2, l - 1))) % p + p) % p;
	}
	//代替平衡树部分操作
	long long hs[N];			//大部分情况需将操作数离散化
	void del(long long x)
	{
		--sum[x];
		add(tree, x, 1);
	}
	void insert(long long x)
	{
		++sum[x];
		add(tree, x, -1);
	}
	long long find_rank(long long x)
	{
		long long ans = 0, cnt = 0;
		for (long long i = 21; i >= 0; --i)
		{
			ans += 1 << i;
			if (ans > tot || cnt + tree[ans] >= x)
				ans -= 1 << i;
			else
				cnt += tree[ans];
		}
		return hs[ans + 1];
	}
	long long my_rank(long long x)
	{
		long long ans = 1;
		--x;
		while (x)
			ans += tree[x],
			x -= lowbit(x);
		return ans;
	}
	long long pre(long long x)
	{
		insert(x);
		long long ans = find_rank(my_rank(x) - 1);
		del(x);
		return ans;
	}
	long long nxt(long long x)
	{
		insert(x);
		long long ans = find_rank(my_rank(x) + sum[x]);
		del(x);
		return ans;
	}
} // fenwickTree

namespace lct
{
	void dfs1(long long u)
	{
		sze[u] = 1;
		for (long long i = head[u]; i; i = nxt[i])
		{
			long long v = to[i];
			if (v == fa[u])
				continue;
			dep[v] = dep[u] + 1;
			fa[v] = u;
			dfs1(v);
			sze[u] += sze[v];
			if (sze[v] > sze[son[u]])
				son[u] = v;
		}
	}
	void dfs2(long long u, long long t)
	{
		top[u] = t;
		id[u] = ++cnt;
		rk[cnt] = u;
		if (son[u])
			dfs2(son[u], t);
		for (long long i = head[u]; i; i = nxt[i])
		{
			long long v = to[i];
			if (v == fa[u] || v == son[u])
				continue;
			dfs2(v, v);
		}
		ed[u] = cnt;
	}
	void add1(long long x, long long y, long long k)
	{
		while (top[x] != top[y])
		{
			if (dep[top[x]] < dep[top[y]])
				std::swap(x, y);
			fenwickTree::add_interval_special(id[top[x]], id[x], k);
			x = fa[top[x]];
		}
		if (dep[x] < dep[y])
			std::swap(x, y);
		fenwickTree::add_interval_special(id[y], id[x], k);
	}
	long long query1(long long x, long long y)
	{
		long long ans = 0;
		while (top[x] != top[y])
		{
			if (dep[top[x]] < dep[top[y]])
				std::swap(x, y);
			ans += fenwickTree::query_interval_special(id[top[x]], id[x]);
			ans %= p;
			x = fa[top[x]];
		}
		if (dep[x] < dep[y])
			std::swap(x, y);
		ans += fenwickTree::query_interval_special(id[y], id[x]);
		ans %= p;
		return ans;
	}
	void add2(long long x, long long k)
	{
		fenwickTree::add_interval_special(id[x], ed[x], k);
	}
	long long query2(long long x)
	{
		return fenwickTree::query_interval_special(id[x], ed[x]);
	}
	il void run()
	{
		if (opt == 1)
			add1(x, y, z);
		else
			if (opt == 2)
				printf("%lld\n", query1(x, y));
			else
				if (opt == 3)
					add2(x, y);
				else
					printf("%lld\n", query2(x));
	}
} // lct

int main()
{
	cnt = 0;
	init::input();
	fenwickTree::tot = n;
	lct::dfs1(r);
	lct::dfs2(r, r);
	for (rt i = 1; i <= n; ++i)
	{
		fenwickTree::sum[i] = ((fenwickTree::sum[i - 1] + val[rk[i]]) % p + p) % p;
	}
	for (rt i = 1; i <= m; ++i)
	{
		init::inquery();
		lct::run();
	}
	return 0;
}