#include <iostream>
#include <cstdio>
#define MAXN 55
#define MAXM 55
using namespace std;
typedef pair<int, int> P;
const int mx[] = {-1, 0, 1, 0};
int a[MAXN][MAXM], dis, l, r;
P s, t;
P qu[MAXN * MAXM * 4];
char ch;
bool vis[MAXN][MAXM][4];
void bfs(P u)
{
	P now;
	qu[l++] = u;
	while (l != u)
	{
		for (int i = 0; i < 4; ++i)
		{
			
		}
	}
}
int main()
{
	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			scanf ("%d",&a[i][j]);
		}
	}
	scanf ("%d%d%d%d", &s.first, &s.second, &t.first, &t.second);
	cin >> ch;
	ch == 'E' ? dis = 1 : ch == 'S' ? dis = 2 : ch == 'W' ? dis = 3 : dis = 4;
	bfs(s);
	return 0;
}

