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
#define lowbit(x) ((x) & (-x))
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rll (x) = (a); (x) <= (b); ++(x))
using namespace std;
ll n, a, b, c, MOD;
ll arr[10000005];
ll ans = 0;
int check(rll p)
{
	rt s = 0;
	while (p)
		s ^= 1,
		p -= lowbit(p);
	return s;
}
int main()
{
	sfl(n), sfl2(a, b), sfl2(c, MOD);
	sfl(arr[0]);
	rep(i, 1, n)
	{
		arr[i] = jia(jia(cheng(a, cheng(arr[i-1], arr[i-1])), cheng(b, arr[i-1])), c);
//		arr[i] = (a * arr[i - 1] * arr[i - 1] + b * arr[i - 1] + c) % MOD;
//		cout << arr[i] << "\t";
		rep(j, 1, i - 1)
			ans += (int)check(arr[i]^arr[j]);
	}
	pfl(ans);
	return 0;
}

