#include <iostream>
#include <cstdio>
#include <queue>
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
#define m_p make_pair
#define pii pair<int, int>
#define piii pair<pii, int>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
const int mx[] = {-1, 0, 1, 0}, my[] = {0, 1, 0, -1};
priority_queue<piii, vector<piii>, greater<piii> > pq;
int a[105][105];
bool done[2000000];
int main()
{
	rt m, n, nx, ny, tx, ty, x, y, c;
	piii now;
	sf2(m, n);
	rep (i, 1, n)
	{
		sf2(x, y),
		sf(c);
		++c;
		a[x][y] = c;
	}
	pq.push(m_p(m_p(0, 1), -1));
	while (!pq.empty())
	{
		now = pq.top();
		pq.pop();
		if (now.first.second == m * m)
		{
			pf(now.first.first);
			return 0;
		}
		if (done[now.first.second])
			continue;
		done[now.first.second] = 1;
		nx = now.first.second / m + 1;
		ny = now.first.second - (nx - 1) * m;
		if (!ny)
			--nx,
			ny = m;
		rep (i, 0, 3)
		{
			tx = nx + mx[i];
			ty = ny + my[i];
			if (tx < 1 || tx > m || ty < 1 || ty > m)
				continue;
			if (done[(tx - 1) * m + ty])
				continue;
			if (!a[tx][ty] && !a[nx][ny])
				continue;
			if (!a[nx][ny])
				pq.push(m_p(m_p(now.first.first + (now.second == a[tx][ty] ? 0 : 1), (tx - 1) * m + ty), -1));
			if (a[nx][ny] == a[tx][ty])
				pq.push(m_p(m_p(now.first.first, (tx - 1) * m + ty), -1));
			else
				if (!a[tx][ty])
					pq.push(m_p(m_p(now.first.first + 2, (tx - 1) * m + ty), a[nx][ny]));
				else
					pq.push(m_p(m_p(now.first.first + 1, (tx - 1) * m + ty), -1));
		}
	}
	pf(-1);
	return 0;
}
