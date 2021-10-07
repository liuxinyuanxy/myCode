#include <iostream>
#include <cstdio>
#define MAX 100010
using namespace std;
const int INF = 0xffff + 1;
int a[MAX], b[MAX], c[MAX];
int x[MAX], y[MAX], t[INF];
int main()
{
    register int i;
    int n;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &c[i]);
        b[i] = c[i] / INF;
        a[i] = c[i] % INF;
    }
    for (i = 0; i < INF; ++i)
        t[i] = 0;
    for (i = 1; i <= n; ++i)
        ++t[a[i]];
    for (i = 1; i < INF; ++i)
        t[i] += t[i - 1];
    for (i = n; i >= 1; --i)
        x[t[a[i]]--] = i;
    for (i = 0; i < INF; ++i)
        t[i] = 0;
    for (i = 1; i <= n; ++i)
        ++t[b[x[i]]];
    for (i = 1; i < INF; ++i)
        t[i] += t[i - 1];
    for (i = n; i >= 1; --i)
        y[t[b[x[i]]]--] = x[i];
    for (i = 1; i <= n; ++i)
        printf("%d ", c[y[i]]);
    printf("\n");
    return 0;
}
