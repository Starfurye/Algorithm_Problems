#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int n, m;
struct edge {
	int u, v, cost;
};
int father[maxn];
vector<edge> roads;
bool cmp(edge a, edge b) {
	return a.cost < b.cost;
}
int findFather(int x) {
	int a = x;
	while (x != father[x]) x = father[x];
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b) {
	int faA = findFather(a), faB = findFather(b);
	if (faA != faB) father[faA] = faB;
}

int main()
{
	ios::sync_with_stdio(false);
// freopen("in.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) father[i] = i;
	for (int i = 0; i < m; ++i) {
		int v1, v2, c; cin >> v1 >> v2 >> c;
		roads.push_back(edge{v1, v2, c});
	}
// fclose(stdin);	
	sort(roads.begin(), roads.end(), cmp);
	int pt = 0, maxday = 0;
	while (pt < m) {
		if (findFather(1) == findFather(n)) break;
		int v1 = roads[pt].u, v2 = roads[pt].v;
		maxday = max(maxday, roads[pt].cost);
		if (father[v1] != father[v2]) Union(v1, v2); 
		++pt;
	}
	cout << maxday;
	
	return 0;
}
