#include <cctype>
#include <cstdio>
#include <iostream>
#define il inline
#define re register
#define gc getchar
#define LL long long
using namespace std;
template <typename T>
void rd(T &s)
{
    s = 0;
    char ch;
    bool p = 0;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= (p ? -1 : 1);
}
template <typename T, typename... Args>
void rd(T &s, Args &... args)
{
    rd(s);
    rd(args...);
}
struct node
{
    int n, m;
    int a[505][505];
};
const int MOD = 1000000007;
node operator*(node A, node B)
{
    node temp;
    temp.n = A.n, temp.m = B.m;
    for (int i = 1; i <= A.n; ++i)
        for (int j = 1; j <= B.m; ++j)
            for (int k = 1; k <= A.m; ++k)
                temp.a[i][j] = (A.a[i][k] * 1ll * B.a[k][j] % MOD + (LL)temp.a[i][j]) % MOD,
                (temp.a[i][j] < 0 ? temp.a[i][j] += MOD : 0);
    return temp;
}
void input(node &A)
{
    for (int i = 1; i <= A.n; ++i)
        for (int j = 1; j <= A.m; ++j)
            rd(A.a[i][j]);
}
void print(node &A)
{
    for (int i = 1; i <= A.n; ++i)
    {
        for (int j = 1; j <= A.m; ++j)
            printf("%d ", A.a[i][j]);
        printf("\n");
    }
}
int main()
{
    node A, B, ans;
    rd(A.n, A.m, B.m);
    B.n = A.m;
    input(A), input(B);
    ans = A * B;
    print(ans);
    return 0;
}