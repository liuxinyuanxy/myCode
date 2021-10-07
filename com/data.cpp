#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
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
#define rep(x, a, b) for (rt (x) = 1; (x) <= (a); (x) += (b))
using namespace std;
int main()
{
	freopen("zero.in", "w", stdout);
	srand(time(NULL));
	cout << 150 << endl;
	rep(i, 150, 1)	
		cout << (rand()%1000000) * (pow(-1, rand())) << " ";
	cout << endl;
	rep(i, 150, 1)	
		cout << (rand()%1000000) * (pow(-1, rand())) << " ";
	cout << endl;
	rep(i, 150, 1)	
		cout << (rand()%1000000) * (pow(-1, rand())) << " ";
	cout << endl;
	rep(i, 150, 1)	
		cout << (rand()%1000000) * (pow(-1, rand())) << " ";
	cout << endl;
	rep(i, 150, 1)	
		cout << (rand()%1000000) * (pow(-1, rand())) << " ";
	cout << endl;
	return 0;
}

