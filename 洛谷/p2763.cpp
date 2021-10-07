#include <cmath>
#include <cstdio>
#include <iostream>
#define il inline
#define LL long long
#define re register
#define gc getchar
using namespace std;
int S, T, N;
int cnt = 1;
const int MAXN = 3000000;
const int INF = 0x3fffffff;
int cur[MAXN];
int head[MAXN], nxt[MAXN], to[MAXN], ret[MAXN];
int dis[MAXN];
int qu[MAXN], l, r;
il void ins(int u, int v, int w)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	ret[cnt] = w;
}
il void insert(int u, int v, int w)
{
	ins(u, v, w);
	ins(v, u, 0);
}
bool bfs()
{
	fill(dis, dis + 1 + N, 0);
	l = r = 0;
	qu[r++] = S;
	dis[S] = 1;
	while (l != r)
	{
		int u = qu[l++];
		if (l > MAXN)
			l = 0;
		for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (ret[i] && !dis[v])
			{
				dis[v] = dis[u] + 1;
				if (v == T)
					return true;
				qu[r++] = v;
				if (r > MAXN)
					r = 0;
			}
	}
	return false;
}
int dfs(int u, int maxflow)
{
	if (u == T)
		return maxflow;
	int ans = 0;
	for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (ret[i] && dis[v] == dis[u] + 1)
		{
			int temp = dfs(v, min(maxflow - ans, ret[i]));
			ret[i] -= temp;
			ret[i ^ 1] += temp;
			ans += temp;
			if (ans == maxflow)
				break;
		}
	if (!ans)
		dis[u] = -2;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int k, n, x, m = 0;
	cin >> k >> n;
	S = (n << 1) + k + 1;
	T = S + 1;
	N = T;
	for (int i = 1; i <= k; ++i)
	{
		cin >> x;
		m += x;
		insert(S, (n << 1) + i, x);
	}
	for (int i = 1; i <= n; ++i)
	{
		insert(i, i + n, 1);
		insert(i + n, T, 1);
		int s;
		cin >> s;
		for (int j = 1; j <= s; ++j)
		{
			cin >> x;
			insert((n << 1) + x, i, 1);
		}
	}
	int ans = 0;
	while (bfs())
		ans += dfs(S, INF);
	if (ans != m)
		cout << "No Solution!\n";
	else
	{
		for (int i = 1; i <= k; ++i)
		{
			cout << i << ":";
			for (int j = head[(n << 1) + i], v = to[j]; j; j = nxt[j], v = to[j])
				if (!ret[j] && (v <= (n << 1)))
					cout << " " << v;
			cout << endl;
		}
	}
	return 0;
}