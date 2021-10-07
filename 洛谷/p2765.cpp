#include <cmath>
#include <cstdio>
#include <iostream>
#define il inline
#define LL long long
#define re register
#define gc getchar
using namespace std;
const int MAXN = 200000;
int cnt;
int head[MAXN], nxt[MAXN], from[MAXN], to[MAXN], ret[MAXN], val[MAXN];
void ins(int u, int v, int w, int c)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	from[cnt] = u;
	to[cnt] = v;
	ret[cnt] = w;
	val[cnt] = c;
}
void insert(int u, int v, int w, int c)
{
	ins(u, v, w, c);
	ins(v, u, 0, -c);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, x;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			cin >> x;
				}
	return 0;
}