#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
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
#define MAX 200005
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int needs, nd[MAX];
ll h[MAX], a[MAX];
int main()
{
    rt n;
    ll s, lll, ma = 0;
    sf(n),
    sfl2(s, lll);
    rep (i, 1, n)
        sfl(h[i]);
    rep (i, 1, n)
        sfl(a[i]);
    unsigned ll l = 0, r = max(s, lll), m;
    unsigned ll tot = 0;
    while (l != r)
    {
        tot = 0;
        m = mid(l, r);
        rep (i, 1, n)
            if (h[i] + (unsigned ll)a[i] * m >= (unsigned ll)lll)
                tot += h[i] + a[i] * m;
        if (tot >= (unsigned ll)s)
            r = m;
        else
            l = m + 1;
    }
    pfl (l);
    return 0;
}

