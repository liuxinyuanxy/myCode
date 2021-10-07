#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#define gc getchar
#define LL long long
using namespace std;
const int MAXN = 33000000;
char ch[MAXN];
int p[MAXN];
int main()
{
    char c;
    ch[0] = '$';
    int len = 1;
    ch[1] = '#';
    while (c = gc(), !isalpha(c))
        ;
    while (ch[++len] = c, ch[++len] = '#', c = gc(), isalpha(c))
        ;
    int mx = 0, id = 0, ans = 0;
    for (int i = 1; i <= len; ++i)
    {
        if (mx > i)
            p[i] = min(p[id * 2 - i], mx - i);
        else
            p[i] = 1;
        while (ch[i - p[i]] == ch[i + p[i]])
            ++p[i];
        if (i + p[i] - 1 > mx)
            mx = i + p[i] - 1, id = i;
        ans = max(ans, p[i] - 1);
    }
    printf("%d\n", ans);
    return 0;
}