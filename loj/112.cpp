#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
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
#define lowbit(x) ((x) & -(x))
const int MAXN = 200001;
int k;
int tree[MAXN];
void add(int p, int x)
{
    for (; p <= k; p += lowbit(p))
        tree[p] += x;
}
int que(int p)
{
    int ans = 0;
    for (; p; p -= lowbit(p))
        ans += tree[p];
    return ans;
}
int sum[MAXN];
int a[MAXN], b[MAXN], c[MAXN], p[MAXN], cnt[MAXN];
bool cmp(int x, int y)
{
    return a[x] == a[y] ? b[x] == b[y] ? c[x] < c[y] : b[x] < b[y] : a[x] < a[y];
}
int temp[MAXN];
int ans[MAXN];
void cdq(int l, int r)
{
    if (l == r)
        return;
    int m = (l + r) >> 1;
    cdq(l, m), cdq(m + 1, r);
    int l1 = l, l2 = m + 1, l3 = l;
    while (l1 <= m && l2 <= r)
    {
        if (b[p[l1]] <= b[p[l2]])
            add(c[p[l1]], cnt[p[l1]]), temp[l3++] = p[l1++];
        else
            sum[p[l2]] += que(c[p[l2]]), temp[l3++] = p[l2++];
    }
    while (l2 <= r)
        sum[p[l2]] += que(c[p[l2]]), temp[l3++] = p[l2++];
    for (int i = l; i < l1; ++i)
        add(c[p[i]], -cnt[p[i]]);
    while (l1 <= m)
        temp[l3++] = p[l1++];
    for (int i = l; i <= r; ++i)
        p[i] = temp[i];
}
int main()
{
    int n;
    read(n), read(k);
    for (int i = 1; i <= n; ++i)
        p[i] = i, read(a[i], b[i], c[i]);
    sort(p + 1, p + 1 + n, cmp);
    int m = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x = p[i], y = p[m];
        if (a[x] != a[y] || b[x] != b[y] || c[x] != c[y])
            p[++m] = x;
        ++cnt[p[m]];
    }
    cdq(1, m);
    for (int i = 1; i <= m; ++i)
        ans[sum[p[i]] + cnt[p[i]] - 1] += cnt[p[i]];
    for (int i = 0; i < n; ++i)
        printf("%d\n", ans[i]);
    return 0;
}