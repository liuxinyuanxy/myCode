#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 5000000
#define rt register int
using namespace std;
struct node{
	int d, s, t;
}o[MAX];
int r[MAX], need[MAX], s[MAX];
int n;
inline void erase()
{
	for (rt i = 1; i <= n; ++i)
		need[i] = 0;
}
bool check(rt from, rt x)
{
	for (rt i = from; i <= x; ++i)
	{
		need[o[i].s] += o[i].d;
		need[o[i].t + 1] -= o[i].d;
	}
	for (rt i = 1; i <= n; ++i)
	{
		s[i] = s[i - 1] + need[i];
		r[i] -= s[i];
		if (r[i] < 0)
		{
			for (rt j = 1; j <= i; ++j)
				r[j] += s[j];
			erase();
			return 1;
		}
	}
	erase();
	return 0;
}
int main()
{
	rt m;
	register bool p = 0;
	scanf ("%d%d", &n, &m);
	for (rt i = 1; i <= n; ++i)
		scanf ("%d", &r[i]);
	for (rt i = 1; i <= m; ++i)
	{
		scanf ("%d%d%d", &o[i].d, &o[i].s, &o[i].t);
		need[o[i].s] += o[i].d;
		need[o[i].t + 1] -= o[i].d;
	}
	for (rt i = 1; i <= n; ++i)
	{
		s[i] = s[i - 1] + need[i];
		if (s[i] > r[i])
		{
			p = 1;
			break;
		}
	}
	if (!p)
	{
		printf("0\n");
		return 0;
	}
	printf("-1\n");
	erase();
	rt l = 1, r = m, mid;
	while (l != r)
	{
		mid = (l + r) >> 1;
		if (check(l, mid))
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	printf("%d", l);
	return 0;
}

