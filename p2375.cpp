#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 1000005
using namespace std;
char ch[MAX];
long long ans;
long long num[MAX];
int nxt[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> ch;
        int len = strlen(ch), p = 0;
        ans = 1;
        num[0] = 0;
        num[1] = 1;
        for (int j = 1; j < len; ++j)
        {
            while (p && ch[j] != ch[p])
                p = nxt[p];
            if (ch[p] == ch[j])
                ++p;
            nxt[j + 1] = p;
            num[j + 1] = num[p] + 1;
        }
        p = 0;
        for (int j = 1; j < len; ++j)
        {
            while (p && ch[j] != ch[p])
                p = nxt[p];
            if (ch[p] == ch[j])
                ++p;
            while (p << 1 > j + 1)
            {
                p = nxt[p];
            }
            ans = ans * (num[p] + 1) % 1000000007;
        }
        cout << ans << endl;
    }
    return 0;
}
