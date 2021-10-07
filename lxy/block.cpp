#include <cstdio>
#include <cstring>
#include <iostream>
#define il inline
using namespace std;
#ifdef DEBUG
#define Gc() getchar()
#define D() cerr << __LINE__ << endl;
#else
#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
#define D()
#endif

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
class qwq
{
public:
    const int MAXN = 10000;
};
using io::gc;
using io::gstr;
using io::pc;
using io::print;
using io::pstr;
using io::read;
const int MAXN = 600000;
int a[MAXN], x[MAXN];
int main()
{
    int n, T;
    read(n), read(T);
    for (int i = 1; i <= n; ++i)
        read(x[i]);
    for (int i = 1; i <= n; ++i)
        read(a[i]);
    return 0;
}