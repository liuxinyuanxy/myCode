#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#define il inline
#define int long long
using namespace std;
namespace io
{
const int __SIZE = (1 << 21) + 1;
char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55];
int __f, qr, _eof, _sze;
#ifdef DEBUG
#define Gc() getchar()
#else
#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
#endif
inline void flush()
{
    fwrite(obuf, 1, oS - obuf, stdout), oS = obuf;
}
inline void gc(char &x) { x = Gc(); }
inline void pc(char x)
{
    *oS++ = x;
    if (oS == oT)
        flush();
}
inline void pstr(const char *s)
{
    int __len = strlen(s);
    for (__f = 0; __f < __len; ++__f)
        pc(s[__f]);
}
inline void gstr(char *s)
{
    for (__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)
        __c = Gc();
    for (; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc())
        *s = __c;
    *s = 0;
}
template <class I>
inline bool read(I &x)
{
    _eof = 0;
    for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc())
    {
        if (__c == '-')
            __f = -1;
        _eof |= __c == EOF;
    }
    for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc())
        x = x * 10 + (__c & 15), _eof |= __c == EOF;
    x *= __f;
    return !_eof;
}
template <class I, class... Args>
inline int read(I &x, Args &... args)
{
    return read(x) + read(args...);
}
template <class I>
inline void print(I x)
{
    if (!x)
        pc('0');
    if (x < 0)
        pc('-'), x = -x;
    while (x)
        qu[++qr] = x % 10 + '0', x /= 10;
    while (qr)
        pc(qu[qr--]);
    pc('\n');
}
struct Flusher_
{
    ~Flusher_() { flush(); }
} io_flusher_;
} // namespace io
using io::gc;
using io::gstr;
using io::pc;
using io::print;
using io::pstr;
using io::read;
const int MAXN = 2000000;
int n, cnt, rt;
int head[MAXN], nxt[MAXN], to[MAXN], val[MAXN], fa[MAXN], sze[MAXN], son[MAXN], top[MAXN], dis[MAXN];
int pos[MAXN], tot;
int sum[MAXN], del1[MAXN], del2[MAXN];
#define lowbit(x) ((x) & -(x))
void add(int p, int x, int *tree)
{
    for (; p <= n; p += lowbit(p))
        tree[p] += x;
}
int que(int p, int *tree)
{
    int ans = 0;
    for (; p; p -= lowbit(p))
        ans += tree[p];
    return ans;
}
void ins(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
void insert(int u, int v)
{
    ins(u, v), ins(v, u);
}
void dfs(int u)
{
    pos[u] = ++tot;
    sum[tot] = sum[tot - 1] + val[u];
    sze[u] = 1;
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (fa[u] != v)
        {
            fa[v] = u;
            dis[v] = dis[u] + 1;
            dfs(v);
            if (sze[v] > sze[son[u]])
                son[u] = v;
            sze[u] += sze[v];
        }
}
void dfs2(int u, int t)
{
    top[u] = t;
    if (son[u])
        dfs2(son[u], t);
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (son[u] != v && fa[u] != v)
            dfs2(v, v);
}
int lca(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dis[top[u]] < dis[top[v]])
            swap(u, v);
        u = fa[top[u]];
    }
    return dis[u] < dis[v] ? u : v;
}
void modify(int u, int x)
{
    if (!u)
        return;
    add(pos[u], x, del1);
    add(pos[u], x * dis[u], del2);
}
il int query1(int l, int r)
{
    return que(r, del1) - que(l - 1, del1);
}
il int query2(int l, int r)
{
    return que(r, del2) - que(l - 1, del2);
}
signed main()
{
    int m;
    read(n), read(m), read(rt);
    for (int i = 1; i <= n; ++i)
        read(val[i]);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        read(u), read(v);
        insert(u, v);
    }
    dfs(rt), dfs2(rt, rt);
    for (int i = 1; i <= m; ++i)
    {
        int op, u, v, w, l;
        read(op), read(u);
        if (op == 1)
        {
            read(v), read(w), l = lca(u, v);
            modify(u, w), modify(v, w), modify(l, -w), modify(fa[l], -w);
        }
        else if (op == 2)
            printf("%lld\n", query1(pos[u], pos[u] + sze[u] - 1) + val[u]);
        else
            printf("%lld\n", sum[pos[u] + sze[u] - 1] - sum[pos[u] - 1] + (1 - dis[u]) * query1(pos[u], pos[u] + sze[u] - 1) + query2(pos[u], pos[u] + sze[u] - 1));
    }
}