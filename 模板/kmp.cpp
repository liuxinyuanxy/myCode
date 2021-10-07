//kmp
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int len1, len2;
int nxt[1000005];
char s1[1000005], s2[1000005];
int main()
{
    ios::sync_with_stdio(false);
    int p;
    cin >> (s1 + 1) >> (s2 + 1);
    len1 = strlen(s1 + 1),
    len2 = strlen(s2 + 1);
    nxt[1] = 0;
    for (int i = 2; i <= len1; ++i)
    {
        p = nxt[i - 1];
        while (p && s2[p + 1] != s2[i])
            p = nxt[p];
        if (s2[p + 1] == s2[i])
            nxt[i] = p + 1;
        else
            nxt[i] = 0;
    }
    p = 0;
    for (int i = 1; i <= len1; ++i)
    {
        while (p && s1[i] != s2[p + 1])
            p = nxt[p];
        if (s1[i] == s2[p + 1])
            ++p;
        else
            p = 0;
        if (p == len2)
        {
            cout << i - len2 + 1 << endl;
            p = nxt[p];
        }
    }
    for (int i = 1; i <= len2; ++i)
        cout << nxt[i] << " ";
    return 0;
}
// abababc
// ababc
