#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define il inline
#define re register
#define gc getchar
#define LL long long
using namespace std;
template <typename T>
void read(T &s)
{
    s = 0;
    bool p = 0;
    char ch;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= p ? -1 : 1;
}
signed main()
{
    int ans = 1;
    int n, lst = 0;
    read(n);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        read(x);
        if (x != lst)
            lst = x, ++ans;
    }
    printf("%d\n", ans);
    return 0;
}