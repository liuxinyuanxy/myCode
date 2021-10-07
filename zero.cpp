#include <cstdio>
#include <cstring>
#include <algorithm>
#define E 40010
using namespace std;

int n, a[E], b[E], c[E];
int a1[E], a2[E], a3[E], a4[E];

int main()
{
	freopen("zero.in", "r", stdin);
	freopen("zero.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	    scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	    scanf("%d", &a1[i]);
	for (int i = 1; i <= n; i++)
	    scanf("%d", &a2[i]);   
	for (int i = 1; i <= n; i++)
	    scanf("%d", &a3[i]);
	for (int i = 1; i <= n; i++)
	    scanf("%d", &a4[i]);
	
	for (int i = 1; i <= n; i++)
	    for (int j = 1; j <= n; j++)
		    b[(i-1)*n+j] = a1[i] + a2[j];
	for (int i = 1; i <= n; i++)
	    for (int j = 1; j <= n; j++)
		    c[(i-1)*n+j] = a3[i] + a4[j];
	
	sort(b+1, b+1+n*n);
	sort(c+1, c+1+n*n);
	
    for (int k = 1; k <= n; k++)
	{
		int x = -a[k], i = n*n;
		for (int j = 1; j <= n*n; j++)
		{
			while (i > 1 && b[j] + c[i] > x) i--;
			if (b[j] + c[i] == x) { printf("YES\n"); return 0; }
		}
    }
    
    printf("NO\n");
    
	return 0;
}
