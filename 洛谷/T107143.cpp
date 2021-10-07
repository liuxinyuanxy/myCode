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
const int MAXN = 2000000;
LL a[MAXN], s[MAXN];
signed main()
{
    int n, k;
    read(n), read(k);
    k = min(n - 1, k);
    for (int i = 1; i < n; ++i)
        read(a[i]), s[i] = s[i - 1] + a[i];
    LL ans = s[k];
    for (int i = k; i < n; ++i)
        ans = max(ans, s[i] - s[i - k]);
    printf("%lld", s[n - 1] - ans);
    return 0;
}