#include<iostream>
#include<string>
#include<cstring>
#include<vector>
 
using namespace std;
 
const int N=105;
 
struct Node{
	string lable,id;
	int cnt;
}a[N];
 
void lowerize(string &s)
{
	for(int i=0;i<s.length();i++)
	  s[i]=tolower(s[i]);
}
 
bool search(Node a[],int &start,int &cnt,string s)
{
	for(int i=start;i>=1;i--)
	{
		if(a[i].cnt<cnt) 
		{
			cnt=a[i].cnt,start=i;
			if(s==a[i].lable||s==a[i].id) return true;
		}
	}
	return false;
}
 
int main()
{
	int n,m;
	string s;
	cin>>n>>m;
	getchar();
	for(int i=1;i<=n;i++)
	{
		getline(cin,s);
		int pos1=-1,pos2=-1,cnt=0; 
		for(int j=0;j<s.length();j++)
		  if(s[j]=='.')
		    cnt++;
		  else if(pos1==-1&&s[j]!='#')
		    pos1=j;
		  else if(s[j]=='#')
		    pos2=j;
		a[i].cnt=cnt;
		if(pos2==-1)
		{
			a[i].lable=s.substr(pos1);
			a[i].id="";
		}
		else
		{
			a[i].lable=s.substr(pos1,pos2-pos1-1);
			a[i].id=s.substr(pos2);
		}
		lowerize(a[i].lable);
	}
	for(int i=0;i<m;i++)
	{
		char tmp[100];
		vector<string>query;
		vector<int>ans;
		gets(tmp);
		char *sp=strtok(tmp," ");
		while(sp)
		{
			query.push_back(sp);
			sp=strtok(NULL," ");
		}
		int len=query.size();
		for(int j=0;j<len;j++)
		  if(query[j][0]!='#')  lowerize(query[j]);
		for(int j=1;j<=n;j++)
		{
			if(query[len-1]==a[j].id||query[len-1]==a[j].lable)
			{
				int start=j,cnt=a[j].cnt,k=len-2;
				for(;k>=0;k--)
				{
					if(!search(a,start,cnt,query[k])) break;
				}
				if(k<0)
				  ans.push_back(j); 
			}
		}
		cout<<ans.size();
		for(int j=0;j<ans.size();j++)
		  cout<<" "<<ans[j];
		cout<<endl;
	}
	return 0;
}
