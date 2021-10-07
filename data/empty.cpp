#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define space putchar(' ')
#define enter putchar('\n')
template <class T>
bool read(T &x){
    char c;
    bool op = 0;
    while(c = getchar(), c < '0' || c > '9')
        if(c == '-') op = 1;
        else if(c == EOF) return 0;
    x = c - '0';
    while(c = getchar(), c >= '0' && c <= '9')
        x = x * 10 + c - '0';
    if(op) x = -x;
    return 1;
}
template <class T>
void write(T x){
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) write(x / 10);
    putchar('0' + x % 10);
}


const int N = 50005, M = 2000005;
int n, Q, ans[N], a[N], lst[N], cnt, num[N]; //用于离散化
int idx, sum[M], lson[M], rson[M], root[N];
struct Query{
    int id, l, r, x;
    bool operator < (const Query &b) const{
        return r < b.r;
    }
} q[N];

void build(int &k, int l, int r){
    k = ++idx;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(lson[k], l, mid);
    build(rson[k], mid + 1, r);
}
void change(int old, int &k, int l, int r, int p, int x){
    k = ++idx;
    lson[k] = lson[old], rson[k] = rson[old];
    sum[k] = sum[old] + x; //先复制一波之前的节点，顺便修改区间和
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(p <= mid) change(lson[k], lson[k], l, mid, p, x);
    else change(rson[k], rson[k], mid + 1, r, p, x);
}
int query(int new_k, int old_k, int l, int r, int x){ //查询第x小
    if(l == r) return l;
    int mid = (l + r) >> 1, sum_right = sum[rson[new_k]] - sum[rson[old_k]];
    if(sum_right >= x)
        return query(rson[new_k], rson[old_k], mid + 1, r, x);
    else
        return query(lson[new_k], lson[old_k], l, mid, x - sum_right);
}
int find(int x){
    return lower_bound(num + 1, num + cnt + 1, x) - num;
}

int main(){
    read(n);
    for(int i = 1; i <= n; i++)
        read(lst[i]), a[i] = lst[i];
    sort(lst + 1, lst + n + 1);
    for(int i = 1; i <= n; i++)
        if(i == 1 || lst[i] != lst[i - 1])
            num[++cnt] = lst[i];
    build(root[0], 1, cnt);
    read(Q);
    for(int i = 1; i <= Q; i++){
        q[i].id = i;
        read(q[i].l), q[i].l++;
        read(q[i].r), q[i].r++;
        read(q[i].x);
    }
    sort(q + 1, q + Q + 1);
    for(int i = 1, j = 1; i <= n; i++){
        change(root[i - 1], root[i], 1, cnt, find(a[i]), 1);
        while(q[j].r == i)
            ans[q[j].id] = query(root[i], root[q[j].l - 1], 1, cnt, q[j].x), j++;
    }
    for(int i = 1; i <= Q; i++)
        printf("%d\n", num[ans[i]]);
    return 0;
}
