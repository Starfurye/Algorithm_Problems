#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<cstring>
using namespace std;
const int N = 10005;
struct node
{
	int id;
	double num;
	double e,a;
}b[N],c[N];
bool cmp(node a, node b)
{
	if (a.a / a.num == b.a / b.num) {
		return a.id < b.id;	
	}
	else return a.a / a.num > b.a / b.num;
}
int fa[N],vis[N];
 
int find(int x)
{
	int r=x;
	while(fa[r]!=r) r=fa[r];
	int i=x,j;
	while(i!=r) {
		j=fa[i];
		fa[i]=r;
		i=j;
	}
	return r;
}
 
int main()
{
	int i,j,n,id,f,m,num,son,k;
	double a,e;
	int fx,fy;
	cin>>n;
	for(i=0;i<N;i++) fa[i]=i;
	for(i=1;i<=n;i++) {
		cin>>id>>f>>m>>num;
		fx=find(id);
		b[id].num=1;
		b[id].id=id;
		if(f!=-1) {
			fy=find(f);
			if(fx!=fy) fa[fy]=fx;
			b[f].num=1;
			b[f].id=f;
		}
		if(m!=-1) {
			fy=find(m);
			if(fx!=fy) fa[fy]=fx;
			b[m].num=1;
			b[m].id=m;
		}
		while(num--) {
			cin>>son;
			fy=find(son);
			if(fx!=fy) fa[fy]=fx;
			b[son].num=1;
			b[son].id=son;
		}
		cin>>e>>a;
		b[id].a=a;
		b[id].e=e;
	}
	k=0;
	for(i=0;i<=N;i++) {
		if(!b[i].num) continue;
		fx=find(i);
		if(i<fx) fa[fx]=i,fa[i]=i;
	}
	for(i=0;i<N;i++) {
		if(i==find(i)) continue;
		else if(b[i].num) {
			b[find(i)].num++;
			b[find(i)].a+=b[i].a;
			b[find(i)].e+=b[i].e;
		}
	}
	for(i=0;i<N;i++) {
		if(i==find(i) && b[i].num) {
			c[k].id=b[i].id;
			c[k].num=b[i].num;
			c[k].a=b[i].a;
			c[k++].e=b[i].e;
		}
	}
 
	sort(c,c+k,cmp);
	cout<<k<<endl;
	for(i=0;i<k;i++) printf("%04d %.0lf %.3lf %.3lf\n",c[i].id,c[i].num,c[i].e/c[i].num,c[i].a/c[i].num);
 
	return 0;
}
