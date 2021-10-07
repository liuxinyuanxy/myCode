#include <iostream>
#include <cstdio>
#include <queue>
#define ll long long
#define MAX 10000000
using namespace std;
typedef pair<ll, int> P;
ll a[MAX];
ll b[MAX];
bool vis[MAX];
int tot, ii[MAX], l[MAX], r[MAX];
priority_queue<P, vector<P>, greater<P> > pq;
int main()
{
	P now;
	int n, k, id;
	ll val;
	ll ma = 0;
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
	{
		ii[i] = i;
		l[i] = i;
		r[i] = i;
		scanf ("%lld", &b[i]);
	}
	for (int i = 2; i <= n; ++i)
	{
		a[i] = b[i] - b[i - 1];
		pq.push(P(a[i], i));
	}
	tot = n;
	for (int i = 1; i <= k; ++i)
	{
		now = pq.top();
		val = now.first;
		id = now.second;
		pq.pop();
		while (vis[id] && !pq.empty())
		{
			now = pq.top();
			val = now.first;
			id = now.second;
			pq.pop();	
		}
		ma += now.first;
		++tot;
		a[tot] = a[ii[l[id] - 1]] + a[ii[r[id] + 1]] - val;
		vis[ii[l[id] - 1]] = vis[ii[r[id] + 1]] = 1;
		if (l[id] - 1 == 1)
			continue;
		l[tot] = max(2, l[ii[l[id] - 1]]);
		r[tot] = min(n, r[ii[r[id] + 1]]);
		ii[l[tot]] = ii[r[tot]] = tot;
		pq.push(P(a[tot], tot));
	}
	printf("%lld", ma);
	return 0;
}

