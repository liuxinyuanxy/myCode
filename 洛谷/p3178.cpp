#include <cstdio>
#include <iostream>
#define il inline
#define int long long
using namespace std;
const int MAXN = 200005;
#define lowbit(x) ((x) & (-x))
int del1[MAXN], del2[MAXN], sum[MAXN];
int n;
il void add(int *tree, int pos, int x)
{
	while (pos <= n)
		tree[pos] += x, pos += lowbit(pos);
}
il int que(int *tree, int pos)
{
	int ans = 0;
	while (pos)
		ans += tree[pos], pos -= lowbit(pos);
	return ans;
}
il void modify(int l, int r, int x)
{
	add(del1, l, x), add(del1, r + 1, -x), add(del2, l, x * l), add(del2, r + 1, -x * (r + 1));
}
il int query(int l, int r)
{
	return sum[r] + (1 + r) * que(del1, r) - que(del2, r) - sum[l - 1] - l * que(del1, l - 1) + que(del2, l - 1);
}
int cnt;
int head[MAXN], nxt[MAXN], to[MAXN], val[MAXN];
int fa[MAXN], top[MAXN], sze[MAXN], son[MAXN];
int pos[MAXN], id[MAXN];
int tot;
il void ins(int u, int v)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}
il void insert(int u, int v)
{
	ins(u, v), ins(v, u);
}
void dfs1(int u)
{
	sze[u] = 1;
	for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u])
		{
			fa[v] = u;
			dfs1(v);
			if (sze[v] > sze[son[u]])
				son[u] = v;
			sze[u] += sze[v];
		}
}
void dfs2(int u, int t)
{
	pos[u] = ++tot;
	top[u] = t;
	id[tot] = u;
	sum[tot] = sum[tot - 1] + val[u];
	if (son[u])
		dfs2(son[u], t);
	for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u] && v != son[u])
			dfs2(v, v);
}
il void modify1(int x, int a)
{
	modify(pos[x], pos[x], a);
}
il void modify2(int x, int a)
{
	modify(pos[x], pos[x] + sze[x] - 1, a);
}
il int query(int x)
{
	int ans = 0;
	while (x)
	{
		ans += query(pos[top[x]], pos[x]);
		x = fa[top[x]];
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> val[i];
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		insert(u, v);
	}
	dfs1(1);
	dfs2(1, 1);
	for (int i = 1; i <= m; ++i)
	{
		int op, x, a;
		cin >> op >> x;
		if (op < 3)
		{
			cin >> a;
			op == 1 ? modify1(x, a) : modify2(x, a);
		}
		else
		{
			cout << query(x) << endl;
		}
	}
	return 0;
}