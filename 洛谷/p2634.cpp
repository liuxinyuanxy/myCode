#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#define gc getchar
#define LL long long
#define il inline
using namespace std;
template <typename T>
void read(T &s)
{
    s = 0;
    char ch;
    bool p = 0;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', isdigit(ch = gc()))
        ;
    s *= p ? -1 : 1;
}
const int MAXN = 40005;
const int INF = 0x3fffffff;
int head[MAXN], nxt[MAXN], to[MAXN], val[MAXN];
int cnt, S;
int sze[MAXN], maxs[MAXN], vis[MAXN], rt;
int F[3], Fs[3];
void ins(int u, int v, int w)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    val[cnt] = w;
}
void find(int u, int f)
{
    sze[u] = 1, maxs[u] = 0;
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (!vis[v] && v != f)
        {
            find(v, u);
            sze[u] += sze[v];
            maxs[u] = max(maxs[u], sze[v]);
        }
    maxs[u] = max(maxs[u], S - sze[u]);
    if (maxs[u] < maxs[rt])
        rt = u;
}
void get_dis(int u, int d, int f)
{
    ++F[d];
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (!vis[v] && v != f)
            get_dis(v, (d + val[i]) % 3, u);
}
int calc(int u)
{
    int ans = 0;
    Fs[0] = 1;
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (!vis[v])
        {
            F[0] = F[1] = F[2] = 0;
            get_dis(v, val[i], u);
            ans += F[0] * Fs[0] + F[1] * Fs[2] + F[2] * Fs[1];
            for (int j = 0; j < 3; ++j)
                Fs[j] += F[j];
        }
    return ans;
}
int solve(int u)
{
    int ans = 0;
    vis[u] = 1;
    for (int j = 0; j < 3; ++j)
        Fs[j] = 0;
    ans += calc(u);
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (!vis[v])
            S = sze[v], maxs[rt = 0] = INF, find(v, u), ans += solve(rt);
    return ans;
}
int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}
int main()
{
    int n;
    read(n);
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        read(u), read(v), read(w);
        w %= 3;
        ins(u, v, w), ins(v, u, w);
    }
    S = n;
    maxs[rt = 0] = INF;
    find(1, 0);
    int ans = solve(rt);
    ans = ans * 2 + n;
    int Q = n * n;
    int G = gcd(Q, ans);
    cout << ans / G << "/" << Q / G;
    return 0;
}