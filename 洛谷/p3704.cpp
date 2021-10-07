#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#define il inline
#define re register
#define gc getchar
#define LL long long
// #define int long long
using namespace std;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
// char buf[1 << 21], *p1 = buf, *p2 = buf;

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
const int MOD = 1000000007;
const int MAXN = 1000000;
int f[MAXN + 10], mu[MAXN + 10];
int vis[MAXN + 10], pri[MAXN], cnt;
int F[MAXN + 10];
int qpow(int a, int b, int p)
{
	int ans = 1;
	for (; b; b >>= 1, a = (a * 1ll * a) % p)
		if (b & 1)
			ans = (ans * 1ll * a) % p;
	return ans;
}
void init()
{
	f[1] = 1;
	for (int i = 2; i <= MAXN; ++i)
		f[i] = (f[i - 1] + f[i - 2]) % MOD;
	for (int i = 2; i <= MAXN; ++i)
	{
		if (!vis[i])
			pri[++cnt] = i,
			mu[i] = -1;
		for (int j = 1; j <= cnt && i * pri[j] <= MAXN; ++j)
		{
			vis[i * pri[j]] = 1;
			if (i % pri[j])
				mu[i * pri[j]] = -mu[i];
			else
				break;
		}
	}
	mu[1] = 1;
	for (int i = 1; i <= MAXN; ++i)
		F[i] = 1;
	for (int i = 1; i <= MAXN; ++i)
	{
		int t = qpow(f[i], MOD - 2, MOD);
		for (int j = 1; j * i <= MAXN; ++j)
			F[i * j] = (F[i * j] * 1ll * (mu[j] == 0 ? 1 : mu[j] == 1 ? f[i] : t)) % MOD;
	}
	F[0] = 1;
	for (int i = 2; i <= MAXN; ++i)
		F[i] = (F[i] * 1ll * F[i - 1]) % MOD;
}

signed main()
{
	init();
	int T;
	read(T);
	while (T--)
	{
		int ans = 1;
		int n, m;
		read(n), read(m);
		for (int l = 1, r; l <= min(n, m); l = r + 1)
		{
			r = min(n / (n / l), m / (m / l));
			ans = (ans * 1ll * qpow(F[r] * 1ll * qpow(F[l - 1], MOD - 2, MOD) % MOD, (n / l) * 1ll * (m / l) % (MOD - 1), MOD)) % MOD;
		}
		if (ans < 0)
			ans += MOD;
		print(ans);
	}
}