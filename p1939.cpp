#include <iostream>
#include <cstdio>
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
#define _ 4
#define MOD 1000000007
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)
using namespace std;
struct matrix
{
    int r, l;
    ll mat[_][_];
};
matrix operator * (const matrix& a, const matrix& b)
{
    matrix ans;
    ans.r = a.r;
    ans.l = b.l;
    rep(i, 1, ans.r)
        rep(j, 1, ans.l)
        {
            ans.mat[i][j] = 0;
            rep(k, 1, a.l)
                ans.mat[i][j] += a.mat[i][k] * b.mat[k][j],
                ans.mat[i][j] %= MOD;
        }
        return ans;
}
il matrix qpow(matrix x, rt b)
{
    matrix ans;
    ans.r = ans.l = x.r;
    rep(i, 1, x.r)
        rep(j, 1, x.r)
            ans.mat[i][j] = 0;
    rep(i, 1, x.r)
        ans.mat[i][i] = 1;
    for (; b; b >>= 1, x = x * x)
        if (b & 1)
            ans = ans * x;
    return ans;
}
int main()
{
    matrix ans, s, fst;
    rt t, n;
    sf(t);
    ans.r = ans.l = 3;
    fst.r = 3, fst.l = 1;
    rep(i, 1, 3)
        fst.mat[i][1] = 1;
    rep (i, 1, 3)
        rep (j, 1, 3)
            ans.mat[i][j] = 0;
    ans.mat[1][2] = ans.mat[2][3] = ans.mat[3][1] = ans.mat[3][3] = 1; 
    while (t--)
    {
        sf(n);
        s = ans;
        s = qpow(s, n - 1);
        s = s * fst;
        pfl(s.mat[1][1]);
        putchar('\n');
    }
    return 0;
}
