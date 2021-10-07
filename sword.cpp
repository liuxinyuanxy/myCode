#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
	freopen("sword.in", "r", stdin);
	freopen("sword.out", "w", stdout);
	 
	int T;
	scanf("%d", &T);
	while (T--)
	{
		LL a, b;
		scanf("%lld%lld", &a, &b);
		LL ans = 0;
		while (a != b)
		{
			if (a < b) swap(a, b);
			if (a % b == 0) { ans += a/b - 1; break; }
			ans += a/b;
			a %= b;
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
