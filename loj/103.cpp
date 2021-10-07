#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 2000000;
char a[MAXN], b[MAXN];
int lena, lenb;
int p[MAXN];
int main()
{
    cin >> (a + 1) >> (b + 1);
    lena = strlen(a + 1);
    lenb = strlen(b + 1);
    for (int i = 2; i <= lenb; ++i)
    {
        p[i] = p[i - 1];
        while (b[p[i] + 1] != b[i] && p[i])
            p[i] = p[p[i]];
        if (b[p[i] + 1] == b[i])
            ++p[i];
    }
    int j = 0;
    for (int i = 1; i <= lena; ++i)
    {
        while (a[i] != b[j + 1] && j)
            j = p[j];
        if (a[i] == b[j + 1])
            ++j;
        if (j == lenb)
        {
            j = p[j];
            printf("%d\n", i - lenb + 1);
        }
    }
    for (int i = 1; i <= lenb; ++i)
        printf("%d ", p[i]);
    return 0;
}