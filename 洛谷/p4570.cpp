#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#define gc getchar
#define LL long long
using namespace std;
template <typename T>
void read(T &s)
{
    s = 0;
    char ch;
    bool p = 0;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', isdigit(ch = gc()))
        ;
    s *= p ? -1 : 1;
}
int Bit[40];
bool insert(LL x)
{
    for (int i = 30; i >= 0; --i)
        if (x & (1ll << i))
        {
            if (Bit[i])
                x ^= Bit[i];
            else
            {
                Bit[i] = x;
                return true;
            }
        }
    return false;
}
LL ans;
int q[2000];
int main()
{
    int k;
    read(k);
    for (int i = 1; i <= k; ++i)
        read(q[i]);
    sort(q + 1, q + k + 1, greater<int>());
    for (int i = 1; i <= k; ++i)
        if (!insert(q[i]))
            ans += q[i];
    cout << ans << endl;
    return 0;
}