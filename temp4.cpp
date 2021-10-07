#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#define gc getchar
#define il inline
#define re register
#define LL long long
#define LLL __int128_t
using namespace std;
template <typename T>
void rd(T &s)
{
	s = 0;
	char ch;
	bool p = 0;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9')
		;
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9')
		;
	s *= (p ? -1 : 1);
}
template <typename T, typename... Args>
void rd(T &s, Args &... args)
{
	rd(s);
	rd(args...);
}
struct edge
{
	int val, from, to;
	edge(int _val = 0, int _from = 0, int _to = 0) : val(_val), from(_from), to(_to){};
};
const int MAXN = 900000;
vector<edge> e[MAXN];
edge t[MAXN];
typedef pair<LL, int> P;
int s;
P dMax[MAXN];
LL Max[MAXN], sedMax[MAXN];
LL up[MAXN];
int n;
void dfs(int u, int f)
{
	dMax[u] = make_pair(0, 0);
	sedMax[u] = up[u] = Max[u] = 0;
	int v;
	for (auto x : e[u])
	{
		v = x.to;
		if (v == f)
			continue;
		dfs(v, u);
		if (dMax[v].first + x.val > dMax[u].first)
			sedMax[u] = dMax[u].first,
			dMax[u] = make_pair(dMax[v].first + x.val, v);
		else if (dMax[v].first + x.val > sedMax[u])
			sedMax[u] = dMax[v].first + x.val;
		if (Max[v] > Max[u])
			Max[u] = Max[v];
	}
	if (dMax[u].first + sedMax[u] > Max[u])
		Max[u] = dMax[u].first + sedMax[u];
}
void print(LLL ans)
{
	if (!ans)
		return;
	print(ans / 10);
	putchar(ans % 10 + '0');
}
pair<int, int> temp;
queue<pair<int, int>> Q;
LLL solve()
{
	LLL ans = 0;
	Q.push(make_pair(s, 0));
	while (!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		int u = temp.first, f = temp.second;
		for (auto x : e[u])
		{
			int v = x.to;
			if (v == f)
				continue;
			if (dMax[u].second == v)
				up[v] = max(max(up[u], sedMax[u]) + x.val, 0ll);
			else
				up[v] = max(max(up[u], dMax[u].first) + x.val, 0ll);
			Q.push(make_pair(v, u));
			if (dMax[u].second == v)
				ans = max(ans, LLL(up[u] + sedMax[u]) * Max[v]);
			else
				ans = max(ans, LLL(up[u] + dMax[u].first) * Max[v]);
		}
	}
	return ans;
}
int main()
{
	rd(n);
	for (int i = 1; i < n; ++i)
	{
		rd(t[i].from, t[i].to, t[i].val);
	}
	random_shuffle(t + 1, t + 1 + n);
	for (int i = 1; i <= n; ++i)
	{
		e[t[i].from].push_back(t[i]);
		e[t[i].to].push_back(edge(t[i].val, t[i].to, t[i].from));
	}
	LLL ans1 = 0;
	for (int i = 1; i <= 10; ++i)
	{
		s = rand() % n + 1;
		dfs(s, -1);
		LLL p = solve();
		ans1 = max(p, ans1);
	}
	for (int i = 1; i <= n; ++i)
		e[i].clear();
	for (int i = 1; i <= n; ++i)
	{
		t[i].val = -t[i].val;
		e[t[i].from].push_back(t[i]);
		e[t[i].to].push_back(edge(t[i].val, t[i].to, t[i].from));
	}
	LLL ans2 = 0;
	for (int i = 1; i <= 10; ++i)
	{
		s = rand() % n + 1;
		dfs(s, -1);
		LLL p = solve();
		ans2 = max(p, ans2);
	}
	print(ans1);
	cout << endl;
	print(ans2);
	cout << endl;
	print(max(ans1, ans2));
	return 0;
}