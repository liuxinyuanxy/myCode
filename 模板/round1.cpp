//区间加法，单点查值。
ll a[50005];
ll change[50005];
int bl[50005];
int blo;
il void add(rt l, rt r, rt c)
{
	rt to = min(bl[l] * blo, r);
	for (rt i = l; i <= to; ++i)
		a[i] += c;
	if (bl[l] != bl[r])
		for (rt i = (bl[r] - 1) * blo + 1; i <= r; ++i)
			a[i] += c;
	for (rt i = bl[l] + 1; i <= bl[r] - 1; ++i)
		change[i] += c;
}
il void query(rt x)
{
	pfl((a[x] + change[bl[x]]));
	putchar('\n');
}
int main()
{
	rt n;
	rt opt, l, r, c;
	sf(n);
	rep(i, n, 1)
		sfl(a[i]);
	blo = sqrt(n);
	rep(i, n, 1)
		bl[i] = (i - 1) / blo + 1;
	rep(i, n, 1)
	{
		sf2(opt, l),
		sf2(r, c);	
		if (opt == 0) 
			add(l, r, c);
		else
			query(r);
	}
	return 0;
}

