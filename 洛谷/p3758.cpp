#include <cstdio>
#include <iostream>
using namespace std;
const int MOD = 2017;
struct Mat
{
    int n, m;
    int gra[122][122];
    Mat()
    {
        for (int i = 1; i <= 121; ++i)
            for (int j = 1; j <= 121; ++j)
                gra[i][j] = 0;
    }
};
Mat operator*(Mat a, Mat b)
{
    Mat t;
    t.n = a.n, t.m = b.m;
    for (int i = 1; i <= a.n; ++i)
        for (int j = 1; j <= a.m; ++j)
            for (int k = 1; k <= b.m; ++k)
                t.gra[i][k] = (t.gra[i][k] + 0ll + a.gra[i][j] * 1ll * b.gra[j][k] % MOD) % MOD;
    return t;
}
Mat qpow(Mat a, long long b)
{
    Mat ans;
    ans.n = a.n, ans.m = a.m;
    for (int i = 1; i <= ans.n; ++i)
        ans.gra[i][i] = 1;
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            ans = ans * a;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}