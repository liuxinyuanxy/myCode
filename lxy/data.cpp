#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int len[500005];
int lennow;
int main()
{
    freopen("zero.in", "w", stdout);
    srand(time(NULL));
    int n = 500000;
    cout << n << endl;
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        int opt = rand() % 5 + 1;
        if (i <= 100)
            opt = 1;
        else if (i <= 200)
            opt = 3;
        if (opt == 2 && lennow <= 1)
            opt = 1;
        if (opt == 2 && rand() % 10 != 0)
            opt = 3;
        if (opt != 3 && rand() % 3 == 0)
            opt = 3;
        cout << opt;
        if (opt == 2)
            --lennow;
        else if (opt == 1)
            ++lennow, cout << " " << char(rand() % 26 + 'a');
        else if (opt == 3)
            len[++cnt] = lennow;
        else if (opt == 4)
        {
            int x = rand() % cnt + 1;
            cout << " " << x << " " << rand() % len[x] + 1;
        }
        else
            cout << " " << rand() % cnt + 1 << " " << rand() % cnt + 1;
        cout << endl;
    }
}