#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define il inline
#define LL long long
#define re register
#define file "prob"
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
inline bool
read(I &x)
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
const int MOD = 1000000007;
int qpow(int a, int b, int p)
{
    int ans = 1;
    for (; b; b >>= 1, a = a * 1ll * a % p)
        if (b & 1)
            ans = ans * 1ll * a % p;
    return ans;
}
const int MAXN = 100000;
int vis[MAXN];
int nxt[MAXN];
int cnt;
int sze[MAXN];
int belong[MAXN];
void dfs(int u)
{
    ++sze[cnt];
    vis[u] = 1;
    belong[u] = cnt;
    if (!vis[nxt[u]])
        dfs(nxt[u]);
}
int a[MAXN];
int n, m;
int ans;
int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}
il int get_lcm(int a, int b)
{
    return a * 1ll * b % MOD * 1ll * qpow(gcd(a, b), MOD - 2, MOD) % MOD;
}
int get_ans()
{
    int lcm = 1;
    for (int i = 1; i <= n; ++i)
        lcm = get_lcm(lcm, sze[belong[a[i]]]);
    return lcm;
}
void dfs2(int pos)
{
    if (pos == n + 1)
    {
        ans = (ans + get_ans()) % MOD;
        return;
    }
    for (int i = 1; i <= m; ++i)
        a[pos] = i, dfs2(pos + 1);
}
int main()
{
    F();
    read(n);
    read(m);
    for (int i = 1; i <= m; ++i)
        read(nxt[i]);
    for (int i = 1; i <= m; ++i)
        if (!vis[i])
            ++cnt, dfs(i);
    dfs2(1);
    print(ans);
    return 0;
}