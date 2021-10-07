// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include <cstdio>
#include <iostream>
#define il inline
#define re register
#define ll long long
#define rll register long long
#define rt register int
#define rc register char

#ifdef DEBUG
#define D() cerr << __LINE__ << endl;
#else
#define D()
#endif

#define pf(x) printf("%d", x)
#define sf(x) scanf("%d", &x)
#define pfl(x) printf("%lld", x)
#define sfl(x) scanf("%lld", &x)
#define jia(a, b) (((a) + (b)) % MOD)
#define jian(a, b) (((a) - (b)) % MOD)
#define cheng(a, b) (((a) * (b)) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfjian(a, b) (a) = ((a) - (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b)) % MOD
#define MAX 400000
#define ls(x) ((x)*2)
#define rs(x) ((x)*2 + 1)
#define mid(x, y) (((x) + (y)) / 2)
using namespace std;
ll MOD;
struct node
{
    ll l, r;
    ll num, azy, azy2;
} tree[MAX];
il void updata(rll x)
{
    D();
    tree[x].num = jia(tree[ls(x)].num, tree[rs(x)].num);
}
il void build(rll x, rll l, rll r)
{
    D();
    tree[x].l = l;
    tree[x].azy2 = 1;
    tree[x].r = r;
    if (l != r)
        build(ls(x), l, mid(l, r)),
            build(rs(x), mid(l, r) + 1, r),
            updata(x);
    else
        sfl(tree[x].num);
    D();
}
il void downdata(rll x)
{
    D();
    if (tree[x].azy2 != 1)
    {
        selfcheng(tree[ls(x)].azy, tree[x].azy2);
        selfcheng(tree[ls(x)].azy2, tree[x].azy2);
        selfcheng(tree[ls(x)].num, tree[x].azy2);
        selfcheng(tree[rs(x)].azy, tree[x].azy2);
        selfcheng(tree[rs(x)].azy2, tree[x].azy2);
        selfcheng(tree[rs(x)].num, tree[x].azy2);
        tree[x].azy2 = 1;
    }
    if (tree[x].azy)
    {
        selfjia(tree[ls(x)].azy, tree[x].azy);
        selfjia(tree[rs(x)].azy, tree[x].azy);
        selfjia(tree[ls(x)].num, tree[x].azy * (tree[ls(x)].r - tree[ls(x)].l + 1));
        selfjia(tree[rs(x)].num, tree[x].azy * (tree[rs(x)].r - tree[rs(x)].l + 1));
        tree[x].azy = 0;
    }
    D();
}
il void changec(rll l, rll r, rll x, rll c)
{
    D();
    if (tree[x].l == l && tree[x].r == r)
    {
        selfcheng(tree[x].num, c);
        selfcheng(tree[x].azy, c);
        selfcheng(tree[x].azy2, c);
        // return;
    }
    downdata(x);
    rt m = mid(tree[x].l, tree[x].r);
    if (m >= r)
        changec(l, r, ls(x), c);
    else if (m < l)
        changec(l, r, rs(x), c);
    else
        changec(l, m, ls(x), c),
            changec(m + 1, r, rs(x), c);
    updata(x);
    D();
}
il void changej(rll l, rll r, rll x, rll c)
{
    D();
    if (tree[x].l == l && tree[x].r == r)
    {
        selfjia(tree[x].num, (r - l + 1) * c % MOD);
        selfjia(tree[x].azy, c);
        return;
    }
    downdata(x);
    rt m = mid(tree[x].l, tree[x].r);
    if (m >= r)
        changej(l, r, ls(x), c);
    else if (m < l)
        changej(l, r, rs(x), c);
    else
        changej(l, m, ls(x), c),
            changej(m + 1, r, rs(x), c);
    updata(x);
    D();
}
il ll query(rll x, rll l, rll r)
{
    D();
    if (tree[x].l == l && tree[x].r == r)
        return tree[x].num;
    downdata(x);
    updata(x);
    rt m = mid(tree[x].l, tree[x].r);
    if (m >= r)
        return query(ls(x), l, r);
    else if (m < l)
        return query(rs(x), l, r);
    else
        return (query(ls(x), l, m) + query(rs(x), m + 1, r)) % MOD;
}
int main()
{
    rll n, m, x, y, p;
    rll k;
    sfl(n),
        sfl(m),
        sfl(MOD);
    build(1, 1, n);
    D();
    for (rt i = 1; i <= m; ++i)
    {
        sfl(p), sfl(x), sfl(y);
        if (p == 3)
        {
            pfl((query(1, x, y) % MOD));
            printf("\n");
        }
        else
        {
            sfl(k);
            D();
            k %= MOD;
            if (p == 1)
                changec(x, y, 1, k);
            else
                changej(x, y, 1, k);
        }
    }
    return 0;
}