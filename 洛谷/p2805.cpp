#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define il inline
#define re register
#define gc getchar
#define LL long long
using namespace std;
struct io
{
	char obuf[200 << 20], *t;
	int a[40];
	io() : t(obuf)
	{
	}
	~io()
	{
		fwrite(obuf, 1, t - obuf, stdout);
	}
	template <class T>
	inline void read(T &s)
	{
		s = 0;
		bool p = 0;
		char ch;
		while (ch = gc(), p |= ch == '-', !isdigit(ch))
			;
		while (s = s * 10 + ch - '0', isdigit(ch = gc()))
			;
		s *= (p ? -1 : 1);
	}
	template <class T>
	inline void print(T u)
	{
		static int *q = a;
		if (u < 0)
			*t++ = '-', u = -u;
		if (!u)
			*t++ = 48;
		else
		{
			while (u)
				*q++ = u % 10 + 48, u /= 10;
			while (q != a)
				*t++ = *--q;
		}
		*t++ = '\n';
	}
} ip;
#define print ip.print
#define read ip.read
int N, S, T;
const int MAXN = 5000000;
const int INF = 0x3fffffff;
int cnt = 1;
int from[MAXN], head[MAXN], nxt[MAXN], to[MAXN], ret[MAXN];
int dis[MAXN];
int qu[MAXN + 10], l, r;
il void ins(int u, int v, int w)
{
	nxt[++cnt] = head[u];
	from[cnt] = u;
	to[cnt] = v;
	head[u] = cnt;
	ret[cnt] = w;
}
il void insert(int u, int v, int w)
{
	ins(u, v, w);
	ins(v, u, 0);
}
bool bfs()
{
	fill(dis + 1, dis + 1 + N, 0);
	l = r = 0;
	qu[r++] = S;
	dis[S] = 0;
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
		if (!ret[i] && dis[v] == dis[u] + 1)
		{
			int temp = dfs(to[i], min(maxflow - ans, ret[i]));
			ans += temp;
			ret[i] -= temp;
			ret[i ^ 1] += temp;
			if (ans == maxflow)
				return ans;
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
	int n;
	cin >> n;
	int ans = 0;
	while (true)
	{
		++ans;
	}
	return 0;
}