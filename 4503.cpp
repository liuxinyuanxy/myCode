#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, l, s;
int ans1,ans;
unsigned long long hs[30005];
unsigned long long temp[30005];
char ch[30005][300];
unsigned long long pw[300] = {1};
inline void init()
{
    for (int i = 1; i <= l; ++i)
    {
        pw[i] = pw[i-1] * 131;
    }
}
inline void h(int i)
{
    for (int j = 0; j < l; ++j)
        hs[i] = hs[i] * 131 + ch[i][j];
}
int main()
{
    scanf("%d%d%d", &n, &l, &s);
    init();
    for (int i = 1; i <= n; ++i)
    {
        cin >> ch[i];
        h(i);
    }
    for (int i = 0; i < l; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            temp[j] = hs[j] - (unsigned long long)(pw[l - i - 1] * ch[j][i]);
        }
        sort(temp + 1, temp + 1 + n);
        ans1 = 0;
        for (int j = 2; j <= n; ++j)
        {
            if (temp[j] == temp[j - 1])
                ++ans1;
            else
                ans += ans1*(ans1+1)/2,
                ans1 = 0;
        }
        ans += ans1*(ans1+1)/2;
    }
    printf("%d", ans);
    return 0;
}
