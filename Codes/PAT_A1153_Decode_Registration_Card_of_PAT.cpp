#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<vector>
using namespace std;
 
const int maxn = 10005;
struct node {
	string p;
	int score;
}s[maxn];
struct node2{
	string id;
	int num;
}a[maxn];
 
bool cmp1(node &x,node &y){
	return x.score != y.score ? x.score >= y.score : x.p < y.p;
}
bool cmp2(node2 &x,node2 &y){
	return x.num != y.num ? x.num > y.num : x.id < y.id;
}
 
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		cin >> s[i].p; scanf("%d", &s[i].score);
	}
	int ca = 0;
	while(m--)
	{
		int type;
		string term;
		scanf("%d", &type);
		cin >> term;
		printf("Case %d: %d ", ++ca,type); cout << term << endl;
		if(type == 1) {
			int flag = 0;	
			sort(s, s + n, cmp1);
			for(int i = 0; i < n; i++){
				if(s[i].p[0] == term[0]){
					flag = 1; cout << s[i].p;
					printf(" %d\n", s[i].score);
				}
			}
			if(!flag) puts("NA");
		}else if(type == 2){
			int cnt = 0, sum = 0;
			for(int i = 0; i < n; i++){
				string p2 = s[i].p.substr(1,3);
				if(p2 == term) {
					cnt++; sum += s[i].score;
				}
			}
			if(cnt == 0) puts("NA");
			else printf("%d %d\n", cnt, sum);
		}else{
			unordered_map<string,int> mp;
			int cnt = 0, flag = 0;
			for(int i = 0; i < n; i++){
				string p3 = s[i].p.substr(4,6);
				string p2 = s[i].p.substr(1,3);
				if(p3 == term) {
					flag = 1; ++mp[p2];
				}
			}
			if(mp.empty()) {
				puts("NA"); continue;
			}
			vector<pair<string,int>> v;
			int now = 0;
			for(auto it = mp.begin(); it != mp.end(); ++it)
			{
				a[now].id = it->first;
				a[now++].num = it->second;
			}
			sort(a, a + now, cmp2);
			for(int i = 0; i < now; i++) {
				cout << a[i].id; printf(" %d\n", a[i].num);	
			}
		} 
	}
	return 0;
}
