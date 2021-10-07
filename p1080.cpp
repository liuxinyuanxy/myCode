#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct people{
    int a, b;
}emperor, minister[1010];

__int128 s, m;

bool cmp(people x, people y)
{
    return x.b*x.a < y.b*y.a;
}
void print(__int128 x)
{
	if (x > 9) 
		print(x / 10);
	putchar(x % 10 + '0');
}
int main()
{
    int n;
    cin >> n;
    cin >> emperor.a >> emperor.b;
    for (int i = 1; i <= n; ++i)
    {
        cin >> minister[i].a >> minister[i].b;
    }
    sort(minister+1, minister+n+1, cmp);
    s = emperor.a;
    for (int i = 1; i <= n; ++i)
    {
        m = max(m, s/minister[i].b);
        s *= minister[i].a;
    }
    print(m);
    return 0;
}

