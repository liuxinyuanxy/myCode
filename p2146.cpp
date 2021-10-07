#include <iostream>
#include <cstdio>
#include <cctype>
#define il inline
#define _ 1000000

using namespace std;

int opt, k;
int cnt;
int head[_], to[_], nxt[_];
int sze[_], son[_], fa[_], dep[_], top[_], id[_], rk[_];
char ch[_];

namespace init
{
	int rd()
	{
		int s = 0, p = 0;
		char ch;
		while (ch = getchar(), p |= ch == '-', ch < '0' || ch > '9')
			;
		while (s = s * 10 + ch - '0', ch = getchar(), ch >= '0' && ch <= '9')
			;
		return s * (p ? -1 : 1);
	}
	void inputQuery()
	{
		char ch;
		while (ch = getchar(), !isalpha(ch))
			;
		opt = ch == 'i';
		k = rd() + 1;
	}
} // init

namespace segmentTree
{
	#define mid(l, r) ((l + r) >> 1)
	#define ls(x) ((x) << 1)
	#define rs(x) ((x) << 1 | 1)
	struct node
	{
		int l, r, val, lzy;
	}tree[_ << 4];
	il int len(int u)
	{
		return (tree[u].r - tree[u].l + 1);
	}
	il void updata(int u)
	{
		tree[u].val = tree[ls(u)].val + tree[rs(u)].val;
	}
	il void downdata(int u)
	{
		if (tree[u].lzy == -1)
			return;
		tree[ls(u)].lzy = tree[rs(u)].lzy = tree[u].lzy;
		tree[ls(u)].val = tree[u].lzy * len(ls(u));
		tree[rs(u)].val = tree[u].lzy * len(rs(u));
		tree[u].lzy = -1;
	}
	void build(int i, int l, int r)
	{
		tree[i].l = l;
		tree[i].r = r;
		tree[i].lzy = -1;
		tree[i].val = 0;
		if (l == r)
			return;
		int m = mid(l, r);
		build(ls(i), l, m);
		build(rs(i), m + 1, r);
	}
	void change(int i, int l, int r, int k)
	{
		if (tree[i].l == l && tree[i].r == r)
		{
			tree[i].val = k * len(i);
			tree[i].lzy = k;
			return;
		}
		downdata(i);
		int m = mid(tree[i].l, tree[i].r);
		if (l > m)
		{
			change(rs(i), l, r, k);
		}
		else
		{
			if (r <= m)
			{
				change(ls(i), l, r, k);
			}
			else
			{
				change(ls(i), l, m, k);
				change(rs(i), m + 1, r, k);
			}
		}
		updata(i);
	}
	int query(int i, int l, int r, int k)
	{
		if (tree[i].l == l && tree[i].r == r)
		{
			int ans = tree[i].val - k * len(i);
			if (ans < 0)
				ans = -ans;
			return ans;
		}
		downdata(i);
		int m = mid(tree[i].l, tree[i].r);
		if (l > m)
		{
			return query(rs(i), l, r, k);
		}
		else
		{
			if (r <= m)
			{
				return query(ls(i), l, r, k);
			}
			else
			{
				return query(ls(i), l, m, k) + query(rs(i), m + 1, r, k);
			}
		}
	}
} // segmentTree

namespace lct
{
	void dfs1(int u)
	{
		sze[u] = 1;
		for (int i = head[u]; i; i = nxt[i])
		{
			int v = to[i];
			if (v == fa[u])
				continue;
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs1(v);
			sze[u] += sze[v];
			if (sze[v] > sze[son[u]])
				son[u] = v;
		}
	}
	void dfs2(int u, int t)
	{
		top[u] = t;
		id[u] = ++cnt;
		rk[cnt] = u;
		if (son[u])
			dfs2(son[u], t);
		for (int i = head[u]; i; i = nxt[i])
		{
			int v = to[i];
			if (v == fa[u] || v == son[u])
				continue;
			dfs2(v, v);
		}
	}
	void add(int x, int y)
	{
		int ans = 0;
		while (top[x] != y)
		{
			ans += segmentTree::query(1, id[top[x]], id[x], 1);
			segmentTree::change(1, id[top[x]], id[x], 1);
			x = fa[top[x]];
		}
		ans += segmentTree::query(1, id[top[x]], id[x], 1);
		segmentTree::change(1, id[top[x]], id[x], 1);
		printf("%d\n", ans);
	}
	void del(int x)
	{
		int ans = segmentTree::query(1, id[x], id[x] + sze[x] - 1, 0);
		segmentTree::change(1, id[x], id[x] + sze[x] - 1, 0);
		printf("%d\n", ans);
	}
} // lct

void add(int u, int v)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}

int main()
{
	int n, m;
	n = init::rd();
	for (int i = 2; i <= n; ++i)
	{
		add(init::rd() + 1, i);
	}
	cnt = 0;
	lct::dfs1(1);
	lct::dfs2(1, 1);
	segmentTree::build(1, 1, n);
	m = init::rd();
	for (int i = 1; i <= m; ++i)
	{
		init::inputQuery();
		if (opt)
			lct::add(k, 1);
		else
			lct::del(k);
	}

}