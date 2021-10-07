#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define il inline
using namespace std;
const int MAXN = 505;
const int MAXM = 600000;
int cnt;
int head[MAXN], nxt[MAXM], to[MAXM], val[MAXN];
void ins(int u, int v)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	++val[v];
}
class gause
{
public:
	int n;
	double ma[MAXN][MAXN];
	void solve()
	{
		for (int i = 0; i < n; ++i)
		{
			int idx = i;
			for (int j = i + 1; j < n; ++j)
				if (fabs(ma[j][i]) > fabs(ma[idx][i]))
					idx = j;
			if (idx != i)
				for (int j = 0; j <= n; ++j)
					swap(ma[i][j], ma[idx][j]);
			for (int j = 0; j < n; ++j)
			{
				if (i != j)
				{
					double temp = ma[j][i] / ma[i][i];
					for (int k = i; k <= n; ++k)
						ma[j][k] -= temp * ma[i][k];
				}
			}
		}
	}
} G;
vector<double> edgev;
typedef pair<int, int> P;
vector<P> edge;
P t;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		cin >> u >> v;
		ins(u, v);
		ins(v, u);
		t.first = u, t.second = v;
		edge.push_back(t);
	}
	G.n = n;
	for (int u = 1; u < n; ++u)
	{
		G.ma[u - 1][u - 1] = 1.0;
		for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
			G.ma[u - 1][v - 1] = -1.0 / val[v];
	}
	G.ma[0][n] = 1;
	G.ma[n - 1][n - 1] = 1;
	G.solve();
	for (auto x : edge)
	{
		int u = x.first, v = x.second;
		edgev.push_back(G.ma[u - 1][n] / G.ma[u - 1][u - 1] / val[u] + G.ma[v - 1][n] / G.ma[v - 1][v - 1] / val[v]);
	}
	sort(edgev.begin(), edgev.end(), greater<double>());
	double ans = 0;
	for (int i = 1; i <= m; ++i)
		ans += i * edgev[i - 1];
	printf("%.3lf", ans);
	return 0;
}