#include <iostream>
int qpow(int a, int b, int p)
{
	int ans = 1;
	for (; b; b >>= 1, a = (a * 1ll * a) % p)
		if (b & 1)
			ans = (ans * 1ll * a) % p;
	return ans;
}
int main()
{
	int fac[1000], p, facinv[1000];
	p = 13;
	fac[0] = 1;
	for (int i = 1; i < p; ++i)
		fac[i] = (fac[i - 1] * i) % p;
	facinv[p - 1] = qpow(fac[p - 1], p - 2, p);
	for (int i = p - 2; i >= 1; --i)
		facinv[i] = (i + 1) * facinv[i + 1] % p;
	printf("%d\n", facinv[1]);
}