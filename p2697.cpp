#include <iostream>
#include <cstdio>
#include <cstring>
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
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
char ch[3000005];
int sg2[1000005];
int sg[1000005];
int len;
int main()
{
	int ans = 0, s = 0;
	cin >> (ch + 2);
	len = strlen(ch + 2);
	s = (ch[2] == 'G' ? 1 : -1);
	sg[s] = 2;
	sg[0] = 1;
	rep (i, 3, len + 1)
	{
		s = s + (ch[i] == 'G' ? 1 : -1);
		if (!sg[s])
			sg[s] = i;
		else
			selfmax(ans, i - sg[s]);
	}
	pf (ans);
	return 0;
}

