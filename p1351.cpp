#include <iostream>
#include <cstdio>
#include <bitset> 
#define il inline
#define re register
#define ll long long
#define rt register int
#define rc register char
#define rll register long long
#define pf(x) printf("%d", x)
#define sf(x) scanf ("%d", &x)
#define pfl(x) printf("%lld", x)
#define sfl(x) scanf ("%lld", &x)
#define jia(a, b) (((a) + (b)) % MOD)
#define jian(a, b) (((a) - (b)) % MOD)
#define cheng(a, b) (((a) * (b)) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfjian(a, b) (a) = ((a) - (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b)) % MOD
#define rep(x, a, b) for (rt (x) = 1; (x) <= (a); (x) += (b))
#define mid(x, y) ((x) + (y) >> 1)
#define MOD 10007
#define MAX 500000
using namespace std;
int head[MAX], nxt[MAX], to[MAX];
int val[MAX];
int tot;
ll maxans, totans, onceans[MAX], firstmax[MAX], secondmax[MAX];
il void add(rt u, rt v)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
}
int main()
{
	rt n, u, v;
	sf(n);
	rep(i, n - 1, 1)
	{
		sf(u),
		sf(v);
		add(u, v);
		add(v, u);
	}
	rep(i, n, 1)
		sf(val[i]);
	rep (i, n, 1)
		for (rt j = head[i]; j; j = nxt[j])
		{
			selfjia(onceans[i], val[to[j]]);
			if (val[to[j]] >= firstmax[i])
				secondmax[i] = firstmax[i],
				firstmax[i] = val[to[j]];
			else
				if (val[to[i]] > secondmax[i])
					secondmax[i] = val[to[j]];
		}
	rep (i, n, 1)
		for (rt j = head[i]; j; j = nxt[j])
		{
			selfjia(totans, cheng(val[i], onceans[to[j]] - val[i]));
			maxans = max(maxans, val[i] * (val[i] == firstmax[to[j]] ? secondmax[to[j]] : firstmax[to[j]]));
		}
	pfl(maxans);
	putchar(' ');
	pfl(totans);
	return 0;
}

