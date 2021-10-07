#include <iostream>
#include <cstdio>
#include <cmath>
#include <cctype>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
const int mx[] = {-1, 0, 1, 0}, my[] = {0, 1, 0, -1};
struct node{
	ll HP, STR, DEF;
}hero, enemy;
int gra[200][200];
int is[200];
il ll rd()
{
	rll s = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s;
}
il ll beat()
{
	return max(1, (ceil((double)enemy.HP / (double)max(1, hero.STR - enemy.DEF)) * max(1, enemy.STR - hero.DEF)));
}
int main()
{
	rc ch;
	rll sx, sy, q;
	rt n = rd(), m = rd();
	for (rt i = 1; i <= n; ++i)
		for (rt j = 1; j <= m; ++j)
		{
			while (ch = gc(), ch != '.' && !isalpha(ch));
			gra[i][j] = ch == 'R' ? 1 : ch == 'Q' ? 2 : ch == 'Y' ? 3 : ch == 'M' ? 4 : 0;
		}
	enemy.HP = rd(),
	enemy.STR = rd(),
	enemy.DEF = rd(),
	sx = rd(), sy = rd(),
	hero.STR = rd(),
	hero.DEF = rd();
	q = rd();
	is['N'] = 0;
	is['E'] = 1;
	is['S'] = 2;
	is['W'] = 3;
	for (rt i = 1; i <= q; ++i)
	{
		while (ch = gc(), !isalpha(ch));
		if (ch == 'Q')
			printf("%lld %lld %lld\n", hero.HP, hero.STR, hero.DEF);
		else
		{
			while (ch = gc(), !isalpha(ch));
			sx += mx[is[ch]],
			sy += my[is[ch]];
			gra[sx][sy] == 1 ? hero.HP = max(0, hero.HP - 10) : gra[sx][sy] == 2 ? hero.STR += 5 : gra[sx][sy] == 3 ? hero.DEF += 5 : gra[sx][sy] == 4 ? hero.HP += beat() : sx = sx;	
		}
	}
	return 0;
}


