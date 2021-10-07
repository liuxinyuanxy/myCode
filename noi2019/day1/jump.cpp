#include <cctype>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#define il inline
#define re register
#define gc getchar
#define LL long long
using namespace std;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
int read()
{
	bool p = 0;
	char ch;
	int s = 0;
	while (ch = gc(), p |= ch == '-', !isdigit(ch))
		;
	while (s = s * 10 + ch - '0', isdigit(ch = gc()))
		;
	return s * (p ? -1 : 1);
}
struct io
{
	char obuf[22 << 20], *t;
	int a[40];
	io() : t(obuf)
	{
		freopen("jump.in", "r", stdin);
		freopen("jump.out", "w", stdout);
	}
	~io()
	{
		fwrite(obuf, 1, t - obuf, stdout);
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

const int MAXN = 100000;
const int MAXM = 500000;
int cnt = 0;
map<int, int> M[50005];
int x[MAXN], y[MAXN], head[MAXN], nxt[MAXM], to[MAXM], val[MAXM];
void insert(int u, int v, int w)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	val[cnt] = w;
}
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P>> pq;
int g[MAXN];
bool done[MAXN];
void dij()
{
	P now;
	pq.push(P(0, 1));
	while (!pq.empty())
	{
		now = pq.top();
		pq.pop();
		if (done[now.second])
			continue;
		done[now.second] = 1;
		for (int i = head[now.second]; i; i = nxt[i])
		{
			if (g[to[i]] > g[now.second] + val[i])
			{
				g[to[i]] = g[now.second] + val[i];
				pq.push(P(g[to[i]], to[i]));
			}
		}
	}
}
int main()
{
	int p, t, l, r, d, u;
	int n, m, w, h;
	n = read(), m = read(), w = read(), h = read();
	for (int i = 1; i <= n; ++i)
		x[i] = read(), y[i] = read(), g[i] = 0x7fffffff;
	g[1] = 0;
	if (n * 1ll * m <= 1000000)
	{
		for (int i = 1; i <= m; ++i)
		{
			p = read(), t = read(), l = read(), r = read(), d = read(), u = read();
			for (int j = 1; j <= n; ++j)
				if (x[j] >= l && x[j] <= r && y[j] >= d && y[j] <= u)
					insert(p, j, t);
		}
	}
	else
	{
		for (int i = 1; i <= n; ++i)
			M[x[i]][y[i]] = i;
		for (int i = 1; i <= m; ++i)
		{
			p = read(), t = read(), l = read(), r = read(), d = read(), u = read();
			insert(p, M[l][d], t);
		}
	}
	dij();
	for (int i = 2; i <= n; ++i)
	{
		print(g[i]);
	}
	return 0;
}