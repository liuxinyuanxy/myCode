#include <iostream>
#include <cstdio>
#include <cmath>
#define N 30005
#define T 30000
using namespace std;
int fa[N], g[N], num[N];
int ff(int i)
{
    if (i == fa[i])
        return i;
    int t = ff(fa[i]);
    g[i] += g[fa[i]];
    return fa[i] = t;
}
int main()
{
    char ch[3];
    int x, y;
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= T; ++i)
    {
        fa[i] = i;
        num[i] = 1;
        g[i] = 0;
    }
    for (int i = 1;i <= t; ++i)
    {
        scanf("%s%d%d", ch, &x, &y);
        if (ch[0] == 'M')
        {
            x = ff(x);
            y = ff(y);
            fa[x] = y;
            g[x] += num[y];
            num[y] += num[x];
            num[x] = 0;
        }
        else
        {
            if (ff(x) != ff(y))
                printf("-1\n");
            else
                printf("%d\n", (abs(g[x] - g[y]) - 1));
        }
    }
    return 0;
}
