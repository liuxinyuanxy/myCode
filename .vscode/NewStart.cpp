#include <cctype>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#define il inline
#define re register
#define gc getchar
#define LL long long
#define int long long
using namespace std;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

struct io
{
    char obuf[200 << 20], *t;
    int a[40];
    io() : t(obuf)
    {
        // freopen("amazing.in", "r", stdin);
        // freopen("amazing.out", "w", stdout);
    }
    ~io()
    {
        fwrite(obuf, 1, t - obuf, stdout);
    }
    template <class T>
    inline void read(T &s)
    {
        s = 0;
        bool p = 0;
        char ch;
        while (ch = gc(), p |= ch == '-', !isdigit(ch))
            ;
        while (s = s * 10 + ch - '0', isdigit(ch = gc()))
            ;
        s *= (p ? -1 : 1);
    }
    template <class T>
    inline void print(T u)
    {
        printf("%lld\n", u);
    }
} ip;
#define print ip.print
#define read ip.read
int n;
const int MAXN = 1000005;
int cnt;
int head[MAXN], to[MAXN], nxt[MAXN], fa[MAXN];
il void ins(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
il void insert(int u, int v)
{
    ins(u, v);
    ins(v, u);
}
int val[MAXN], tag[MAXN], sum[MAXN];
int tot;
int trie[MAXN];
struct node
{
    int son[2];
    int cnt;
} st[MAXN * 20];
void trie_insert(int &u, int w, int k)
{
    if (k == 21)
        return;
    if (!u)
        u = ++tot;
    ++st[u].cnt;
    trie_insert(st[u].son[w & 1], w >> 1, k + 1);
}
void trie_add(int top, int u, int k)
{
    if (st[u].cnt == 0 || u == 0)
        return;
    swap(st[u].son[0], st[u].son[1]);
    sum[top] ^= (1 << k) * (st[u].cnt & 1);
    trie_add(top, st[u].son[0], k + 1);
}
void dfs(int u, int f)
{
    fa[u] = f;
    sum[f] ^= val[u];
    if (f)
        trie_insert(trie[f], val[u], 0);
    for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (v != f)
            dfs(v, u);
}
void modify(int u, int w)
{
    if (fa[u])
    {
        sum[fa[u]] ^= val[u] + tag[fa[u]];
        trie_insert(trie[fa[u]], val[u] + tag[fa[u]], 0);
    }
    val[u] += w;
    if (fa[u])
    {
        sum[fa[u]] ^= val[u] + tag[fa[u]];
        trie_insert(trie[fa[u]], val[u] + tag[fa[u]], 0);
    }
}
signed main()
{
    int m, u, v, opt;
    read(n), read(m);
    for (int i = 1; i < n; ++i)
    {
        read(u), read(v);
        insert(u, v);
    }
    for (int i = 1; i <= n; ++i)
    {
        read(val[i]);
    }
    dfs(1, 0);
    fa[0] = 0;
    for (int i = 1; i <= m; ++i)
    {
        read(opt), read(u);
        if (opt == 2)
        {
            read(v);
            modify(u, -v);
        }
        else if (opt == 1)
        {
            trie_add(u, trie[u], 0);
            ++tag[u];
            if (fa[u])
                modify(fa[u], 1);
        }
        else
        {
            print(sum[u] ^ (val[fa[u]] + tag[fa[fa[u]]]));
        }
    }
    return 0;
}