#include <iostream>
#include <cstdio>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include <map>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> P;
gp_hash_table<P, P> fa;
int n, k;
int ans = 0;
P find(P x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void add(P t1, P t2)
{
    t1 = find(t1), t2 = find(t2);
    fa[t1] = t2;
}
int main()
{
    int p, x, y;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= 3; ++j)
            fa[P(i, j)] = P(i, j);
    for (int i = 1; i <= k; ++i)
    {
        scanf("%d%d%d", &p, &x, &y);
        if (x > n || y > n)
        {
            ++ans;
            continue;
        }
        if (p == 1)
            if (
                find(P(x, 1)) == find(P(y, 2)) ||
                find(P(x, 1)) == find(P(y, 3)) ||
                find(P(x, 2)) == find(P(y, 1)) ||
                find(P(x, 2)) == find(P(y, 3)) ||
                find(P(x, 3)) == find(P(y, 1)) ||
                find(P(x, 3)) == find(P(y, 2))
            )
                ++ans;
            else
                add(P(x, 1), P(y, 1)),
                add(P(x, 2), P(y, 2)),
                add(P(x, 3), P(y, 3));
        else
            if (x == y)
                ++ans;
            else
                if (
                    find(P(x, 1)) == find(P(y, 1)) ||
                    find(P(x, 1)) == find(P(y, 3)) ||
                    find(P(x, 2)) == find(P(y, 1)) ||
                    find(P(x, 2)) == find(P(y, 2)) ||
                    find(P(x, 3)) == find(P(y, 2)) ||
                    find(P(x, 3)) == find(P(y, 3))
                )
                    ++ans;
                else
                    add(P(x, 1), P(y, 2)),
                    add(P(x, 2), P(y, 3)),
                    add(P(x, 3), P(y, 1));
    }
    printf("%d", ans);
    return 0;
}
