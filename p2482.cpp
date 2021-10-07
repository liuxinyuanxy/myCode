#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define il inline
#define re register
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
#define selfmin(x, y) (x) = min((x), (y)) 
#define selfmax(x, y) (x) = max((x), (y))
#define mid(x, y) (((x) + (y)) >> 1)
#define MOD 1000000007
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
vector<int> v[100];
char ch[100];
int s[100];
int k, l, ans;
int check(rt tc, rt pos, const int& sze)
{
	rt ans = 1;
	rt l = pos - 1, r = pos + 1, ll = v[tc][pos], rr = v[tc][pos];
	rt used = 0;
	while (true)
	{
		if (l < 0 && r >= sze)
			break;
		if (l < 0)
			used += v[tc][r] - rr - 1, ++rr, ++r;
		else
		if (r >= sze)
			used += (ll - v[tc][l] - 1), --ll, --l;
		else
		if (ll - v[tc][l] < v[tc][r] - rr)
			used += (ll - v[tc][l] - 1), --ll, --l;
		else
			used += v[tc][r] - rr - 1, ++rr, ++r;
		if (used > k)
			break;
		++ans;
	}
//	cout << tc << "\t" << pos << "\t" << ans << endl;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> (ch + 1);
	cin >> k;
	l = strlen(ch + 1);
	if (k == 0)
	{
		s[1] = ans = 1;
		rep (i, 2, l)
			s[i] = (ch[i] == ch[i - 1] ? s[i - 1] : 0) + 1,
			selfmax(ans, s[i]);
	}
	else
	{
		int sze;
		rep (i, 1, l)
			v[ch[i] - 'A'].push_back(i);
		if (k >= l * l)
		{
			rep (i, 'A', 'Z')
			{
				sze = v[i - 'A'].size();
				selfmax(ans, sze);
			}
		}
		else
		{
			rep (i, 'A' - 'A', 'Z' - 'A')
			{
				sze = v[i].size();
				rep (j, 0, sze - 1)
					selfmax(ans, check(i, j, sze));
			}	
		}
	}
	pf (ans);
	return 0;
}

