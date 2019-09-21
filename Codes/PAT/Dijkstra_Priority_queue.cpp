/***************************Problem Description****************************/
/*给出一个带权无向图，包含n个点，m条边。求出s，e的最短路。保证最短路存在。*/
/*Input specification*/
/*第一行输入n，m(1 <= n && n <= 5*10^5,1 <= m && m <= 2*10^6)。接下来m行，每
行三个整数，u, v, w,表示u，v之间有一条权值为w(w >= 0)的边。最后输入起点s和终
点e。*/
/*Output specification*/
/*对于每组数据输出一个整数代表答案。*/
#include<vector>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 10010;
int n, m;
struct node {
	int v, w;
	bool operator < (const node& b) const {
		return w > b.w;
	}
};
vector<node> Adj[maxn];
bool vis[maxn];
int d[maxn];
void dijkstra(int s, int e) {
	fill(d, d + n, INF);
	fill(vis, vis + n, false);
	priority_queue<node> q;
	d[s] = 0;
	q.push(node{s, 0});
	while (!q.empty()) {
		node front = q.top();	q.pop();
		int u = front.v;
		if (!vis[u]) {
			vis[u] = true;
			for (int i = 0; i < Adj[u].size(); ++i) {
				node next = Adj[u][i];
				if (d[u] + next.w < d[next.v]) {
					d[next.v] = d[u] + next.w;
					q.push(node{next.v, d[next.v]});
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
// freopen("in.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		Adj[v1].push_back(node{v2, c});
		Adj[v2].push_back(node{v1, c});
	}	
// fclose(stdin);
	int st, ed;
	cin >> st >> ed;
	dijkstra(st, ed);
	cout << d[ed] << endl;
	
	return 0;
}
