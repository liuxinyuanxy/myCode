#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    freopen("in.txt", "w", stdout);
    srand(time(NULL));
    long long n =  1000000;
    for (long long i = 1; i <= n; ++i)
    {
        int x = rand() % 100 + 1;
        for (int j = 1; j <= x; ++j)
        {
            int ch = rand() % 26;
            putchar(ch + 'a');
        }
        putchar('\n');
    }
    return 0;
}
