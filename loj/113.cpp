#include <cstdio>
#include <cstring>
#include <iostream>
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
const int MAXL = 51;
LL a[MAXL + 2];
bool p = 0;
void insert(LL x)
{
    for (int i = MAXL; i >= 0; --i)
    {
        if (!(x & (1ll << i)))
            continue;
        if (a[i])
            x ^= a[i];
        else
        {
            for (int j = 0; j < i; ++j)
                if (x & (1ll << j))
                    x ^= a[j];
            for (int j = i + 1; j <= MAXL; ++j)
                if (a[j] & (1ll << i))
                    a[j] ^= x;
            a[i] = x;
            return;
        }
    }
    p = 1;
}
vector<LL> v;
LL query(LL k)
{
    LL ans = 0;
    if (k >= (1ll << v.size()))
        return -1;
    for (int i = 0; i <= MAXL; ++i)
        if (k & (1ll << i))
            ans ^= v[i];
    return ans;
}
int main()
{
    int n;
    read(n);
    LL x;
    while (n--)
        read(x), insert(x);
    for (int i = 0; i <= MAXL; ++i)
        if (a[i])
            v.push_back(a[i]);
    int m;
    read(m);
    while (m--)
    {
        LL k;
        read(k);
        printf("%lld\n", query(k - p));
    }
    return 0;
}