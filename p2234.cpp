#include <iostream>
#include <algorithm>
#include <cstdio>
#define rep(i, a, b) for (rt i = (a); i <= (b); ++i)
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define p_q priority_queue
#define pii pair <int, int>
#define piii pair <pii, int>
#define piiii pair <pii, pii>
#define pll pair <ll, ll>
#define plll pair <pll, ll>
#define pllll pair <pll, pll>
#define lowbit(x) ((x) & -(x))
using namespace std;
int tree[1000005], num[1000005], a[1000000], hs[1000000];
int tot;
il int rd()
{
	rt s = 0, p = 1; rc ch;
	while (ch = gc(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') p = -1, ch = gc();
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s * p;
}
il void add(rt x, rt w)
{
	num[x] += w;
	while (x <= tot)
		tree[x] += w,
		x += lowbit(x);
}
il int ask_rank(rt x)
{
	rt ans = 1; --x;
	while (x)
		ans += tree[x],
		x -= lowbit(x);
	return ans;
}
il int is_rank(rt x)
{
	if (!x)
		return -1;
	rt ans = 0, cnt = 0;
	for (rt i = 20; i >= 0; --i)
	{
		ans += (1 << i);
		if (ans > tot || cnt + tree[ans] >= x)
			ans -= (1 << i);
		else
			cnt += tree[ans];
	}
	return ans + 1;
}
il int pre(rt x)
{
	if (num[x] >= 2)
		return 0;
	rt ans = is_rank(ask_rank(x) - 1);
	if (ans == -1)
		return 0x3fffffff;
	return hs[x] - hs[ans];
}
il int nxt(rt x)
{
	if (num[x] >= 2)
		return 0;
	rt ans = is_rank(ask_rank(x) + num[x]);
	if (ans > tot)
		return 0x3fffffff;
	return hs[ans] - hs[x];
}
int main()
{
	rt ans = 0;
	rt n = rd();
	rep (i, 1, n)
	{
		hs[i] = a[i] = rd();
	}
	sort(hs + 1, hs + 1 + n);
	tot = unique(hs + 1, hs + 1 + n) - hs - 1;
	rep (i, 1, n)
		a[i] = lower_bound(hs + 1 , hs + 1 + tot, a[i]) - hs;
	ans = hs[a[1]];
	add(a[1], 1);
	rep (i, 2, n)
		add(a[i], 1),
		ans += min(pre(a[i]), nxt(a[i]));
	printf("%d", ans);
	return 0;
}
