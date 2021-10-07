#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <queue>
#include <vector>
#define il inline
#define re register
#define gc getchar
#define LL long long
#define int LL
#define D() \
// cerr << __LINE__ << endl
using namespace std;
template <typename T>
void read(T &s)
{
	s = 0;
	char ch;
	while (ch = gc(), !isdigit(ch))
		;
	while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
		;
}
const int MAXN = 3000000;
int cnt = 0;
int head[MAXN], nxt[MAXN], to[MAXN];
int val[MAXN];
int dfn[MAXN], low[MAXN];
il void ins(int u, int v)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}
il void insert(int u, int v)
{
	ins(u, v);
	ins(v, u);
}
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> val[i];
	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b;
		insert(a, b);
	}
}