#include <iostream>
#include <bitset> 
#include <cstdio>
#define il inline
#define re register
#define ll long long
#define rt register int
#define rc register char
#define rll register long long
#define pf(x) printf("%d", x)
#define pf2(x, u) printf("%d %d", x, y)
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
#define mid(x, y) ((x) + (y) >> 1)
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = 1; (x) <= (a); (x) += (b))
using namespace std;
bool p = 1;
int tot = 0;
typedef bitset<12000> Bint;
Bint aa, bb;
bool operator<(const Bint &a,const Bint &b)
{
    for(int i=a.size()-1; ~i; --i)
        if(a[i]<b[i])return 1;
    return 0;
}
bool operator!=(const Bint &a,const Bint &b)
{
    for(int i=a.size()-1; ~i; --i)
        if(a[i]!=b[i])return 1;
    return 0;
}
Bint operator+(const Bint &a,const Bint &b)
{
	cout << a.to_ulong() << endl;
    return b.any()?(a^b)+((a&b)<<1):a;
}
Bint& operator+=(Bint &a,const Bint &b)
{
    return a=a+b;
}
Bint operator-(const Bint &a)
{
    return Bint(1)+~a;
}
Bint& operator-=(Bint &a,const Bint &b)
{
    return a+=-b;
}
Bint operator-(Bint a,const Bint &b)
{
    return a-=b;
}
Bint operator*(Bint a,Bint b)
{
    Bint r(0);
    for(; b.any(); b>>=1,a+=a)if(b[0])r+=a;
    return r;
}
Bint& operator*=(Bint &a,const Bint &b)
{
    return a=a*b;
}
Bint operator%=(Bint &dividend,const Bint &divisor)
{
    if(dividend<divisor||divisor.none())return dividend;
    Bint c,res=0;
    for(int k; divisor<dividend;)
    {
        for(k=0,c=divisor; !(dividend<c); c<<=1,++k)
            if(dividend<divisor+c)
            {
                res+=1<<k;
                break;
            }
        if(dividend<divisor+c)break;
        res+=1<<(k-1);
        dividend-=c>>1;
    }
    return dividend;//res??
}
istream& getb(istream &is,Bint &val)
{
    int sign=1,ch=is.get();
    for(; !isdigit(ch)&&ch!=EOF; ch=is.get())
        if(ch=='-')
            sign=-sign;
    for(val=0; isdigit(ch); ch=is.get())
        val=(val<<3)+(val<<1)+(ch^'0');
    if(sign==-1)val=-val;
    return is.putback(ch);
}
ostream& putb(ostream &os,const Bint &val)
{
	p = 0;
    if(Bint(9)<val)putb(os, val / 10);
    return os.put(val.to_ulong()%10+'0');
}
int main()
{
    getb(cin, aa);
    getb(cin, bb);
    aa = aa + bb;
//    putb(cout, aa + bb);
    return 0;
}

