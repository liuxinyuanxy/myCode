#include <iostream>
#include <cstdio>
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
#define _ 1505
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
pii qu[_ * _], temp, nxt;
int n, m, sx, sy, l, r;
int a[_][_], vis[_ << 2][_ << 2];
const int mx[] = {-1, 0, 1, 0}, my[] = {0, 1, 0, -1};
bool bfs()
{
	rt tx, ty;
	l = r = 0;
	temp.first = sx;
	temp.second = sy;
	qu[r++] = temp;
	while (l != r)
	{
		temp = qu[l++];
		if (l > _ * (_ - 1))
			l = 0;
		rep (i, 0, 3)
		{
			tx = mx[i] + temp.first;
			ty = my[i] + temp.second;
			if (tx + n < 1 || ty + m < 1 || tx + n > 3 * n || ty + m > 3 * m)
				continue;
			if (vis[tx + n][ty + m])
				continue;
			if (!a[(tx + n - 1) % n + 1][(ty + m - 1) % m + 1])
				continue;
			if (a[(tx + n - 1) % n + 1][(ty + m - 1) % m + 1] == 2)
				return true;
			vis[tx + n][ty + m] = 1;
			nxt.first = tx;
			nxt.second = ty;
			qu[r++] = nxt;
			if (r > _ * (_ - 1))
				r = 0;
		}
	}
	return false;
}
int main()
{
	rc ch;
	while (~sf2(n, m))
	{
		rep (i, 1, n)
			rep (j, 1, m)
			{
				ch = getchar();
				while (ch != 'S' && ch != '.' && ch != '#')
					ch = getchar();
				ch == '#' ? a[i][j] = 0 : a[i][j] = 1;
				if (ch == 'S')
					sx = i,
					sy = j,
					a[i][j] = 2,
					vis[i + n][j + m] = 1;
			}
		if (bfs())
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}

