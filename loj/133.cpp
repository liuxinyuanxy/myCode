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
int tree[MAXN][MAXN];
int n, m;
#define lowbit(x) ((x) & -(x))
void add(int x, int y, int w)
{
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= m; j += lowbit(j))
            tree[i][j] += w;
}
int que(int x, int y)
{
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        for (int j = y; j; j -= lowbit(j))
            ans += tree[i][j];
    return ans;
}
int query(int a, int b, int c, int d)
{
    return que(c, d) - que(a - 1, d) - que(c, b - 1) + que(a - 1, b - 1);
}
signed main()
{
    scanf("%lld%lld", &n, &m);
    int opt, a, b, c, d;
    while (~scanf("%lld%lld%lld%lld", &opt, &a, &b, &c))
    {
        if (opt == 1)
            add(a, b, c);
        else
        {
            read(d);
            printf("%lld\n", query(a, b, c, d));
        }
    }
    return 0;
}