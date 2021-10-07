#include <iostream>
#include <cstdio>
#include <vector>
#define il inline
#define re register
#define ll long long
#define rt register int
#define rc register char
#define rll register long long
#define pf(x) printf("%d", x)
#define pf2(x, y) printf("%d %d", x, y)
#define sf(x) scanf ("%d", &x)
#define sf2(x, y) scanf ("%d%d", &x, &y)
#define pfl(x) printf("%lld", x)
#define pfl2(x, y) printf("%lld%lld", x, y)
#define sfl(x) scanf ("%lld", &x)
#define sfl2(x, y)	scanf ("%lld%lld", &x, &y)
#define jia(a, b) (((a) + (b)) % MOD)
#define jian(a, b) (((a) - (b)) % MOD)
#define cheng(a, b) (((a) * (b)) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfjian(a, b) (a) = ((a) - (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b)) % MOD
#define selfmax(x, y) (x) = max((x), (y))
#define mid(x, y) (((x) + (y)) >> 1)
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define min(a, b) ((a) > (b) ? (b) : (a))
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int tot;
vector<vector<int> > vv;
vector<int> temp;
bool check(rt a, rt b)
{
	return (a & b) >= min(a, b);
}
int main()
{
	freopen("in.txt", "r", stdin);
	int n, k, p;
	int len;
	bool hs1, hs2;
	sf2(n, k);
	rep(i, 1, n)
	{
		sf(p);
		hs1 = 0;
		rep(j, 1, tot)
		{
			len = vv[j - 1].size();
			hs2 = 1;
			rep(k, 1, len)
				if (check(p, vv[j - 1][k - 1]))
				{
					hs2 = 0;
					break;
				}
			if (hs2)
			{
				vv[j - 1].push_back(p);
				hs1 = 1;
				break;
			}
		}
		if  (!hs1)
		{
			++tot;
			vv.push_back(temp);
			vv[tot - 1].push_back(p);
		}
	}
	putchar('1');
	putchar('\n');
	pf(tot);
	putchar('\n');
	rep(i, 1, tot)
	{
		len = vv[i - 1].size();
		pf(len);
		putchar(' ');
		rep(j, 1, len)
			pf(vv[i - 1][j - 1]),
			putchar(' ');
		putchar('\n');
	}
	return 0;
}

