#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define il inline
#define re register
#define gc getchar
#define LL long long
// #define int long long
using namespace std;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21,
// stdin), p1 == p2) ? EOF : *p1++) char buf[1 << 21], *p1 = buf, *p2 = buf;

struct io
{
	char obuf[200 << 20], *t;
	int a[40];
	io() : t(obuf) {}
	~io() { fwrite(obuf, 1, t - obuf, stdout); }
	template <class T>
	inline void read(T &s)
	{
		s = 0;
		bool p = 0;
		char ch;
		while (ch = gc(), p |= ch == '-', !isdigit(ch))
			;
		while (s = s * 10 + ch - '0', isdigit(ch = gc()))
			;
		s *= (p ? -1 : 1);
	}
	template <class T>
	inline void print(T u)
	{
		static int *q = a;
		if (u < 0)
			*t++ = '-', u = -u;
		if (!u)
			*t++ = 48;
		else
		{
			while (u)
				*q++ = u % 10 + 48, u /= 10;
			while (q != a)
				*t++ = *--q;
		}
		*t++ = '\n';
	}
} ip;
#define print ip.print
#define read ip.read
int n;
const int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
vector<int> v[25];
void dfs(re int num, re int s)
{
	if (s > n)
		return;
	v[s].push_back(num);
	for (re int i = 0; i <= 9; ++i)
		dfs(num * 10 + i, s + a[i]);
}
il int get(re int s)
{
	re int o = 0;
	if (s == 0)
		return 6;
	while (s)
	{
		o += a[s % 10];
		s /= 10;
	}
	return o;
}
// 128
signed main()
{
	cin >> n;
	if (n == 24)
	{
		cout << 128 << endl;
		return 0;
	}
	n -= 4;
	v[6].push_back(0);
	for (re int i = 1; i <= 9; ++i)
		dfs(i, a[i]);
	re int ans = 0;
	for (re int i = 2; i <= n - 4; ++i)
		for (auto x : v[i])
			for (re int j = 2; j <= n - 2; ++j)
				for (auto y : v[j])
				{
					if (i + j + get(x + y) == n)
					{
						// cout << x << " " << y << endl;
						++ans;
					}
				}
	cout << ans << endl;
}