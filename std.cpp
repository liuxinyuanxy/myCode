#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int t;
char s[110000];
int a[110000];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		long long ans=0;
		memset(a,0,sizeof(a));	
		int tot=1;	
		scanf("%s",s+1);
		int l=strlen(s+1);
		for(int i=1;i<=l;i++)
		{
			int tot=1;
			if(s[i]=='0')tot++;
			for(int j=i;j<=l;j++)
			{
				if(s[j]==s[j-1]&&j>i)tot++;
				ans+=tot;
				tot++;	
			} 
		}
		printf("%lld\n",ans);
	}
}
