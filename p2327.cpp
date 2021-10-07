#include <iostream>
#include <cstdio>
using namespace std;
int ans;
void run(int n, int* a, int* b)
{
    for (int i = 2; i < n; ++i)
        b[i] = a[i - 1] - (b[i - 1] + b[i - 2]);
    if (b[n - 1] + b[n - 2] == a[n - 1])
        ++ans;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n], b[n];
    for (auto& x:a)
    {
        scanf("%d", &x);
    }
    if (a[0] >= 3 || a[0] < 0)
        ans = 0;
    else
    {
        if (a[0] == 0)
            b[0] = b[1] = 0;
        else
            if (a[0] == 2)
                b[0] = b[1] = 1;
            else
            {
                b[0] = 1;
                b[1] = 0;
                run(n, a, b);
                b[0] = 0;
                b[1] = 1;
            }
        run(n, a, b);
    }
    printf("%d", ans);
    return 0;
}
