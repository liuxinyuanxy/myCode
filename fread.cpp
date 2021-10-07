#include<cstdio>
#include<cctype>
#include<algorithm>
#include<queue>
#define MAX 200005
#define re register
#define rt register int
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
template <typename T> inline void read(T&x)
{
    char cu=getchar();x=0;bool fla=0;
    while(!isdigit(cu)){if(cu=='-')fla=1;cu=getchar();}
    while(isdigit(cu))x=x*10+cu-'0',cu=getchar();
    if(fla)x=-x; 
}
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
typedef std::pair<int, int> P;
std::priority_queue<P, std::vector<P>, std::greater<P> > pq;
int g[MAX];
int b[MAX];
int head[MAX], nxt[MAX], to[MAX], val[MAX];
int s, tot;
int n;
bool done[MAX];
inline void add(rt u, rt v, rt w)
{
    nxt[++tot] = head[u];
    to[tot] = v;
    val[tot] = w;
    head[u] = tot;
}
inline void dij()
{
    P now;
    pq.push(P(0, s));
    while (!pq.empty())
    {
        now = pq.top();
        pq.pop();
        if (done[now.second])
            continue;
        done[now.second] = 1;
        for (rt i = head[now.second]; i; i = nxt[i])
        {
            if (g[to[i]] > g[now.second] + val[i])
            {
                g[to[i]] = g[now.second] + val[i];
                pq.push(P(g[to[i]], to[i]));
            }
        }
    }
}
int main()
{
    rt m, u, v, w;
    read(n),
	read(m),
	read(s); 
    for (rt i = 1; i <= m; ++i)
    {
    	read(u),
    	read(v),
    	read(w);
        add(u, v, w);
    }
    for (rt i = 1; i <= n; ++i)
        g[i] = 0x7fffffff;
    g[s] = 0;
    dij();
    for (rt i = 1; i <= n; ++i)
    {
    	printf("%d ", g[i]);
    }
    return flush(),0;
}

