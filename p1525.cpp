#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int n, m;
typedef pair<int, int> P;
struct node{
    int x, y, c;
};
node a[100005];
map<P, P> fa;
P find(P x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
bool cmp(node x, node y)
{
    return x.c > y.c;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        fa[P(i, 0)] = P(i, 0);
        fa[P(i, 1)] = P(i, 1);
    }
    for(int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].c);
    }
    sort(a + 1, a + 1 + m, cmp);
    for (int i = 1; i <= m; ++i)
    {
        P p1, p2, p3, p4;
        p1 = find(P(a[i].x, 0));
        p2 = find(P(a[i].y, 0));
        p3 = find(P(a[i].x, 1));
        p4 = find(P(a[i].y, 1));
        if (p1 == p2 ||
            p3 == p4)
            {
                printf("%d\n", a[i].c);
                return 0;
            }
        fa[p1] = p4;
        fa[p2] = p3;
    }
    printf("%d", 0);
}
