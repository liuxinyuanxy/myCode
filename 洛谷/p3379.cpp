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
const int MOD = 1000000007;
const int MAXN = 1000005;
int A, B, C, P;
il int rnd()
{
    return A = (A * B + C) % P;
}
signed main()
{
    int n, m;
    read(n), read(m);

    return 0;
}