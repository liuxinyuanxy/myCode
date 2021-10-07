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
#define lowbit(x) ((x) & -(x))
#define _ 1000000
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
namespace fast_IO
{
    const int IN_LEN=10000000,OUT_LEN=10000000;
    char ibuf[IN_LEN],obuf[OUT_LEN],*ih=ibuf+IN_LEN,*oh=obuf;
    char *lastin=ibuf+IN_LEN;
    const char *lastout=ibuf+OUT_LEN-1;
    inline char getchar_()
    {
        if(ih==lastin)lastin=ibuf+fread(ibuf,1,IN_LEN,stdin),ih=ibuf;
        return (*ih++);
    }
    inline void putchar_(const char x)
    {
        if(ih==lastout)fwrite(obuf,1,oh-obuf,stdout),oh=obuf;
        *oh++=x;
    }
    inline void flush(){fwrite(obuf, 1, oh - obuf, stdout);}
}
using namespace fast_IO;
#define getchar() getchar_()
#define putchar(x) putchar_((x))
template <typename T> void printe(const T x)
{
    if(x>=10)printe(x/10);
    putchar(x%10+'0');
}
template <typename T> inline void print(const T x)
{
    if(x<0)putchar('-'),printe(-x);
    else printe(x);
}
il int rd()
{
	rt s = 0, p = 1; rc ch;
	while (ch = gc(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') p = -1, ch = gc();
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9'); 
	return s * p;
}
int tree[_], n = rd();
il void add(rt x, rt d)
{
	while (x <= n)
		tree[x] += d,
		x += lowbit(x);
}
il int query(rt x)
{
	rt ans = 0;
	while (x)
		ans += tree[x],
		x -= lowbit(x);
	return ans;
}
int main()
{
	rt opt, x, y;
	rt m = rd();
	rep (i, 1, n)
		add(i, rd());
	rep (i, 1, m)
	{
		opt = rd();
		x = rd(), y = rd();
		if (opt == 1)
			add(x, y);
		else
			print(query(y) - query(x - 1)),
			putchar('\n');
	}
	return flush(), 0;
}

