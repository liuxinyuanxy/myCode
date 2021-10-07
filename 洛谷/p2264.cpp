#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define il inline
#define re register
#define gc getchar
#define LL long long
using namespace std;
char word[105][100];
int l[105];
char gra[2000];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> word[i];
		int len = strlen(word[i]);
		l[i] = len;
		for (int j = 0; j < len; ++j)
			word[i][j] = tolower(word[i][j]);
	}
	cin.getline(gra, 1500);
	cin.getline(gra, 1500);
	int len = strlen(gra);
	for (int j = 0; j < len; ++j)
		gra[j] = tolower(gra[j]);
	int ans = 0;
	char *www = strtok(gra, ".");
	while (www != NULL)
	{
		for (int i = 1; i <= n; ++i)
		{
			char *w = strstr(www, word[i]);
			while ((w != NULL) && (isalpha(*(w - 1)) || isalpha(*(w + l[i]))))
				w = strstr(w + 1, word[i]);
			if (w != NULL)
				++ans;
		}
		www = strtok(NULL, ".");
	}
	cout << ans;
}