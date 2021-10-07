#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define il inline
#define re register
#define gc getchar
#define LL long long
using namespace std;
template <typename T>
void read(T &s)
{
    s = 0;
    bool p = 0;
    char ch;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= p ? -1 : 1;
}
const int MAXN = 200000;
int head[MAXN], nxt[MAXN], to[MAXN], val[MAXN];
int cnt;
int n, m, s, t;
void ins(int u, int v, int w)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    val[cnt] = w;
}
void insert(int u, int v, int w)
{
    ins(u, v, w);
    ins(v, u, w);
}
typedef pair<LL, int> P;
bool done[MAXN];
priority_queue<P, vector<P>, greater<P>> pq;
LL dis[MAXN];
void dij()
{
    fill(dis + 1, dis + 1 + n, -1);
    dis[s] = 0;
    pq.push(P(0, s));
    while (!pq.empty())
    {
        P w = pq.top();
        pq.pop();
        int u = w.second;
        if (done[u])
            continue;
        done[u] = 1;
        if (u == t)
            return;
        for (int i = head[u], v; v = to[i], i; i = nxt[i])
            if (!~dis[v] || dis[v] > dis[u] + val[i])
            {
                dis[v] = dis[u] + val[i];
                pq.push(P(dis[v], v));
            }
    }
}
int main()
{
    read(n), read(m), read(s), read(t);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        read(u), read(v), read(w);
        insert(u, v, w);
    }
    dij();
    cout << dis[t];
    return 0;
}