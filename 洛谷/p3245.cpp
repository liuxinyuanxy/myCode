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
const int N = 100005;
int suf[N], a[N];
int belong[N], cnt[N], ans[N];
int p, tot;
vector<int> hs;
struct que
{
    int l, r, id;
} Q[N];
void get_array(int &n)
{
    char ch;
    while (ch = gc(), !isdigit(ch))
        ;
    while (a[++n] = ch - '0', isdigit(ch = gc()))
        ;
}
bool cmp(const que &x, const que &y)
{
    return belong[x.l] ^ belong[y.l] ? belong[x.l] < belong[y.l] : belong[x.l] & 1 ? x.r < y.r : x.r > y.r;
}
il void add(int pos)
{
    // cout << pos << endl;
    tot -= cnt[pos] * (cnt[pos] - 1) / 2;
    ++cnt[pos];
    tot += cnt[pos] * (cnt[pos] - 1) / 2;
}
il void del(int pos)
{
    // cout << "d" << pos << endl;
    tot -= cnt[pos] * (cnt[pos] - 1) / 2;
    --cnt[pos];
    tot += cnt[pos] * (cnt[pos] - 1) / 2;
}
int qpow(int a, int b)
{
    int ans = 1;
    for (; b; b >>= 1, a = a * 1ll * a % p)
        if (b & 1)
            ans = ans * 1ll * a % p;
    return ans;
}
int S1[N], S2[N];
void qwq(int n)
{
    for (int i = 1; i <= n; ++i)
        S1[i] = S1[i - 1] + (a[i] % p ? 0 : i),
        S2[i] = S2[i - 1] + !(a[i] % p);
    int m;
    read(m);
    int l, r;
    for (int i = 1; i <= m; ++i)
    {
        read(l, r);
        printf("%d\n", S1[r] - S1[l - 1] - (S2[r] - S2[l - 1]) * (l - 1));
    }
}
int main()
{
    int n = 0, m;
    read(p);
    get_array(n);
    if (p == 2 || p == 5)
    {
        qwq(n);
        return 0;
    }
    suf[n + 1] = 0;
    for (int i = n; i >= 1; --i)
    {
        suf[i] = (suf[i + 1] + a[i] * 1ll * qpow(10, n - i) % p) % p;
        hs.push_back(suf[i]);
    }
    hs.push_back(0);
    suf[n + 1] = 1;
    sort(hs.begin(), hs.end());
    hs.erase(unique(hs.begin(), hs.end()), hs.end());
    for (int i = 1; i <= n; ++i)
        suf[i] = lower_bound(hs.begin(), hs.end(), suf[i]) - hs.begin() + 1;
    read(m);
    for (int i = 1; i <= m; ++i)
        read(Q[i].l, Q[i].r), Q[i].id = i, ++Q[i].r;
    int block = n / sqrt(2.0 * m / 3.0);
    for (int i = 1; i <= n + 1; ++i)
        belong[i] = (i - 1) / block + 1;
    sort(Q + 1, Q + m + 1, cmp);
    for (int i = Q[1].l; i <= Q[1].r; ++i)
        add(suf[i]);
    ans[Q[1].id] = tot;
    int l = Q[1].l, r = Q[1].r;
    for (int i = 1; i <= m; ++i)
    {
        while (l > Q[i].l)
            add(suf[--l]);
        while (r < Q[i].r)
            add(suf[++r]);
        while (l < Q[i].l)
            del(suf[l++]);
        while (r > Q[i].r)
            del(suf[r--]);
        ans[Q[i].id] = tot;
    }
    for (int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);
    return 0;
}