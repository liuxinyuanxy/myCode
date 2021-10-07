#include <cstdio>
#include <cstring>
#include <iostream>
#define D() \
	// cerr << __LINE__ << endl;
using namespace std;
typedef pair<int, int> P;
const int MAXN = 60;
const int MAXM = 4000;
P qu[MAXM];
int l, r;
class machine
{
private:
	int n;
	int out[MAXN], pi[MAXN][2];
	int vis[MAXN][MAXN];

public:
	machine() { memset(out, 0, sizeof(out)); }
	void read()
	{
		int m;
		cin >> n >> m;
		for (int i = 1; i <= m; ++i)
		{
			int x;
			cin >> x;
			out[x] = 1;
		}
		for (int i = 0; i < n; ++i)
			cin >> pi[i][0] >> pi[i][1];
	}
	bool check(const machine &x)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < x.n; ++j)
				vis[i][j] = 0;
		l = r = 0;
		P t;
		t.first = 0, t.second = 0;
		vis[0][0] = 1;
		qu[r++] = t;
		while (l != r)
		{
			P u = qu[l++];
			if (out[u.first] && !x.out[u.second])
				return false;
			for (int i = 0; i < 2; ++i)
			{
				t.first = pi[u.first][i], t.second = x.pi[u.second][i];
				if (!vis[t.first][t.second])
					vis[t.first][t.second] = 1, qu[r++] = t;
			}
		}
		return true;
	} // check whether x is the upgrade of this
} ma[MAXN];
int cnt;
int in[MAXN];
int head[MAXN], from[MAXM], nxt[MAXM << 1], to[MAXM << 1], head2[MAXM];
void ins(int u, int v)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	from[cnt] = u;
	to[cnt] = v;
}
void ins2(int u, int v)
{
	nxt[++cnt] = head2[u];
	head2[u] = cnt;
	to[cnt] = v;
	++in[v];
}
int tot;
int vis[MAXN], clo[MAXN], sze[MAXN];
int dis[MAXN];
int dfn[MAXN], low[MAXN], sta[MAXN], top;
int y;
void tarjan(int u)
{
	dfn[u] = low[u] = ++tot;
	sta[++top] = u;
	vis[u] = 1;
	for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!dfn[v])
			tarjan(v), low[u] = min(low[u], low[v]);
		else if (vis[v])
			low[u] = min(low[u], dfn[v]);
	if (low[u] == dfn[u])
		do
			y = sta[top--], clo[y] = u, vis[y] = 0, ++sze[u];
		while (y != u);
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int S;
	int ans = 0;
	int qu[MAXN];
	cin >> S;
	for (int i = 1; i <= S; ++i)
		ma[i].read();
	for (int i = 1; i <= S; ++i)
		for (int j = 1; j <= S; ++j)
			if (i != j && ma[i].check(ma[j]))
				ins(i, j);
	D();
	for (int i = 1; i <= S; ++i)
		if (!dfn[i])
			tarjan(i);
	D();
	int m = cnt;
	for (int i = 1; i <= m; ++i)
		if (clo[from[i]] != clo[to[i]])
			ins2(clo[from[i]], clo[to[i]]);
	D();
	l = r = 0;
	for (int i = 1; i <= S; ++i)
		if (clo[i] == i && in[i] == 0)
			qu[r++] = i, dis[i] = sze[i];
	while (l != r)
	{
		int u = qu[l++];
		ans = max(ans, dis[u]);
		for (int i = head2[u], v = to[i]; i; i = nxt[i], v = to[i])
		{
			--in[v];
			dis[v] = max(dis[v], dis[u] + sze[v]);
			if (in[v] == 0)
				qu[r++] = v;
		}
	}
	cout << ans << endl;
	return 0;
}