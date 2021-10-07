#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

namespace suffixSort
{
	const int MAXN = 2000000;
	int tax[MAXN], tp[MAXN], rak[MAXN], sa[MAXN];
	// N : 后缀个数 M : 字符集大小
	void redixSort(int N, int M)
	{
		for (int i = 0; i <= M; ++i)
			tax[i] = 0;
		for (int i = 1; i <= N; ++i)
			++tax[rak[i]];
		for (int i = 1; i <= M; ++i)
			tax[i] += tax[i - 1];
		for (int i = N; i >= 1; --i)
			sa[tax[rak[tp[i]]]--] = tp[i];
	}
	void suffixSort(char* ch, int len)
	{
		int M = 'z' - '0' + 1;
		for (int i = 1; i <= len; ++i)
			rak[i] = ch[i] - '0' + 1,
			tp[i] = i;
		redixSort(len, M);
		int p = 0;
		for (int w = 1; p < len; w <<= 1, M = p)
		{
			//这里的p仅为计数器
			p = 0;
			for (int i = 1; i <= w; ++i)
				tp[++p] = len - w + i;
			for (int i = 1; i <= len; ++i)
				if (sa[i] > w)
					tp[++p] = sa[i] - w;
			redixSort(len, M);
			std::swap(rak, tp);				//此时tp为临时数组用于更新下次字符集和rak数组， 上一次的tp以被丢弃
			rak[sa[1]] = 1;
			//这里的p用于统计字符集大小
			p = 1;
			for (int i = 2; i <= len; ++i)
				rak[sa[i]] = (tp[sa[i]] == tp[sa[i - 1]] && tp[sa[i] + w] == tp[sa[i - 1] + w]) ? p : ++p;
		}
	}
} // suffixSort
char ch[10000000];
int main()
{
	int len;
	cin >> (ch + 1);
	len = strlen(ch + 1);
	suffixSort::suffixSort(ch, len);
	for (int i = 1; i <= len; ++i)
	{
		printf("%d ", suffixSort::sa[i]);
	}
	return 0;
}