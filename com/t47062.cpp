#include <iostream>
#include <cstdio>
#define il inline
#define re register
#define ll long long
#define rt register int
#define rc register char
#define rll register long long
#define pf(x) printf("%d", x)
#define pf2(x, y) printf("%d %d", x, y)
#define sf(x) scanf ("%d", &x)
#define sf2(x, y) scanf ("%d%d", &x, &y)
#define pfl(x) printf("%lld", x)
#define pfl2(x, y) printf("%lld%lld", x, y)
#define sfl(x) scanf ("%lld", &x)
#define sfl2(x, y)	scanf ("%lld%lld", &x, &y)
#define jia(a, b) (((a) + (b)) % MOD)
#define jian(a, b) (((a) - (b)) % MOD)
#define cheng(a, b) (((a) * (b)) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfjian(a, b) (a) = ((a) - (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b)) % MOD
#define selfmax(x, y) (x) = max((x), (y))
#define mid(x, y) (((x) + (y)) >> 1)
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define lowbit(x) ((x) & (-x))
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
il ll rd()
{
	rll s = 0, p = 1;
	rc ch = getchar();
	while ((ch < '0' || ch > '9'))
		ch == '-' ? p = -1 : ch = getchar();
	while(ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0',
		ch = getchar();
	return s * p;
}
ll n;
ll a[500005];
bool tag[500005]; 
ll tree[500005];
il void add(rll x, rll k)
{
	while (x <= n)
		tree[x] += k,
		x += lowbit(x);
}
il ll query(rll x)
{
	ll ans = 0;
	while (x)
		ans += tree[x],
		x -= lowbit(x);
	return ans;
}
int main()
{
	__int128 MAX = 17179869184000000;
	rll Talent, m, k, c;
	rt p = 0, never = 0;
	rc ch;
	n = rd(), Talent = rd();
	if (Talent == 0)
	{
		never = 1;
	}
	rep(i, 1, n)
	{
		a[i] = rd();
		if (a[i] <= Talent)
			add(i, 1);
	}
	m = rd();
	rep(i, 1, m)
	{
		ch = getchar();
		while (ch != 'B' && ch != 'G' && ch != 'Z' && ch != 't')
			ch = getchar();
		if (ch == 'B')
			p = 1;
		else
			if (ch == 'G')	
				p = 2;
			else
				if (ch == 't')
					p = 3;
				else
					p = 4;
		k = rd();
		c = rd();
		if (p == 1)
		{
			if (tag[k])
				continue;
			if (a[k] > Talent && a[k] - c <= Talent)
				add(k, 1);
			a[k] -= c;
			if (a[k] <= 0)
				a[k] = 1;
		}
		if (p == 2)
		{
			if (c == 0)
			{
				if (tag[k] || a[k] > Talent)
					add(k, 1);
				tag[k] = 0;
				a[k] = 0;
				continue;
			}
			if (tag[k])
				continue;
			if (a[k] <= Talent && (__int128)a[k] * c > (__int128)Talent)
				add(k, -1);
			if ((__int128)a[k] * (__int128)c >= MAX)
				tag[k] = 1;
			else
				a[k] *= c;
		}
		if (p == 3)
		{
			if ((c <= Talent)&&(tag[k] || a[k] > Talent))
				add(k, 1);
			tag[k] = 0;
			a[k] = c;
		}
		if (p == 4)
		{
			if (never)
			{
				putchar('0');
				putchar('\n');
				continue;
			}
			pfl((query(c) - query(k - 1)) * 600),
			putchar('\n');
		}
	}
	return 0;
}

