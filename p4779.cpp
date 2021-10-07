#include <iostream>
#include <cstdio>
#include <queue>
#define MAX 1000000
using namespace std;
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P> > pq;
int b[MAX];
int pre[MAX], nxt[MAX], a[MAX];
bool vis[MAX];
int main()
{
	P now;
	int n, k, ans = 0, id;
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
	{
		scanf ("%d", &b[i]);
	}
	for (int i = 1; i < n; ++i)
	{
		a[i] = b[i + 1] - b[i];
		pre[i] = i - 1;
		nxt[i] = i + 1;
		pq.push(P(a[i], i));
	}
	a[0] = a[n] = 0x5fffffff;
	for (int i = 1; i <= k; ++i)
	{
		now = pq.top();
		pq.pop();
		id = now.second;
		while (vis[id])
		{
			now = pq.top();
			pq.pop();
			id = now.second;
		}
		ans += now.first;
		a[id] = a[pre[id]] + a[nxt[id]] - a[id];
		vis[pre[id]] = vis[nxt[id]] = 1;
		pre[id] = pre[pre[id]], nxt[pre[id]] = id;
		nxt[id] = nxt[nxt[id]], pre[nxt[id]] = id;
		pq.push(P(a[id], id));
	}
	printf("%d", ans);
	return 0;
}
