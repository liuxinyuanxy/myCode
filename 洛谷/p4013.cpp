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
// #define int long long
using namespace std;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
// char buf[1 << 21], *p1 = buf, *p2 = buf;

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
int cst = 0;
int N, S, T;
const int MAXN = 5000000;
const int INF = 0x3fffffff;
int cnt = 1;
int from[MAXN], head[MAXN], nxt[MAXN], to[MAXN], val[MAXN], ret[MAXN];
il void ins(int u, int v, int w, int c)
{
	nxt[++cnt] = head[u];
	from[cnt] = u;
	to[cnt] = v;
	head[u] = cnt;
	val[cnt] = c;
	ret[cnt] = w;
}
il void insert(int u, int v, int w, int c)
{
	ins(u, v, w, c);
	ins(v, u, 0, -c);
}
int a[MAXN];
int qu[MAXN + 10], l, r;
int dis[MAXN], b[MAXN], vis[MAXN], f[MAXN];
bool SPFA()
{
	l = r = 0;
	fill(dis + 1, dis + 1 + N, INF);
	fill(b + 1, b + 1 + N, 0);
	fill(f + 1, f + 1 + N, 0);
	fill(vis + 1, vis + 1 + N, 0);
	qu[r++] = S;
	dis[S] = 0;
	b[S] = INF;
	vis[S] = 1;
	while (l != r)
	{
		int u = qu[l++];
		if (l > MAXN)
			l = 0;
		for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
		{
			if (ret[i] > 0 && dis[v] > dis[u] + val[i])
			{
				dis[v] = dis[u] + val[i];
				b[v] = min(b[u], ret[i]);
				f[v] = i;
				if (!vis[v])
				{
					vis[v] = 1;
					qu[r++] = v;
					if (r > MAXN)
						r = 0;
				}
			}
		}
		vis[u] = 0;
	}
	if (dis[T] == INF)
		return 0;
	cst += dis[T] * 1ll * b[T];
	int o = T;
	while (f[o])
	{
		ret[f[o]] -= b[T];
		ret[f[o] ^ 1] += b[T];
		o = from[f[o]];
	}
	return 1;
}
int gra[25][50];
int id[25][50], tot;
int main()
{
	int m, n;
	read(m), read(n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m + i - 1; ++j)
		{
			read(gra[i][j]);
			id[i][j] = ++tot;
		}
	S = (tot << 1) + 1;
	T = S + 1;
	N = T;
	for (int i = 1; i <= m; ++i)
	{
		insert(i, i + tot, 1, -gra[1][i]);
		insert(S, i, 1, 0);
	}
	for (int i = 2; i <= n; ++i)
		for (int j = 1; j <= m + i - 1; ++j)
		{
			insert(id[i][j], id[i][j] + tot, 1, -gra[i][j]);
			if (j != m + i - 1)
				insert(id[i - 1][j] + tot, id[i][j], 1, 0);
			if (j != 1)
				insert(id[i - 1][j - 1] + tot, id[i][j], 1, 0);
		}
	for (int i = 1; i <= n + m - 1; ++i)
		insert(id[n][i] + tot, T, 1, 0);
	while (SPFA())
		;
	print(-cst);
	for (int i = 1; i <= N; ++i)
		head[i] = 0;
	cnt = 1;
	cst = 0;
	S = tot + 1;
	T = S + 1;
	N = T;
	for (int i = 1; i <= m; ++i)
	{
		insert(S, i, 1, -gra[1][i]);
	}
	for (int i = 2; i <= n; ++i)
		for (int j = 1; j <= m + i - 1; ++j)
		{
			if (j != m + i - 1)
				insert(id[i - 1][j], id[i][j], 1, -gra[i][j]);
			if (j != 1)
				insert(id[i - 1][j - 1], id[i][j], 1, -gra[i][j]);
		}
	for (int i = 1; i <= n + m - 1; ++i)
		insert(id[n][i], T, INF, 0);
	while (SPFA())
		;
	print(-cst);
	for (int i = 1; i <= N; ++i)
		head[i] = 0;
	cnt = 1;
	cst = 0;
	S = tot + 1;
	T = S + 1;
	N = T;
	for (int i = 1; i <= m; ++i)
	{
		insert(S, i, 1, -gra[1][i]);
	}
	for (int i = 2; i <= n; ++i)
		for (int j = 1; j <= m + i - 1; ++j)
		{
			if (j != m + i - 1)
				insert(id[i - 1][j], id[i][j], INF, -gra[i][j]);
			if (j != 1)
				insert(id[i - 1][j - 1], id[i][j], INF, -gra[i][j]);
		}
	for (int i = 1; i <= n + m - 1; ++i)
		insert(id[n][i], T, INF, 0);
	while (SPFA())
		;
	print(-cst);
	return 0;
}