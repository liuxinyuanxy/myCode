#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <queue>
#include <vector>
#define il inline
#define re register
#define gc getchar
#define LL long long
#define int LL
using namespace std;
struct io
{
	char obuf[200 << 20], *t;
	int a[40];
	io() : t(obuf)
	{
	}
	~io()
	{
		fwrite(obuf, 1, t - obuf, stdout);
	}
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
int p, T;
namespace sub1
{
const int MAXN = 10000000;
int pri[MAXN], cnt, vis[MAXN + 10], phi[MAXN + 10], two[MAXN + 10];
void init()
{
	phi[1] = 1;
	two[0] = 1;
	two[1] = 2;
	for (int i = 2; i <= MAXN; ++i)
	{
		two[i] = (two[i - 1] << 1) % p;
		if (!vis[i])
			pri[++cnt] = i, phi[i] = i - 1;
		for (int j = 1; j <= cnt && i * pri[j] <= MAXN; ++j)
		{
			vis[i * pri[j]] = 1;
			if (i % pri[j])
				phi[i * pri[j]] = phi[i] * phi[pri[j]] % p;
			else
			{
				phi[i * pri[j]] = phi[i] * pri[j] % p;
				break;
			}
		}
	}
}
il int qpow(int a, int b)
{
	// cerr << __LINE__ << endl;
	int ans = 1;
	for (; b; b >>= 1, a = a * a % p)
		if (b & 1)
			ans = ans * a % p;
	return ans;
}
int get(int o)
{
	// cerr << __LINE__ << endl;
	if (o <= MAXN)
		return phi[o];
	int ans = o;
	for (int i = 2; i <= sqrt(o); ++i)
	{
		// cerr << i << endl;
		if (o % i == 0)
			ans -= ans / i;
		while (o % i == 0)
			o /= i;
	}
	if (o != 1)
		ans -= ans / o;
	return ans;
}
int get2(int o)
{
	// cerr << __LINE__ << endl;
	if (o <= MAXN)
		return two[o];
	return qpow(2, o);
}
void solve()
{
	init();
	while (T--)
	{
		// cerr << __LINE__ << endl;
		int n;
		read(n);
		int S = 0;
		for (int i = 1; i <= sqrt(n); ++i)
			if (n % i == 0)
			{
				S = (S + get2(n / i) * 1ll * get(i) % p) % p;
				if (i != n / i)
					S = (S + get2(i) * 1ll * get(n / i) % p) % p;
			}
		print(S);
	}
}
} // namespace sub1
namespace sub2
{
const int MAXN = 500000;
int cnt;
int pri[MAXN + 10], vis[MAXN + 10], phi[MAXN + 10], two[MAXN + 10], ans[MAXN + 10];
void init()
{
	phi[1] = 1;
	two[0] = 1;
	two[1] = 2;
	for (int i = 2; i <= MAXN; ++i)
	{
		two[i] = (two[i - 1] << 1) % p;
		if (!vis[i])
			pri[++cnt] = i, phi[i] = i - 1;
		for (int j = 1; j <= cnt && i * pri[j] <= MAXN; ++j)
		{
			vis[i * pri[j]] = 1;
			if (i % pri[j])
				phi[i * pri[j]] = phi[i] * phi[pri[j]] % p;
			else
			{
				phi[i * pri[j]] = phi[i] * pri[j] % p;
				break;
			}
		}
	}
	for (int i = 1; i <= MAXN; ++i)
		for (int j = i; j <= MAXN; j += i)
		{
			ans[j] += phi[i] * 1ll * two[j / i] % p;
			ans[j] %= p;
		}
}
void solve()
{
	init();
	while (T--)
	{
		int x;
		read(x);
		print(ans[x]);
	}
}
} // namespace sub2
signed main()
{
	read(T), read(p);
	if (T <= 10007)
		sub1::solve();
	else
		sub2::solve();
}