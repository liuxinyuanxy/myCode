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
il ll tre(rt u, rt fa)
{
//	cout << u << endl;
	rt v;
	rll ans = 0, temp;
	for (rt i = head[u]; i; i = nxt[i])
	{
		v = to[i];
		if (v == fa)
			continue;
		temp = tre(v, u);
		ans = ((ans + temp) % MOD + (ans * temp) % MOD) % MOD;
	}
	return (ans * 2 + 1) % MOD;
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
	printf("%lld", tre(1, -1));
	return 0;
}


