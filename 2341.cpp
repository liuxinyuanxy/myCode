#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<vector>
#include<map>
#include<queue>
#define rep(i, x, y) for (int i = (x); i <= (y); i ++)
#define down(i, x, y) for (int i = (x); i >= (y); i --)
#define mid (l+r)/2
#define lc o<<1
#define rc o<<1|1
#define pb push_back
#define mp make_pair
#define Pair pair<int, int>
#define F first
#define S second
#define B begin()
#define E end()
using namespace std;
typedef long long LL;
//head

const int N = 100010, LOG = 20;
int n, m, q, tot = 0;
int a[N], b[N];
int T[N], sum[N*LOG], L[N*LOG], R[N*LOG];

inline int build(int l, int r)
{
	int rt = ++ tot;
	if (l < r){
		L[rt] = build(l, mid);
		R[rt] = build(mid+1, r);
	}
	return rt;
}

inline int update(int pre, int l, int r, int x)
{
    printf("%d %d %d %d \n", pre, l, r, x);
	int rt = ++ tot;
	L[rt] = L[pre]; R[rt] = R[pre]; sum[rt] = sum[pre] + 1;
	if (l < r){
		if (x <= mid) L[rt] = update(L[pre], l, mid, x);
		else R[rt] = update(R[pre], mid+1, r, x);
	}
	return rt;
}

inline int query(int u, int v, int l, int r, int k)
{
	if (l == r) return l;
	int x = sum[L[v]] - sum[L[u]];
	if (x >= k) return query(L[u], L[v], l, mid, k);
	else return query(R[u], R[v], mid+1, r, k-x);
}

int main()
{
	int Test; scanf("%d", &Test);
	while (Test --){
		tot = 0;
		memset(T, 0, sizeof T); memset(sum, 0, sizeof sum);
		memset(L, 0, sizeof L); memset(R, 0, sizeof R);
		scanf("%d%d", &n, &q);
		rep(i, 1, n) scanf("%d", &a[i]), b[i] = a[i];
		sort(b+1, b+1+n);
		m = unique(b+1, b+1+n)-b-1;
		T[0] = build(1, m);
		rep(i, 1, n){
			a[i] = lower_bound(b+1, b+1+m, a[i]) - b;
			T[i] = update(T[i-1], 1, m, a[i]);
		}
		while (q --){
			int x, y, z; scanf("%d%d%d", &x, &y, &z);
			int p = query(T[x-1], T[y], 1, m, z);
			printf("%d\n", b[p]);
		}
	}
	return 0;
}
