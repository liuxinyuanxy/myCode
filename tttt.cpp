#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define rt register int
using namespace std;
typedef pair<double, int> P;
int fa[505];
bool vis[505];
struct node{
	int u, v;
	double w;
}build[255000];
P ansx[505]; 
int ans[255000] = {0};
int tot = 0, cnt = 0;
struct Point{
	int x, y;
}po[505];
int find_root(int x)
{
	return x == fa[x] ? x : fa[x] = find_root(fa[x]);
}
inline int _read(){
    register char ch=getchar();rt sum=0;
    while(!(ch>='0'&&ch<='9'))ch=getchar();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum;
}
inline double dis(int i, int j)
{
	return sqrt((po[i].x - po[j].x) * (po[i].x - po[j].x) + (po[i].y - po[j].y) * (po[i].y - po[j].y));
}
inline bool cmp(const node& a, const node& b)
{
	return a.w < b.w;
}
int main()
{
	int s = _read(), p = _read();
	for (rt i = 1; i <= p; ++i)
	{
		po[i].x = _read(),
		po[i].y = _read();
		fa[i] = i;
 	}
	for (rt i = 1; i < p; ++i)
		for (rt j = i + 1; j <= p; ++j)
			build[++cnt].u = i,
			build[cnt].v = j,
			build[cnt].w = dis(i, j);
	sort(build + 1, build + 1 + cnt, cmp);
	for (int i = 1; i <= cnt; ++i)
	{
		int x = find_root(build[i].u), y = find_root(build[i].v);
		if (x != y)
		{
			ans[++tot] = i;			
			fa[x] = y;
		}
	}
	printf("%.2lf", build[ans[tot - s + 1]].w);
	return 0;
}

