//区间修改单点查询 
#include <iostream>
#include <cstdio>
using namespace std;
int a[500010], n;
inline int lowbit(int x)
{
    return x & -x;
}
void add(int k, int num)
{
    while (k <= n)
    {
        a[k] += num;
        k += lowbit(k);
    }
}
int query(int k)
{
    int s = 0;
    while (k)
    {
        s += a[k];
        k -= lowbit(k);
    }
    return s;
}
int main()
{
    int m;
    int temp, x, y, k;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &temp);
        add(i, temp);
        add(i+1, -temp);
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &temp, &x);
        if (temp == 1)
        {
            scanf("%d%d", &y, &k);
            add(x, k);
            add(y+1, -k);
        }else{
            printf("%d\n", query(x));
        }
    }
    return 0;
}
