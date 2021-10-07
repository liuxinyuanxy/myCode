#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 100000
using namespace std;
struct node{
	int u, v, w;
}l[MAX];
int fa[MAX];
int valfa[MAX];
int tree[MAX];
int q[MAX];
int dep[MAX];
int head[MAX], nxt[MAX], to[MAX], val[MAX];
int tot;
inline int find_Fa(int x)
{
	return x == fa[x] ? x : fa[x] = find_Fa(fa[x]);
}
inline bool merge(int x, int y)
{
	x = find_Fa(x),
	y = find_Fa(y);
	if (x == y)
		return false;
	fa[x] = y;
	return true;
}
inline void add(int u, int v, int w)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	val[tot] = w;
}
bool cmp(const node& a, const node& b)
{
	return a.w > b.w;
}
void dfs(int u, int last, int mark, int d)
{
	dep[u] = d;
	q[u] = mark;
	tree[u] = last;
	for (int i = head[u]; i; i = nxt[i])
		if (tree[to[i]] == 0)
		{
			valfa[to[i]] = val[i];
			dfs(to[i], u, mark, d + 1);
		}
}
int sch(int x, int y)
{
	int ans = 0x7fffffff;
	if (dep[x] < dep[y])
		swap(x, y);
	while (dep[x] > dep[y])
	{
		ans = min(ans, valfa[x]);
		x = tree[x];
	}
	while (x != y)
	{
		ans = min(ans, min(valfa[x], valfa[y]));
		x = tree[x],
		y = tree[y];
	}
	return ans;
}
int main()
{
	int n, m, ques, x, y;
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (int i = 1; i <= m; ++i)
	{
		scanf ("%d%d%d", &l[i].u, &l[i].v, &l[i].w);
	} 
	sort(l + 1, l + m + 1, cmp);
	for (int i = 1; i <= m; ++i)
	{
		if (merge(l[i].u, l[i].v))
			add(l[i].u, l[i].v, l[i].w),
			add(l[i].v, l[i].u, l[i].w);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (tree[i] == 0)
		{
			dfs(i, -1, i, 1);
		}
	}
	scanf ("%d", &ques);
	for (int i = 1; i <= ques; ++i)
	{
		scanf ("%d%d", &x, &y);
		if (q[x] != q[y])
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n", sch(x, y));
	}
	return 0;
}

