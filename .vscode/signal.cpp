#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <vector>
#define gc getchar
#define il inline
#define LL long long
#define re register
#define file "signal"
#ifdef DEBUG
#define D() cerr << __LINE__ << endl;
#define F()
#else
#define D()
#define F()                          \
    freopen(file ".in", "r", stdin); \
    freopen(file ".out", "w", stdout);
#endif
#define FFF()                        \
    freopen(file ".in", "r", stdin); \
    freopen(file ".out", "w", stdout);
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
const int MAXN = 200000;
int p[MAXN], q[MAXN];
int x[MAXN];
int main()
{
    F();
    int n, m;
    read(n), read(m);
    for (re int i = 1; i <= m; ++i)
    {
        read(p[i]), read(q[i]);
        x[q[i]] += p[i];
        for (re int j = 1; j < q[i]; ++j)
            if (p[i] - (q[i] - j) > 0)
                x[j] += p[i] - (q[i] - j);
        for (re int j = q[i] + 1; j <= n; ++j)
            if (p[i] - (j - q[i]) > 0)
                x[j] += p[i] - (j - q[i]);
    }
    for (re int i = 1; i <= m; ++i)
    {
        re int ans = 0;
        x[q[i]] -= p[i];
        for (re int j = 1; j < q[i]; ++j)
            if (p[i] - (q[i] - j) > 0)
                x[j] -= p[i] - (q[i] - j);
        for (re int j = q[i] + 1; j <= n; ++j)
            if (p[i] - (j - q[i]) > 0)
                x[j] -= p[i] - (j - q[i]);
        for (re int k = 1; k <= n; ++k)
        {
            x[k] += p[i];
            for (re int j = 1; j < k; ++j)
                if (p[i] - (k - j) > 0)
                    x[j] += p[i] - (k - j);
            for (re int j = k + 1; j <= n; ++j)
                if (p[i] - (j - k) > 0)
                    x[j] += p[i] - (j - k);
            re int tmp = x[1];
            for (re int j = 2; j <= n; ++j)
                if (x[j] < tmp)
                    tmp = x[j];
            if (tmp > ans)
                ans = tmp;
            x[k] -= p[i];
            for (re int j = 1; j < k; ++j)
                if (p[i] - (k - j) > 0)
                    x[j] -= p[i] - (k - j);
            for (re int j = k + 1; j <= n; ++j)
                if (p[i] - (j - k) > 0)
                    x[j] -= p[i] - (j - k);
        }
        x[q[i]] += p[i];
        for (re int j = 1; j < q[i]; ++j)
            if (p[i] - (q[i] - j) > 0)
                x[j] += p[i] - (q[i] - j);
        for (re int j = q[i] + 1; j <= n; ++j)
            if (p[i] - (j - q[i]) > 0)
                x[j] += p[i] - (j - q[i]);
        cout << ans << endl;
    }
    return 0;
}