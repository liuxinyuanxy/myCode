#include <iostream>
#include <cstdio>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define _ 2000000
#define MOD 100000007
using namespace std;
int head[_], nxt[_], to[_];
int T, tot;
il int rd()
{
	rt s = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s;
}
il void add(rt u, rt v)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
}
// ans : 集合 
// cnt : 总数 
il void tre(rt u, rt fa, ll& ans, ll& cnt)
{
//	cout << u << endl;
	rt v;
	rll anst = 0, cntt = 0;
	for (rt i = head[u]; i; i = nxt[i])
	{
		v = to[i];
		if (v == fa)
			continue;
		anst = cntt = 0;
		tre(v, u, anst, cntt);
		cnt = ((cnt * (anst + 1) % MOD) + (cntt * (ans + 1)) % MOD) % MOD;
		ans = ((ans + anst) % MOD + (ans * anst) % MOD) % MOD;
	}
	cnt = (cnt + (T == 1 ? u : 1)) % MOD;
	ans = (ans + 1) % MOD;
}
int main()
{
	rt n = rd(), x, y; T = rd();
	for (rt i = 1; i < n; ++i)
	{
		x = rd(), y = rd();
		add(x, y);
		add(y, x);
	}
	rll ans = 0, cnt = 0;
	tre(1, -1, ans, cnt);
	printf("%lld", cnt);
	return 0;
}


