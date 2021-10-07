#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (rt i = (a); i <= (b); ++i)
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define p_q priority_queue
#define pii pair <int, int>
#define piii pair <pii, int>
#define piiii pair <pii, pii>
#define pll pair <ll, ll>
#define plll pair <pll, ll>
#define pllll pair <pll, pll>
using namespace std;
int a[100];
il int rd()
{
	rt s = 0, p = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	if (ch == '0') p = 13, ch = gc();
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s + p;
}
int main()
{
	rt T = rd(), n = rd();
	while (T--)
	{
		rep (i, 1, n)
			++a[rd()],
			rd();
		
	}
	return 0;
}

