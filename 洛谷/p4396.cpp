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
struct que
{
    int l, r, a, b, id;
} Q[N];
bool cmp(const que &x, const que &y)
{
    return be[x.l] ^ be[y.l] ? be[x.l] < be[y.l] : be[x.l] & 1 ? x.r < y.r : x.r > y.r;
}
int a[N], cnt[N];
int S1[N], S2[N];
int ans1[N], ans2[N];
int B;
void add(int pos)
{
    ++S1[(pos - 1) / B + 1];
    if (!cnt[pos])
        ++S2[(pos - 1) / B + 1];
    ++cnt[pos];
}
void del(int pos)
{
    --S1[(pos - 1) / B + 1];
    --cnt[pos];
    if (!cnt[pos])
        --S2[(pos - 1) / B + 1];
}
void query(int l, int r, int id)
{
    int L = (l - 1) / B + 1, R = (r - 1) / B + 1;
    for (int i = l; i <= min(L * B, r); ++i)
        ans1[id] += cnt[i], ans2[id] += bool(cnt[i]);
    if (L != R)
        for (int i = (R - 1) * B + 1; i <= r; ++i)
            ans1[id] += cnt[i], ans2[id] += bool(cnt[i]);
    for (int i = L + 1; i < R; ++i)
        ans1[id] += S1[i], ans2[id] += S2[i];
}
vector<int> hs;
int main()
{
    int n, m;
    read(n, m);
    B = sqrt(n);
    for (int i = 1; i <= n; ++i)
        read(a[i]), hs.push_back(a[i]);
    for (int i = 1; i <= m; ++i)
        read(Q[i].l, Q[i].r, Q[i].a, Q[i].b), hs.push_back(Q[i].a), hs.push_back(Q[i].b), Q[i].id = i;
    sort(hs.begin(), hs.end());
    hs.erase(unique(hs.begin(), hs.end()), hs.end());
    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(hs.begin(), hs.end(), a[i]) - hs.begin() + 1;
    for (int i = 1; i <= m; ++i)
    {
        Q[i].a = lower_bound(hs.begin(), hs.end(), Q[i].a) - hs.begin() + 1;
        Q[i].b = lower_bound(hs.begin(), hs.end(), Q[i].b) - hs.begin() + 1;
    }
    int block = n / sqrt(m * 2 / 3);
    for (int i = 1; i <= n; ++i)
        be[i] = (i - 1) / block + 1;
    sort(Q + 1, Q + 1 + m, cmp);
    for (int i = Q[1].l; i <= Q[1].r; ++i)
        add(a[i]);
    int L = Q[1].l, R = Q[1].r;
    for (int i = 1; i <= m; ++i)
    {
        while (L > Q[i].l)
            add(a[--L]);
        while (R < Q[i].r)
            add(a[++R]);
        while (L < Q[i].l)
            del(a[L++]);
        while (R > Q[i].r)
            del(a[R--]);
        query(Q[i].a, Q[i].b, Q[i].id);
    }
    for (int i = 1; i <= m; ++i)
        printf("%d %d\n", ans1[i], ans2[i]);
    return 0;
}