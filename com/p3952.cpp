#include <iostream>
#include <cstdio>
#include <cstring>
#define il inline
#define re register
#define ll long long
#define rt register int
#define rc register char
#define rll register long long
#define pf(x) printf("%d", x)
#define pf2(x, u) printf("%d %d", x, y)
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
#define mid(x, y) ((x) + (y) >> 1)
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = 1; (x) <= (a); (x) += (b))
using namespace std;
bool is[300];
bool vis[100];
int sta[300], top;
int ans, cnt;
char now;
int from, to;
il int d_o()
{
	rt s = 0;
	rc ch;
	ch = getchar();
	while (ch != '(')
		ch = getchar();
	ch = getchar();
	while (ch != '1' && ch != 'n')
		ch = getchar();
	if (ch == '1')
		return -1;
	ch = getchar();
	while (ch < '0' || ch > '9')	
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0',
		ch = getchar();
	return s;
}
bool o_o()
{
	char ch;
	from = to = 0;
	ch = getchar();
	while (ch != 'F' && ch != 'E')	
		ch = getchar();
	if (ch == 'E')
		return 0;
	ch = getchar();
	while (ch < 'a' || ch > 'z')
		ch = getchar();
	now = ch;
	ch = getchar();
	while ((ch != 'n') && (ch < '0' || ch > '9'))
		ch = getchar();
	if (ch == 'n')
		from = -1;
	else
	{
		while (ch >= '0' && ch <= '9')
			from = from * 10 + ch - '0',
			ch = getchar();
	}
	ch = getchar();
	while ((ch != 'n') && (ch < '0' || ch > '9'))
		ch = getchar();
	if (ch == 'n')
		to = -1;
	else
	{
		while (ch >= '0' && ch <= '9')
			to = to * 10 + ch - '0',
			ch = getchar();
	}
	return 1;
}
int main()
{
	bool wr;
	bool p = 1;
	int t, line, o;
	sf(t);
	while (t--)
	{
		memset(vis, 0, sizeof(vis));
		memset(is, 0, sizeof(is));
		wr = 0;
		p = 1;
		cnt = ans = 0;
		top = 0;
		sf(line);
		o = d_o();
		for (int i = 1; i <= line; ++i)
		{
			if (o_o())
			{
				if (wr)
					continue;
				if (vis[now - 'a'])
				{
					wr = 1;
					continue;
				}
				vis[now - 'a'] = 1;
				++top;
				sta[top] = now - 'a';
				if (from != -1 && to == -1)
				{
					if (p)
						is[top] = 1,
						++cnt,
						ans = max(ans, cnt);	
				}
				else
				{
					if ((from == -1 && to != -1) || (from > to))
						p = 0;
					is[top] = 0;
				}
			}
			else
			{
				if (wr)
					continue;
				if (!top)
				{
					wr = 1;
					continue;
				}
				vis[sta[top]] = 0;
				if (!p)
					p = 1;
				if (is[top])
					--cnt;
				--top;
			}
//			cout << "\t\t\t\t\t" << cnt << endl;
		}
		if (top)
		{
			wr = 1;
		}
		if (wr)
		{
			printf("ERR\n");
		}
		else
		{
//			cout << ans << "\t\t" << o << endl;
			if ((!ans && o == -1) || (ans == o))
			{
				printf("Yes\n");
			}
			else
				printf("No\n");
		}
	}
	return 0;
}

