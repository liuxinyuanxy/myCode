#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

namespace init
{
	template <class T>
	void rd(T& s)
	{
		bool p = 0;
		char ch;
		while (ch = getchar(), p |= ch == '-', ch < '0' || ch > '9');
		while (s = s * 10 + ch - '0', ch = getchar(), ch >= '0' && ch <= '9');
		s *= (p ? -1 : 1);
	}
	char rdch_int()
	{
		char ch;
		while (ch = getchar(), ch < '0' || ch > '9');
		return ch;
	}
	char rdch_alpha()
	{
		char ch;
		while (ch = getchar(), !isalpha(ch));
		return ch;
	}
} // init

namespace trie
{
	const int N = 100000;
	struct node{
		int son[100];
		int val;
		int x;
		int fail;
		node() { for (int i = 0; i < 100; ++i) son[i] = 0; val = x = fail = 0; }
	}trie[N];
	int head[N], nxt[N], val[N];
	int x[N];
	int root;
	int cnt;
	void add_normal(char* ch, int len)
	{
		int o = root;
		for (int i = 0 ; i < len; ++i)
		{
			if (trie[o].son[ch[i] - '0'])
			{
				o = trie[o].son[ch[i] - '0'];
			}
			else
			{
				trie[o].son[ch[i] - '0'] = ++cnt;
				o = cnt;
			}
		}
		++trie[o].x;
	}
	void add_special(char* ch, int len)
	{
		int o = root;
		for (int i = 0; i < len; ++i)
		{
			int p = 0;
			for (int j = head[o]; j; j = nxt[j])
				if (val[j] == ch[i])
					p = j;
			if (p)
				o = p;
			else
			{
				nxt[++cnt] = head[o];
				head[o] = cnt;
				val[cnt] = ch[i];
				o = cnt;
			}
		}
		++x[o];
	}
	void get_fail()
	{
		const int M = N << 4;
		int qu[M + 2], l, r;
		l = r = 0;
		for (int i = '0' - '0'; i <= 'z' - '0'; ++i)
			if (trie[root].son[i])
				qu[r++] = trie[root].son[i];
		while (l != r)
		{
			int p = qu[l++];
			int t = trie[p].fail;
			if (l > M)
				l = 0;
			for (int i = '0' - '0'; i <= 'z' - '0'; ++i)
				if (trie[p].son[i])
				{
					qu[r++] = trie[p].son[i];
					if (r > M)
						r = 0;
					trie[trie[p].son[i]].fail = trie[t].son[i];
				}
				else
				{
					trie[p].son[i] = trie[t].son[i];
				}
		}
	}
	int Aho_Corasick_Automaton(char* ch, int len)
	{
		int ans = 0;
		int o = root;
		for (int i = 0; i < len; ++i)
		{
			o = trie[o].son[ch[i] - '0'];
			for (int j = o; j && ~trie[j].x; j = trie[j].fail)
				ans += trie[j].x,
				trie[j].x = -1;
		}
		return ans;
	}

} // trie
using std::cin;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

}