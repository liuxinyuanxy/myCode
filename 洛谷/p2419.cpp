#include <cctype>
#include <cstdio>
#include <iostream>
#define il inline
#define re register
#define LL long long
#define gc getchar
using namespace std;
template <typename T>
void rd(T &s)
{
    s = 0;
    char ch;
    bool p = 0;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= (p ? -1 : 1);
}
template <typename T, typename... Args>
void rd(T &s, Args &... args)
{
    rd(s);
    rd(args...);
}
int n;
bool gra[101][101];
bool vis[101][101];
int du[101];
void dfs(int o, int u)
{
    for (int i = 1; i <= n; ++i)
        if (gra[u][i] && !vis[o][i])
        {
            vis[o][i] = 1;
            ++du[i];
            ++du[o];
            dfs(o, i);
        }
}
int main()
{
    int u, v;
    int m;
    rd(n, m);
    for (int i = 1; i <= m; ++i)
    {
        rd(u, v);
        gra[u][v] = 1;
    }
    for (int i = 1; i <= n; ++i)
        dfs(i, i);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (du[i] == n - 1)
            ++ans;
    cout << ans;
    return 0;
}