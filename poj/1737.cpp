#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define il inline
#define gc getchar
#define re register
#define LL long long
#define file ""
#ifdef DEBUG
#define D() cerr << __LINE__ << endl;
#define F()
#else
#define D()
#define F()                          \
	freopen(file ".in", "r", stdin); \
	freopen(file ".out", "w", stdout);
#endif
using namespace std;
template <typename T>
void read(T &s)
{
	s = 0;
	bool p = 0;
	char ch;
	while (ch = gc(), p |= ch == '-', !isdigit(ch))
		;
	while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
		;
	s *= p ? -1 : 1;
}
const int MAXN = 9999;
const int MAXSIZE = 1010;
const int DLEN = 4;
class bignum
{
public:
	int a[1000];
	int len;
	bignum()
	{
		len = 1;
		memset(a, 0, sizeof(a));
	}
	bignum(const char *);
	bignum(const int);
	bignum(const bignum &);
	bignum &operator=(const bignum &);
	friend istream &operator>>(istream &, bignum &);
	friend ostream &operator<<(ostream &, bignum &);
	bignum operator+(const bignum &) const;
	bignum operator-(const bignum &) const;
	bignum operator*(const bignum &)const;
	bignum operator/(const int &) const;
	bool operator>(const bignum &T) const;
	void print();
};
bignum::bignum(const char *s)
{
	int t, k, index, L, i;
	memset(a, 0, sizeof(a));
	L = strlen(s);
	len = L / DLEN;
	if (L % DLEN)
		len++;
	index = 0;
	for (i = L - 1; i >= 0; i -= DLEN)
	{
		t = 0;
		k = i - DLEN + 1;
		if (k < 0)
			k = 0;
		for (int j = k; j <= i; j++)
			t = t * 10 + s[j] - '0';
		a[index++] = t;
	}
}
bignum::bignum(const bignum &T) : len(T.len)
{
	int i;
	memset(a, 0, sizeof(a));
	for (i = 0; i < len; i++)
		a[i] = T.a[i];
}
bignum &bignum::operator=(const bignum &n)
{
	int i;
	len = n.len;
	memset(a, 0, sizeof(a));
	for (i = 0; i < len; i++)
		a[i] = n.a[i];
	return *this;
}
bignum::bignum(const int b)
{
	int c, d = b;
	len = 0;
	memset(a, 0, sizeof(a));
	while (d > MAXN)
	{
		c = d - (d / (MAXN + 1)) * (MAXN + 1);
		d = d / (MAXN + 1);
		a[len++] = c;
	}
	a[len++] = d;
}
istream &operator>>(istream &in, bignum &b)
{
	char ch[MAXSIZE * 5];
	int i = -1;
	in >> ch;
	int L = strlen(ch);
	int count = 0, sum = 0;
	for (i = L - 1; i >= 0;)
	{
		sum = 0;
		int t = 1;
		for (int j = 0; j < 4 && i >= 0; j++, i--, t *= 10)
			sum += (ch[i] - '0') * t;
		b.a[count] = sum;
		count++;
	}
	b.len = count++;
	return in;
}
ostream &operator<<(ostream &out, bignum &b)
{
	int i;
	cout << b.a[b.len - 1];
	for (i = b.len - 2; i >= 0; i--)
	{
		printf("%04d", b.a[i]);
	}
	return out;
}
bignum bignum::operator+(const bignum &T) const
{
	bignum t(*this);
	int i, big;
	big = T.len > len ? T.len : len;
	for (i = 0; i < big; i++)
	{
		t.a[i] += T.a[i];
		if (t.a[i] > MAXN)
		{
			t.a[i + 1]++;
			t.a[i] -= MAXN + 1;
		}
	}
	if (t.a[big] != 0)
		t.len = big + 1;
	else
		t.len = big;
	return t;
}
bignum bignum::operator-(const bignum &T) const
{
	int i, j, big;
	bool flag;
	bignum t1, t2;
	if (*this > T)
	{
		t1 = *this;
		t2 = T;
		flag = 0;
	}
	else
	{
		t1 = T;
		t2 = *this;
		flag = 1;
	}
	big = t1.len;
	for (i = 0; i < big; i++)
	{
		if (t1.a[i] < t2.a[i])
		{
			j = i + 1;
			while (t1.a[j] == 0)
				j++;
			t1.a[j--]--;
			while (j > i)
				t1.a[j--] += MAXN;
			t1.a[i] += MAXN + 1 - t2.a[i];
		}
		else
			t1.a[i] -= t2.a[i];
	}
	t1.len = big;
	while (t1.a[t1.len - 1] == 0 && t1.len > 1)
	{
		t1.len--;
		big--;
	}
	if (flag)
		t1.a[big - 1] = 0 - t1.a[big - 1];
	return t1;
}
bignum bignum::operator*(const bignum &T) const
{
	bignum ret;
	int i, j, up;
	int temp, temp1;
	for (i = 0; i < len; i++)
	{
		up = 0;
		for (j = 0; j < T.len; j++)
		{
			temp = a[i] * T.a[j] + ret.a[i + j] + up;
			if (temp > MAXN)
			{
				temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
				up = temp / (MAXN + 1);
				ret.a[i + j] = temp1;
			}
			else
			{
				up = 0;
				ret.a[i + j] = temp;
			}
		}
		if (up != 0)
			ret.a[i + j] = up;
	}
	ret.len = i + j;
	while (ret.a[ret.len - 1] == 0 && ret.len > 1)
		ret.len--;
	return ret;
}
bignum bignum::operator/(const int &b) const
{
	bignum ret;
	int i, down = 0;
	for (i = len - 1; i >= 0; i--)
	{
		ret.a[i] = (a[i] + down * (MAXN + 1)) / b;
		down = a[i] + down * (MAXN + 1) - ret.a[i] * b;
	}
	ret.len = len;
	while (ret.a[ret.len - 1] == 0 && ret.len > 1)
		ret.len--;
	return ret;
}
bool bignum::operator>(const bignum &T) const
{
	int ln;
	if (len > T.len)
		return true;
	else if (len == T.len)
	{
		ln = len - 1;
		while (a[ln] == T.a[ln] && ln >= 0)
			ln--;
		if (ln >= 0 && a[ln] > T.a[ln])
			return true;
		else
			return false;
	}
	else
		return false;
}
void bignum::print()
{
	int i;
	printf("%d", a[len - 1]);
	for (i = len - 2; i >= 0; i--)
		printf("%04d", a[i]);
	printf("\n");
}
bignum f[60];
bignum qpow(bignum a, int b)
{
	bignum ans = 1;
	for (; b; b >>= 1, a = a * a)
		if (b & 1)
			ans = ans * a;
	return ans;
}
bignum c[60][60];
int main()
{
	int n;
	c[0][0] = 1;
	for (int i = 1; i <= 50; ++i)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	f[1] = 1;
	for (int i = 2; i <= 50; ++i)
	{
		f[i] = qpow(2, i * (i - 1) / 2);
		bignum g = 0;
		for (int j = 1; j < i; ++j)
			g = g + c[i - 1][j - 1] * f[j] * qpow(2, (i - j) * 1ll * (i - j - 1) / 2);
		f[i] = f[i] - g;
	}
	while (read(n), n)
		f[n].print();
	return 0;
}
