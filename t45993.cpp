#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#define ll long long
using namespace std;
set<ll> S;
map<ll, ll> M;
int main()
{
	ll n, m, t;
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; ++i)
	{
		scanf("%lld", &t);
		S.insert(m+i-t);
		S.insert(m+i+t);
		++M[m+i-t];
		++M[m+i+t];
	}
	ll ans = 0;
	for (auto x : S)
	{
		t = M[x];
		ans += t * (t - 1) / 2;
	}
	printf("%lld", ans);
	return 0;
}

