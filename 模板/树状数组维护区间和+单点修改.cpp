//单点修改区间查询 
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
    int temp, x, y;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &temp);
        add(i, temp);
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &temp, &x, &y);
        if (temp == 1)
        {
            add(x, y);
        }else{
            printf("%d\n", query(y) - query(x-1));
        }
    }
    return 0;
}
