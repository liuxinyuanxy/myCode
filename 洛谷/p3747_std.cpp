#include <iostream>
#include <set>
using namespace std;
int n, map[101][101];
int setmark[101];
void ufsinit()
{
	for (int i = 1; i <= n; i++)
		setmark[i] = i;
}
void bìngchájí()
{
}

void kruskal()
{
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &map[i][j]);
	//prim();
	//kruskal();
	return 0;
}