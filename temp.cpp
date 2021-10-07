#include <cstdio>
#include <iostream>
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
LL dis[MAXN];
int n;
int x, y;
int maxst(int u, int f)
{
	int v = 0, ans = u, nxt;
	for (auto temp : e[u])
	{
		v = temp.to;
		if (v == f)
			continue;
		if ((u == x && v == y) || (u == y && v == x))
			continue;
		dis[v] = dis[u] + temp.val;
		nxt = maxst(v, u);
		if (dis[nxt] > dis[ans])
			ans = nxt;
	}
	return ans;
}
LLL get_l(int u)
{
	dis[u] = 0;
	int k = maxst(u, -1);
	dis[k] = 0;
	int kk = maxst(k, -1);
	return dis[kk];
}
int minst(int u, int f)
{
	int v = 0, ans = u, nxt;
	for (auto temp : e[u])
	{
		v = temp.to;
		if (v == f)
			continue;
		if ((u == x && v == y) || (u == y && v == x))
			continue;
		dis[v] = dis[u] + temp.val;
		nxt = minst(v, u);
		if (dis[nxt] < dis[ans])
			ans = nxt;
	}
	return ans;
}
LLL get_ll(int u)
{
	dis[u] = 0;
	int k = minst(u, -1);
	dis[k] = 0;
	int kk = minst(k, -1);
	return dis[kk];
}
void print(LLL ans)
{
	if (!ans)
		return;
	print(ans / 10);
	putchar(ans % 10 + '0');
}
int main()
{
	LLL ans1 = 0, ans2 = 0;
	rd(n);
	for (int i = 1; i < n; ++i)
	{
		rd(t[i].from, t[i].to, t[i].val);
		e[t[i].from].push_back(t[i]);
		e[t[i].to].push_back(edge(t[i].val, t[i].to, t[i].from));
	}
	for (int i = 1; i < n; ++i)
	{
		x = t[i].from, y = t[i].to;
		LLL l1 = get_l(y), l2 = get_l(x);
		// cout << l1 << " " << l2 << endl;
		ans1 = max(ans1, l1 * l2);
		l1 = get_ll(y), l2 = get_ll(x);
		// cout << l1 << " " << l2 << endl;
		ans2 = max(ans2, l1 * l2);
	}
	print(ans1);
	cout << endl;
	print(ans2);
	cout << endl;
	return 0;
}