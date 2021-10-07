#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct node{
	int a, b, c;
}f[10005];
typedef pair<int, int> P;
int is[10005];
priority_queue<P, vector<P>, greater<P> > pq;
int main()
{
	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf ("%d%d%d", &f[i].a, &f[i].b, &f[i].c);
		pq.push(P(f[i].a + f[i].b + f[i].c, i));
		is[i] = 1;
	}
	P now;
	int id;
	for (int i = 1; i <= m; ++i)
	{
		now = pq.top();
		pq.pop();
		id = now.second;
		printf("%d ", now.first);
		++is[id];
		pq.push(P(f[id].a * is[id] * is[id] + f[id].b * is[id] + f[id].c, id));
	}
	return 0;
}

