#include <iostream>
#include <cstdio>
#include <algorithm>
#define sf(x) scanf ("%d", &x)
#define sf2(x, y) scanf ("%d%d", &x, &y)
#define sf3(x, y, z) scanf ("%d%d%d", &x, &y, &z)
#define pf(x) printf ("%d", x)
#define pf2(x, y) printf("%d%d", x, y)
#define pf3(x, y, z) printf("%d%d%d", x, y, z)
#define sfl(x) scanf ("%lld", &x)
#define sfl2(x, y) scanf ("%lld%lld", &x, &y)
#define sfl3(x, y, z) scanf ("%lld%lld%lld", &x, &y, &z)
#define pfl(x) printf ("%lld", x)
#define pfl2(x, y) printf("%lld%lld", x, y)
#define pfl3(x, y, z) printf("%lld%lld%lld", x, y, z)
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
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
pii ques[100005];
int hs[100005], tot;
int tree[100005];
int sum[100005];
il void add(rt x, rt w)
{
	sum[x] += w;
	while (x <= tot)
		tree[x] += w,
		x += lowbit(x);
}
il int ask_rank(rt x)
{
	rt ans = 1;
	--x;
	while (x)
		ans += tree[x],
		x -= lowbit(x);
	return ans;
}
il int is_rank(rt x)
{
	rt cnt = 0, ans = 0;
	for (rt i = 20; i >= 0; --i)
	{
		ans += (1 << i);
		if (ans > tot || cnt + tree[ans] >= x)
			ans -= (1 << i);
		else
			cnt += tree[ans];
	}
	return hs[ans + 1];
}
il int pre(rt x)
{
	return is_rank(ask_rank(x) - 1);
}
il int nxt(rt x)
{
	return is_rank(ask_rank(x) + sum[x]);
}
int main()
{
	rt n;
	sf(n);
	rep (i, 1, n)
	{
		sf2(ques[i].first, ques[i].second);
		if (ques[i].first != 4)
			hs[++tot] = ques[i].second;
	}
	sort(hs + 1, hs + 1 + tot);
	tot = unique(hs + 1, hs + 1 + tot) - hs - 1;
	rep (i, 1, n)
		if (ques[i].first != 4)
			ques[i].second = lower_bound(hs + 1, hs + 1 + tot, ques[i].second) - hs;
	rep (i, 1, n)
	{
		if (ques[i].first < 3)
		{
			if (ques[i].first == 1)
				add(ques[i].second, 1);
			else
				add(ques[i].second, -1);
		}
		else
		{
			if (ques[i].first == 3)
				pf(ask_rank(ques[i].second));
			else
				if (ques[i].first == 4)
					pf(is_rank(ques[i].second));
				else
				{
					add(ques[i].second, 1);
					if (ques[i].first == 5)
						pf(pre(ques[i].second));
					else
						pf(nxt(ques[i].second));
					add(ques[i].second, n-1);
				}
			putchar('\n');
		}
	}
	return 0;
}
