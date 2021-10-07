#include <iostream>
#include <cstdio>
using namespace std;
int ans;
int main()
{
    int n, last, now;
    scanf("%d", &n);
    scanf("%d", &last);
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", &now);
        ans += max(last, now);
        last = now;
    }
    printf("%d", ans);
}
