#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
 
#define INF 0x7fffffff
#define EPS 1e-12
#define MOD 1000000007
#define PI 3.141592653579798
#define N 100000
 
using namespace std;
 
typedef long long LL;
typedef double DB;
 
LL e_gcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    LL ans=e_gcd(b,a%b,x,y);
    LL temp=x;
    x=y;
    y=temp-a/b*y;
    return ans;
}
 
LL cal(LL a,LL b,LL c)
{
    LL x,y;
    LL gcd=e_gcd(a,b,x,y);
    if(c%gcd!=0) return -1;
    x*=c/gcd;
    b/=gcd;
    if(b<0) b=-b;
    LL ans=x%b;
    if(ans<=0) ans+=b;
    return ans;
}
 
int main()
{
    LL a,b,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        LL ans=cal(a,b,1);
        if(ans==-1) printf("Not Exist\n");
        else printf("%lld\n",ans);
    }
    return 0;
}
