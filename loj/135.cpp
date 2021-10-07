#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define il inline
#define re register
#define gc getchar
#define LL long long
#define int LL
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
const int MAXN = 5000;
#define lowbit(x) ((x) & -(x))
int n, m;
int del1[MAXN][MAXN], del2[MAXN][MAXN], del3[MAXN][MAXN], del4[MAXN][MAXN];
void add(int x, int y, int w)
{
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= m; j += lowbit(j))
        {
            del1[i][j] += w;
            del2[i][j] += w * (y - 1);
            del3[i][j] += w * (x - 1);
            del4[i][j] += w * (x - 1) * (y - 1);
        }
}
void modify(int a, int b, int c, int d, int x)
{
    add(a, b, x);
    add(c + 1, b, -x);
    add(a, d + 1, -x);
    add(c + 1, d + 1, x);
}
int que(int x, int y)
{
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        for (int j = y; j; j -= lowbit(j))
        {
            ans += x * y * del1[i][j];
            ans -= x * del2[i][j];
            ans -= y * del3[i][j];
            ans += del4[i][j];
        }
    return ans;
}
int query(int a, int b, int c, int d)
{
    return que(c, d) - que(a - 1, d) - que(c, b - 1) + que(a - 1, b - 1);
}
signed main()
{
    scanf("%lld%lld", &n, &m);
    int opt, a, b, c, d, x;
    while (~scanf("%lld%lld%lld%lld%lld", &opt, &a, &b, &c, &d))
        if (opt == 1)
            read(x), modify(a, b, c, d, x);
        else
            printf("%lld\n", query(a, b, c, d));
    return 0;
}