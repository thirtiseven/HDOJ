#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int s,e,w;
} a[25000+5];
int n,m,k;
int fa[505];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int Find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=Find(fa[x]);
}
int Kruskal()
{
	sort(a+1,a+m+1,cmp);
	int ans=0;
	for(int i=1; i<=m; i++)
	{
		int x=Find(a[i].s);
		int y=Find(a[i].e);
		if(x!=y)
		{
			ans+=a[i].w;
			fa[x]=y;
		}
	}
	return ans;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		for(int i=1; i<=m; i++)
		{
			scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].w);
		}
		for(int i=1; i<=n; i++)
			fa[i]=i;
		for(int i=1; i<=k; i++)
		{
			int t,x,y;
			scanf("%d%d",&t,&x);
			for(int j=2; j<=t; j++)
			{
				scanf("%d",&y);
				int fx=Find(x);
				int fy=Find(y);
				if(fx!=fy)
					fa[fx]=fy;
			}
		}
		int ans=Kruskal();
		int sum=0;
		for(int i=1; i<=n; i++)
		{
			if(fa[i]==i)
				sum++;
		}
		if(sum>1)
			cout<<"-1"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}