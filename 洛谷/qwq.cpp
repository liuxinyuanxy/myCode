#include <bits/stdc++.h>
#define R register int
#define I inline void
#define G           \
    if (++ip == ie) \
        if (fread(ip = buf, 1, SZ, stdin))
#define lc c[x][0]
#define rc c[x][1]
using namespace std;
const int SZ = 1 << 19, N = 3e5 + 9;
char buf[SZ], *ie = buf + SZ, *ip = ie - 1;
inline int in()
{
    G;
    while (*ip < '-')
        G;
    R x = *ip & 15;
    G;
    while (*ip > '-')
    {
        x *= 10;
        x += *ip & 15;
        G;
    }
    return x;
}
int f[N], c[N][2], v[N], s[N], st[N];
bool r[N];
inline bool nroot(R x)
{
    return c[f[x]][0] == x || c[f[x]][1] == x;
}
I pushup(R x)
{
    s[x] = s[lc] ^ s[rc] ^ v[x];
}
I pushr(R x)
{
    R t = lc;
    lc = rc;
    rc = t;
    r[x] ^= 1;
}
I pushdown(R x)
{
    if (r[x])
    {
        if (lc)
            pushr(lc);
        if (rc)
            pushr(rc);
        r[x] = 0;
    }
}
I rotate(R x)
{
    R y = f[x], z = f[y], k = c[y][1] == x, w = c[x][!k];
    if (nroot(y))
        c[z][c[z][1] == y] = x;
    c[x][!k] = y;
    c[y][k] = w;
    if (w)
        f[w] = y;
    f[y] = x;
    f[x] = z;
    pushup(y);
}
I splay(R x)
{
    R y = x, z = 0;
    st[++z] = y;
    while (nroot(y))
        st[++z] = y = f[y];
    while (z)
        pushdown(st[z--]);
    while (nroot(x))
    {
        y = f[x];
        z = f[y];
        if (nroot(y))
            rotate((c[y][0] == x) ^ (c[z][0] == y) ? x : y);
        rotate(x);
    }
    pushup(x);
}
I access(R x)
{
    for (R y = 0; x; x = f[y = x])
        splay(x), rc = y, pushup(x);
}
I makeroot(R x)
{
    access(x);
    splay(x);
    pushr(x);
}
int findroot(R x)
{
    access(x);
    splay(x);
    while (lc)
        pushdown(x), x = lc;
    splay(x);
    return x;
}
I split(R x, R y)
{
    makeroot(x);
    access(y);
    splay(y);
}
I link(R x, R y)
{
    makeroot(x);
    if (findroot(y) != x)
        f[x] = y;
}
I cut(R x, R y)
{
    makeroot(x);
    if (findroot(y) == x && f[y] == x && !c[y][0])
    {
        f[y] = c[x][1] = 0;
        pushup(x);
    }
}
int main()
{
    R n = in(), m = in();
    for (R i = 1; i <= n; ++i)
        v[i] = in();
    while (m--)
    {
        R type = in(), x = in(), y = in();
        switch (type)
        {
        case 0:
            split(x, y);
            printf("%d\n", s[y]);
            break;
        case 1:
            link(x, y);
            break;
        case 2:
            cut(x, y);
            break;
        case 3:
            splay(x);
            v[x] = y;
        }
    }
    return 0;
}