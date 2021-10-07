#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define il inline
#define LL long long
#define re register
#define file "zero"
#ifdef DEBUG
#define D() cerr << __LINE__ << endl;
#define F()
#else
#define D()
#define F()                          \
    freopen(file ".in", "r", stdin); \
    freopen(file ".out", "w", stdout);
#endif
using namespace std;
#ifdef DEBUG
#define D() cerr << __LINE__ << endl;
#define F()
#define Gc() getchar()
#else
#define D()
#define F()                          \
    freopen(file ".in", "r", stdin); \
    freopen(file ".out", "w", stdout);
#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
#endif
using namespace std;
namespace io
{
const int __SIZE = (1 << 21) + 1;
char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55];
int __f, qr, _eof, _sze;
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
const int MAXN = 1000500;
set<int> S[MAXN];
struct que
{
    int opt, l, r;
    char c;
} Q[MAXN];
int tot = 1;
int sze[MAXN], dis[MAXN];
int fa[MAXN], nxt[MAXN][30], son[MAXN], top[MAXN];
int pos[MAXN];
void dfs(int u)
{
    sze[u] = 1;
    son[u] = 0;
    for (int i = 0; i < 26; ++i)
    {
        int v = nxt[u][i];
        dis[v] = dis[u] + 1;
        if (v)
        {
            dfs(v);
            sze[u] += sze[v];
            if (sze[v] > sze[son[u]])
                son[u] = v;
        }
    }
}
void dfs2(int u, int t)
{
    top[u] = t;
    if (son[u])
        dfs2(son[u], t);
    for (int i = 0; i < 26; ++i)
    {
        int v = nxt[u][i];
        if (v && v != son[u])
            dfs2(v, v);
    }
}
int now = 1;
il void insert(int c)
{
    if (!nxt[now][c])
        nxt[now][c] = ++tot, fa[tot] = now;
    now = nxt[now][c];
}
il void del()
{
    now = fa[now];
}
il void modify(int i, int p)
{
    if (S[i].count(p))
        S[i].erase(p);
    else
        S[i].insert(p);
}
il int get_min(int i)
{
    if (S[i].empty())
        return 0x3fffffff;
    else
        return *S[i].begin();
}
int query(int i, int j)
{
    int u = pos[i], v = pos[j];
    while (top[u] != top[v])
    {
        if (dis[top[u]] < dis[top[v]])
            swap(u, v);
        u = fa[top[u]];
    }
    int ans = min(dis[u], dis[v]);
    ans = min(ans, min(get_min(i), get_min(j)) - 1);
    return ans;
}
int main()
{
    F();
    int n;
    read(n);
    for (int i = 1; i <= n; ++i)
    {
        int opt;
        char ch;
        read(opt);
        Q[i].opt = opt;
        if (opt == 1)
        {
            while (gc(ch), !isalpha(ch))
                ;
            ch -= 'a';
            Q[i].c = ch;
            insert(ch);
        }
        else if (opt == 2)
            del();
        else if (opt >= 4)
            read(Q[i].l), read(Q[i].r);
    }
    dfs(1);
    dfs2(1, 1);
    now = 1;
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (Q[i].opt == 1)
            insert(Q[i].c);
        else if (Q[i].opt == 2)
            del();
        else if (Q[i].opt == 3)
            pos[++cnt] = now;
        else if (Q[i].opt == 4)
            modify(Q[i].l, Q[i].r);
        else
            print(query(Q[i].l, Q[i].r)), pc('\n');
    }
    return 0;
}
/*
11
1 a
1 b
3
3
2
1 a
3
5 1 3
4 1 1
5 2 2
5 1 3
*/