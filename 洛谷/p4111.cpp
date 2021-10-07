#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <vector>
#define gc getchar
#define il inline
#define re register
using namespace std;
template <typename T>
void read(T &s)
{
    s = 0;
    bool p = 0;
    char ch;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= p ? -1 : 1;
}
template <typename T, typename... Args>
void read(T &s, Args &... args)
{
    read(s), read(args...);
}
const int MOD = 1000000000;
const int N = 10;
const int M = 90;
int id[N][N];
int g[M][M];
int cnt;
void add(int u, int v)
{
    ++g[u][u], ++g[v][v];
    --g[u][v], --g[v][u];
}
int gause()
{
    int ans = 1;
    for (int i = 1; i < cnt; ++i)
    {
        for (int j = i + 1; j < cnt; ++j)
        {
            while (g[j][i])
            {
                int d = g[i][i] / g[j][i];
                for (int k = i; k < cnt; ++k)
                    g[i][k] = (g[i][k] - d * 1ll * g[j][k] % MOD) % MOD;
                swap(g[i], g[j]);
                ans *= -1;
            }
        }
        ans = ans * 1ll * g[i][i] % MOD;
    }
    if (ans < 0)
        ans += MOD;
    return ans;
}
int main()
{
    char ch;
    int n, m;
    read(n, m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            while (ch = gc(), ch != '.' && ch != '*')
                ;
            if (ch == '.')
                id[i][j] = ++cnt;
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (id[i][j] && id[i + 1][j])
                add(id[i][j], id[i + 1][j]);
            if (id[i][j] && id[i][j + 1])
                add(id[i][j], id[i][j + 1]);
        }
    printf("%d", gause());
    return 0;
}