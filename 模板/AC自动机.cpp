/*
AC自动机 
给定n个模式串和1个文本串，求有多少个模式串在文本串里出现过。 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int tot;
char minn = 127, maxx = 0;
queue <int> q;
int ans;
char ch[1000005];
struct node
{
    int son[30];
    int x;
    int fail;
}trie[1000005];
inline void add()
{
    int p = 0, len = strlen(ch);
    for (int i = 0; i < len; ++i)
    {
        minn = min(minn, ch[i]);
        maxx = max(maxx, ch[i]);
        if (!trie[p].son[ch[i] - 'a'])
            trie[p].son[ch[i] - 'a'] = ++tot,
            p = tot;
        else
            p = trie[p].son[ch[i] - 'a'];
    }
    ++trie[p].x;
}
inline void bfs()
{
    int p = 0;
    int t;
    trie[p].fail = 0;
    for (int i = minn; i <= maxx; ++i)
    {
        if (trie[0].son[i - 'a'])
        {
            q.push(trie[0].son[i - 'a']);
            trie[trie[0].son[i - 'a']].fail = 0;
        }
    }
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        for (int i = minn; i <= maxx; ++i)
        {
            t = trie[p].fail;
            if (trie[p].son[i - 'a'])
            {
                q.push(trie[p].son[i - 'a']);
                trie[trie[p].son[i - 'a']].fail = trie[t].son[i - 'a'];
            }
            else
                trie[p].son[i - 'a'] = trie[t].son[i - 'a'];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> ch;
        add();
    }
    bfs();
    cin >> ch;
    int len = strlen(ch);
    int p = 0;
    int temp;
    for (int i = 0; i < len; ++i)
    {
        p = trie[p].son[ch[i] - 'a'];
        temp = p;
        while (temp && trie[temp].x != -1)
        {
            ans += trie[temp].x;
            trie[temp].x = -1;
            temp = trie[temp].fail;
        }
    }
    cout << ans;
    return 0;
}
