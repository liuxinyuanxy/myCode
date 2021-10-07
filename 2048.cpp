#include <cstdio>
#include <cstring>
#define MOD 998244353LL
#define F 2100
using namespace std;

typedef long long LL;

int n, x, cnt = 0;
LL a[F], num[F];

void Read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
}

int main()
{
	freopen("2048.in", "r", stdin);
	freopen("2048.out", "w", stdout);
	
	Read(n);
	memset(num, 0, sizeof(num));
	memset(a, 0, sizeof(a));
	for (int i = 0; i <= 11; i++)
	    num[1<<i] = i;
	
	for (int i = 1; i <= n; i++)
	{
		Read(x);
		if (!num[x] && x != 1) { cnt++; continue; }
		
		for (int j = 2048; j >= 1; j--)
		    if (a[j])
		    {
		    	if (j + x <= 2048) a[j+x] = (a[j+x] + a[j]) % MOD;
		    	else a[2048] = (a[2048] + a[j]) % MOD;
			}
		a[x]++;
	}
	
	for (int i = 1; i <= cnt; i++)
	    a[2048] = a[2048] * 2LL % MOD;
	
	printf("%d\n", a[2048]);
	
	return 0;
}
