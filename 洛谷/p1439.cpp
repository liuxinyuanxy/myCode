#include <algorithm>
#include <cstdio>
#include <iostream>
#define gc getchar
#define il inline
#define re register
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
const int MAXN = 150000;
int a[MAXN], b[MAXN], pos[MAXN];
int g[MAXN], r = 0;
int main()
{
    int n;
    read(n);
    for (int i = 1; i <= n; ++i)
        read(a[i]), pos[a[i]] = i;
    for (int i = 1; i <= n; ++i)
        read(b[i]);
    g[r = 1] = pos[b[1]];
    for (int i = 2; i <= n; ++i)
    {
        int x = upper_bound(g + 1, g + 1 + r, pos[b[i]]) - g;
        if (x > r)
            r = x;
        g[x] = pos[b[i]];
    }
    cout << r << endl;
    return 0;
}