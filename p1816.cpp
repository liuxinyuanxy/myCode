#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int tree[100005];
int n, m;
inline lowbit(int x)
{
    return x & -x;
}
inline void change(int x, int i)
{
    while (i <= n)
    {
        tree[i] = min(tree[i], x);
        i += lowbit(i);
    }
}
inline int query(int i)
{
    int ans = 0x7fffffff;
    while (i)
    {
        ans = min(ans, tree[i]);
        i -= lowbit(i);
    }
}
int main()
{
    int temp;
    scanf("%d%d", &n, &m);
    memset(tree, 0x3f, sizeof(int) * (n + 1));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &temp);
        change(temp, i);
    }
    for (int i = 1; i <= )
    return 0;
}
