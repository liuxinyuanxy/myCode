#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define il inline
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
    while (s = s * 10 + ch - '0', isdigit(ch = gc()))
        ;
    s *= p ? -1 : 1;
}
template <typename T, typename... Args>
void read(T &s, Args &... args)
{
    read(s), read(args...);
}
const int N = 300005;
int be[N];
int cnt[1500000];
int a[N], S[N];
LL ans[N], tot;
struct que
{
    int l, r, id;
} Q[N];
bool cmp(const que &x, const que &y)
{
    return be[x.l] ^ be[y.l] ? be[x.l] < be[y.l] : be[x.l] & 1 ? x.r < y.r : x.r > y.r;
}
int k;
void add(int d)
{
    tot += cnt[d ^ k];
    ++cnt[d];
}
void del(int d)
{
    --cnt[d];
    tot -= cnt[d ^ k];
}
int main()
{
    int n, m;
    read(n, m, k);
    for (int i = 1; i <= n; ++i)
        read(a[i]), S[i] = S[i - 1] ^ a[i];
    int block = sqrt(n);
    for (int i = 1; i <= m; ++i)
        read(Q[i].l, Q[i].r), --Q[i].l, Q[i].id = i;
    for (int i = 1; i <= n; ++i)
        be[i] = (i - 1) / block + 1;
    sort(Q + 1, Q + 1 + m, cmp);
    for (int i = Q[1].l; i <= Q[1].r; ++i)
        add(S[i]);
    int L = Q[1].l, R = Q[1].r;
    for (int i = 1; i <= m; ++i)
    {
        while (L > Q[i].l)
            add(S[--L]);
        while (R < Q[i].r)
            add(S[++R]);
        while (L < Q[i].l)
            del(S[L++]);
        while (R > Q[i].r)
            del(S[R--]);
        ans[Q[i].id] = tot;
    }
    for (int i = 1; i <= m; ++i)
        printf("%lld\n", ans[i]);
    return 0;
}