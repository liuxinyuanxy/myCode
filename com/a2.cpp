#include <iostream>
#include <cstdio>
#include <cstdlib>
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
#define MAX 100005
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int a[MAX], b[MAX];
int need1[MAX], need2[MAX];
pii num[MAX];
il void check(rt& a, rt b)
{
	if (a != -1 && a != b)
	{
		printf("NO\n");
		exit(0);
	}
	a = b;
}
int main()
{
	int n;
	sf(n);
	rep(i, 1, n - 1)
		sf(a[i]);
	rep(i, 1, n - 1)
		sf(b[i]);
	rep (i, 1, n)
		num[i].first = num[i].second = need1[i] = need2[i] = -1;
	rep (i, 1, n - 1)
	{
		if (b[i] & 1)
			check(num[i].second, 1),
			check(num[i + 1].second, 1);
		if (b[i] & 2)
			check(num[i].first, 1),
			check(num[i + 1].first, 1);
		if (!(a[i] & 1))
			check(num[i].second, 0),
			check(num[i + 1].second, 0);
		if (!(a[i] & 2))
			check(num[i].first, 0),
			check(num[i].first, 0);
	}
	rep(i, 1, n - 1)
	{
		if (b[i] & 1)
			need2[i] = 2;
		if (b[i] & 2)
			need1[i] = 2;
		if (!(a[i] & 1))
			need2[i] = 0;
		if (!(a[i] & 2))
			need1[i] = 0;
		if (need1[i] == -1)
			need1[i] = 1;
		if (need2[i] == -1)
			need2[i] = 1;
	}
	
	bool p1 = 1, p2 = 1, ex1 = 0, ex2 = 0;
	if (need1[1] == 1)
	{
		if (num[1].first != -1)
			check(num[2].first, need1[1] - num[1].first);
		else
		if (num[2].first != -1)
			check(num[1].first, need1[1] - num[2].first);
		else
			ex1 = 1,
			num[1].first = 1,
			num[2].first = 0;
	}
	rep(i, 1, n - 1)
	{
		if (num[i].first + num[i + 1].first != need1[i])
		{
			p1 = 0;
			break;
		}
	}
	if (!p1 && ex1)
	{
		swap(num[1].first, num[2].first);
		p1 = 1;
		rep(i, 1, n - 1)
		{
			if (num[i].first + num[i + 1].first != need1[i])
			{
				p1 = 0;
				break;
			}
		}
	}
	if (!p1)
	{
		printf("NO");
		return 0;
	}
	
	if (need2[1] == 1)
	{
		if (num[1].second != -1)
			check(num[2].second, need2[1] - num[1].second);
		else
		if (num[2].second != -1)
			check(num[1].second, need2[1] - num[2].second);
		else
			ex2 = 1,
			num[1].second = 1,
			num[2].second = 0;
	}
	rep(i, 1, n - 1)
	{
		if (num[i].second + num[i + 1].second != need2[i])
		{
			p2 = 0;
			break;
		}
	}
	if (!p2 && ex2)
	{
		swap(num[1].second, num[2].second);
		p2 = 1;
		rep(i, 1, n - 1)
		{
			if (num[i].second + num[i + 1].second != need2[i])
			{
				p2 = 0;
				break;
			}
		}
	}
	if (!p2)
	{
		printf("NO");
		return 0;
	}
	
	printf("YES\n");
	rep (i, 1, n)
	{
		pf(num[i].first * 2 + num[i].second);
	}
	return 0;
}
