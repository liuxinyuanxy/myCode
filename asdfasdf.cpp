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
char ch[1000005];
int sg[1000005];
int len;
int main()
{
    int ans = 0;
    cin >> ch;
    len = strlen(ch);
    sg[0] = (ch[0] == 'G' ? 1 : -1);
    rep (i, 1, len - 1)
    {
        sg[i] = sg[i - 1] + (ch[i] == 'G' ? 1 : -1);
        rep (j, 0, i - 1)
            if (sg[i] - sg[j] == 0)
            {
                ans = selfmax(ans, i - j);
                break;
            }
    }
    if (sg[len - 1] == 0)
    	ans = len;
    pf (ans);
    return 0;
}

