#include <iostream>
#include <cstdio>
#define N 105
#define MAX 10000
using namespace std;
int a[N], b[N], c[MAX];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        ++c[a[i]];
    }
    for (int i = 1; i <= MAX; ++i)
    {
        c[i] += c[i-1];
    }
    for (int i = n; i >= 1; --i)
    {
        int val = a[i];
        b[c[val]] = val;
        --c[val];
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", b[i]);
    }
}
