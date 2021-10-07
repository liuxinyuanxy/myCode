#include<bits/stdc++.h>
#define il inline
using namespace std;
const int N=50005;
int T,n,pos[N];
struct node{
    int v,id;
    bool operator< (const node a)const{return v<a.v;}
    bool operator == (const node a)const{return v==a.v;}
}a[N];
il bool cmp(const node &a,const node &b){return a.id<b.id;}
il int gi(){
    int a=0;char x=getchar();bool f=0;
    while((x<'0'||x>'9')&&x!='-')x=getchar();
    if(x=='-')x=getchar(),f=1;
    while(x>='0'&&x<='9')a=a*10+x-48,x=getchar();
    return f?-a:a;
}
int main(){
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
    T=gi();
    while(T--){
        n=gi();
        for(int i=1;i<=n;i++)a[i].v=gi(),a[i].id=i;
        stable_sort(a+1,a+n+1);
        int m=unique(a+1,a+n+1)-a-1;
        sort(a+1,a+m+1,cmp);
        for(int i=1;i<=m;i++)printf("%d ",a[i].v);
        printf("\n");
    }
    return 0;
}
