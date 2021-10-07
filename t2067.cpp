#include <iostream>
#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define lowbit(x) ((x) & -(x))
using namespace std;
using namespace __gnu_pbds;
map<string, int> hs;
string s;
ll n;
ll tre[200000];
il void add(rt x, rt w)
{
	while (x <= n)
		tre[x] += w,
		x += lowbit(x);
}
il int query(rt x)
{
	int ans = 0;
	while (x)
		ans += tre[x],
		x -= lowbit(x);
	return ans;
}
int main()
{
	ll p, ans = 0;
	ios::sync_with_stdio(false);
	cin >> n;
	for (rt i = 1; i <= n; ++i)
	{
		cin >> s;
		hs[s] = i;
	}
	for (rt i = 1; i <= n; ++i)
	{
		cin >> s;
		p = hs[s];
		ans += query(p - 1);
		add(p, 1);
	}
	printf("%lld", n * (n - 1) / 2 - ans);
	return 0;
}


