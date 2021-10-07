/*
	2018.12.2
	?????????,????????????,??????,??????
	2018.12.3
	????
	2018.12.4
	??????????
	2018.12.5
	updata lct
*/

/*
	????????,?????,????????
	code by liuxinyuan
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cctype>
#include <algorithm>

namespace init
{
	template <class T>
	void rd(T& s)
	{
		bool p = 0;
		char ch;
		while (ch = getchar(), p |= ch == '-', ch < '0' || ch > '9');
		while (s = s * 10 + ch - '0', ch = getchar(), ch >= '0' && ch <= '9');
		s *= (p ? -1 : 1);
	}
	char rdch_int()
	{
		char ch;
		while (ch = getchar(), ch < '0' || ch > '9');
		return ch;
	}
	char rdch_char()
	{
		char ch;
		while (ch = getchar(), !isalpha(ch));
		return ch;
	}
} // init

namespace segment_tree
{
	#define mid(l, r) ((l + r) >> 1)
	#define ls(x) ((x) << 1)
	#define rs(x) (((x) << 1) | 1)
	#define fa(x) ((x) >> 1)
	#define len(x) (tree[x].r - tree[x].l + 1)
	const int N = 1000000;
	struct node
	{
		long long l, r, val;
		long long lzy1, lzy2;
	}tree[N << 4];
	inline void updata(int x)
	{
		tree[x].val = (tree[ls(x)].val + tree[rs(x)].val);
	}
	inline void downdata(int x)
	{
		if (tree[x].lzy2 > 1)
		{
			tree[ls(x)].lzy2 *= tree[x].lzy2;
			tree[rs(x)].lzy2 *= tree[x].lzy2;
			tree[ls(x)].lzy1 *= tree[x].lzy2;
			tree[rs(x)].lzy1 *= tree[x].lzy2;
			tree[ls(x)].val *= tree[x].lzy2;
			tree[rs(x)].val *= tree[x].lzy2;
		}
		tree[x].lzy2 = 1;
		if (tree[x].lzy1)
		{
			tree[ls(x)].lzy1 += tree[x].lzy1;
			tree[rs(x)].lzy1 += tree[x].lzy1;
			tree[ls(x)].val += tree[x].lzy1 * len(ls(x));
			tree[rs(x)].val += tree[x].lzy2 * len(rs(x));
		}
		tree[x].lzy1 = 0;
	}
	void build(int i, int l, int r)
	{
		tree[i].l = l;
		tree[i].r = r;
		tree[i].lzy1 = 0;
		tree[i].lzy2 = 1;
		if (l == r)
		{
			init::rd(tree[i].val);
			return;
		}
		int m = mid(l, r);
		build(ls(i), l, m),
		build(rs(i), m + 1, r);
		updata(i);
	}
	void add(int i, int l, int r, long long k)
	{
		if (tree[i].l == l && r == tree[i].r)
		{
			tree[i].val += k * len(i);
			tree[i].lzy1 += k;
			return;
		}
		downdata(i);
		int m = mid(tree[i].l, tree[i].r);
		if (l > m)
			add(rs(i), l, r, k);
		else
			if (r <= m)
				add(ls(i), l, r, k);
			else
				add(ls(i), l, m, k),
				add(rs(i), m + 1, r, k);
		updata(i);
	}
	void mul(int i, int l, int r, long long k)
	{
		if (tree[i].l == l && r == tree[i].r)
		{
			tree[i].lzy1 *= k;
			tree[i].val *= k;
			tree[i].lzy2 *= k;
			return;
		}
		downdata(i);
		int m = mid(tree[i].l, tree[i].r);
		if (l > m)
			mul(rs(i), l, r, k);
		else
			if (r <= m)
				mul(ls(i), l, r, k);
			else
				mul(ls(i), l, m, k),
				mul(rs(i), m + 1, r, k);
		updata(i);
	}
	long long query(int i, int l, int r)
	{
		if (tree[i].l == l && tree[i].r == r)
			return tree[i].val;
		downdata(i);
		int m = mid(tree[i].l, tree[i].r);
		if (l > m)
			return query(rs(i), l, r);
		else
			if (r <= m)
				return query(ls(i), l, r);
			else
				return query(ls(i), l, m) + query(rs(i), m + 1, r);
	}
} // segment_tree

namespace fenwickTree
{
	#define lowbit(x) ((x) & -(x))
	const int N = 100000;
	int tree[N];
	int del1[N], del2[N];
	int sum[N];
	int tot;
	void add(int *d, int x, int k)
	{
		while (x <= tot)
			d[x] += k,
			x += lowbit(x);
	}
	int query(int* d, int x)
	{
		int ans = 0;
		while (x)
			ans += d[x],
			x -= lowbit(x);
		return ans;
	}
	//???? ????
	void add_point_normal(int x, int k)
	{
		add(tree, x, k);
	}
	int query_interval_normal(int l, int r)
	{
		return query(tree, r) - query(tree, l - 1);
	}
	//???? ????
	void add_interval_normal(int l, int r, int k)
	{
		add(tree, l, k);
		add(tree, r + 1, -k);
	}
	int query_point_normal(int x)
	{
		return query(tree, x);
	}
	//???? ????
	void add_interval_special(int l, int r, int k)
	{
		add(del1, l, k);
		add(del1, r + 1, -k);
		add(del2, l, k * l);
		add(del2, r + 1, -k * (r + 1));
	}
	int query_interval_special(int l, int r)
	{
		return sum[r] + (r + 1) * query(del1, r) - query(del2, r) - (sum[l - 1] + l * query(del1, l - 1) - query(del2, l - 1));
	}
	//?????????
	int hs[N];			//?????????????
	void del(int x)
	{
		--sum[x];
		add(tree, x, 1);
	}
	void insert(int x)
	{
		++sum[x];
		add(tree, x, -1);
	}
	int find_rank(int x)
	{
		int ans = 0, cnt = 0;
		for (int i = 21; i >= 0; --i)
		{
			ans += 1 << i;
			if (ans > tot || cnt + tree[ans] >= x)
				ans -= 1 << i;
			else
				cnt += tree[ans];
		}
		return hs[ans + 1];
	}
	int my_rank(int x)
	{
		int ans = 1;
		--x;
		while (x)
			ans += tree[x],
			x -= lowbit(x);
		return ans;
	}
	int pre(int x)
	{
		insert(x);
		int ans = find_rank(my_rank(x) - 1);
		del(x);
		return ans;
	}
	int nxt(int x)
	{
		insert(x);
		int ans = find_rank(my_rank(x) + sum[x]);
		del(x);
		return ans;
	}
} // fenwickTree

namespace lct
{
	const int N = 1000000;
	int cnt;
	int head[N], nxt[N], to[N];
	int sze[N], son[N], dep[N], top[N], rk[N], id[N], fa[N], ed[N];
	void dfs1(int u)
	{
		sze[u] = 1;
		for (int i = head[u]; i; i = nxt[i])
		{
			int v = to[i];
			if (v == fa[i])
				continue;
			dep[v] = dep[u] + 1;
			fa[v] = u;
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
		ed[u] = cnt;
	}
	void add1(int x, int y, int k)
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
	int query1(int x, int y)
	{
		int ans = 0;
		while (top[x] != top[y])
		{
			if (dep[top[x]] < dep[top[y]])
				std::swap(x, y);
			ans += fenwickTree::query_interval_special(id[top[x]], id[x]);
			x = fa[top[x]];
		}
		if (dep[x] < dep[y])
			std::swap(x, y);
		ans += fenwickTree::query_interval_special(id[y], id[x]);
		return ans;
	}
	void add2(int x, int k)
	{
		fenwickTree::add_interval_special(id[x], ed[x], k);
	}
	int query2(int x)
	{
		return fenwickTree::query_interval_special(id[x], ed[x]);
	}
} // lct

namespace eulerFunction
{
	const int N = 10000000;
	int vis[N];
	int phi[N];
	int pri[N], cnt;
	long long SolveWithlogN(long long n)
	{
		int sum = n;
		for (long long i = 1; i * i <= n; ++i)
			if (n % i == 0)
			{
				sum -= sum / i;
				while (n % i == 0)
					n /= i;
			}
		if (n > 1)
			sum -= sum / n;
		return sum;
	}
	int main(int n)
	{
		vis[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			if (!vis[i])
				pri[++cnt] = i,
				phi[i] = i - 1;
			for (int j = i * 2; pri[j] * i <= n; ++j)
			{
				vis[pri[j] * i] = 1;
				if (i % pri[j] == 0)
				{
					phi[i * pri[j]] = phi[i] * pri[j];
					break;
				}
				else
					phi[i * pri[j]] = phi[i] * phi[pri[j]];
			}
		}
		return 0;
	}
} // eulerFunction

namespace prime
{
	void solveWithN(int n)
	{
		eulerFunction::main(n);
	}
	bool solveWithsqrtN(long long n)
	{
		if (n == 1)
			return 0;
		for (long long i = 2; i * i <= n; ++i)
			if (n % i == 0)
				return 0;
		return 1;
	}
	bool solve_develop(int n)
	{
		if (n == 1)
			return 0;
		if (n == 2 || n == 3)
			return 1;
		if (n % 6 != 1 && n % 6 != 5)
			return 0;
		for (long long i = 5; i * i <= n; i += 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return 0;
		return 1;
	}
} // prime

namespace qpow
{
	//please use this when p approaches LONG_LONG_MAX
	//warning : this function is very slow(logB)
	long long mul(long long a, long long b, long long p)
	{
		long long s = 0;
		for (; b; b >>= 1, a = (a + a) % p)
			if (b & 1)
				s = (s + a) % p;
		return s;
	}
	long long pow_special(long long a, long long b, long long p)
	{
		long long s = 1;
		for (; b; b >>= 1, a = mul(a, a, p))
			if (b & 1)
				s = mul(s, a, p);
		return s;
	}
	long long pow_normal(long long a, long long b, long long p)
	{
		long long s = 1;
		for (; b; b >>= 1, a = (a * a % p))
			if (b & 1)
				s = (s * a) % p;
		return s;
	}
} // qpow

namespace name
{

} // name

//haven't finished
namespace exgcd
{
	void exgcd(long long a, long long b, long long& x, long long& y, long long& gcd)
	{
		if (!b)
			x = 1,
			y = 0,
			gcd = a;
		else
			exgcd(b, a % b, y, x, gcd),
			y -= (a / b) * x;
	}
} // exgcd

namespace inv
{

} // inv

namespace KMP
{

} // KMP

namespace manacher
{

} // manacher

namespace ACmachine
{

} // ACmachine

namespace trie
{

} // trie
