#include <iostream>
#include <cstdio>
#define gc getchar
#define re register
#define il inline
using namespace std;
int T;
long long l, r;
void finish_line()
{
	char ch;
	while (ch = gc(), ch != '\n')
		;
}
void check()
{
	long long s = 0;
	long long s2 = 0;
	char ch;
	bool p = 0;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9')
		;
	if (ch == '0')
	{
		if (p)
		{
					cout << 0 << endl;
			finish_line();
			return;
		}
		ch = gc();
		if (ch == '\n')
			cout << 1 << endl;
		else
		{
			cout << 0 << endl;
			finish_line();
		}
		return;
	}
	while (ch >= '0' && ch <= '9')
	{
		if (s >= 10000000000ll)
			s2 = s2 * 10 + ch - '0';
		else
			s = s * 10 + ch - '0';
		if (!p)
		{
			if (s2 > r / 100000000000ll)
			{
				cout << 2 << endl;
				finish_line();
				return;
			}
		}
		else
		{
			if (l >= 0)
			{
				cout << 2 << endl;
				finish_line();
				return;
			}
			if (s2 > (-l) / 100000000000ll)
			{
				cout << 2 << endl;
				finish_line();
				return;
			}
		}
		ch = gc();
	}
	if (((s2 * 100000000000ll + s) * (p ? -1 : 1) > r) || ((s2 * 100000000000ll + s) * (p ? -1 : 1) < l))
		cout << 2 << endl;
	else
		cout << 1 << endl;
}
int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	cin  >> l >> r >> T;
	while (T--)
	{
		check();
	}
	return 0;
}