#include <algorithm>
#include <bitset>
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
const int MAXN = 1000005;
bitset<33334> B;
bitset<33334> e[1005];
int cnt = 0;
int S[MAXN];
int TTT[MAXN], T[MAXN];
int l, r;
void add_right(int x)
{
    T[r++] = x;
    B <<= 1;
    B &= e[x];
    if (x != S[1])
        B[1] = 1;
}
void add_left(int x, int p)
{
    T[--l] = x;
    for (int i = l; i < r; ++i)
        if (T[i] == S[i - l + 1])
            return;
    B[p] = 1;
}
signed main()
{
    int opt, x;
    int n, m;
    read(n), read(m);
    for (int i = 1; i <= n; ++i)
        read(S[i]);
    for (int i = 1; i <= m; ++i)
        e[S[i]][i] = 1, cnt = max(cnt, S[i]);
    for (int i = 1; i <= cnt; ++i)
        e[i] = ~e[i];
    for (int i = 1; i <= m; ++i)
    {
        read(opt), read(x);
        if (opt == 0)
            add_right(x);
        else
            add_left(x, i);
        printf("%d\n", (int)B.count());
    }
    return 0;
}