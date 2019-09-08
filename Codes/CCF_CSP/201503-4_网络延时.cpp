#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 20005;
const int INF = 0x3f3f3f3f;
struct node {
	int v, dis;
};
vector<node> Adj[maxn];
int d[maxn];
bool inq[maxn];
int n, m, v1;			// machine: 0 to n - 1, PC: n to m + n - 1
int SPFA(int s) {
	int maxdis = 0;
	memset(inq, false, sizeof(inq));
	fill(d, d + maxn, INF);
	queue<int> Q;	Q.push(s);
	inq[s] = true;	d[s] = 0;
	while (!Q.empty()) {
		int u = Q.front();	Q.pop();
		inq[u] = true;
		for (int j = 0; j < Adj[u].size(); ++j) {
			int v = Adj[u][j].v, dis = Adj[u][j].dis;
			if (d[u] + dis < d[v]) {
				d[v] = d[u] + dis;
				if (d[v] < maxdis) {
					maxdis = d[v]; v1 = v;
				}
				if (!inq[v]) {
					Q.push(v);	inq[v] = true;
				}
			}
		}
	}
	return -maxdis;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n + m; ++i) {
		int v; scanf("%d", &v);
		Adj[i].push_back(node{v - 1, -1}); Adj[v - 1].push_back(node{i, -1});
	}
	int ans = 0;
	for (int i = 0; i < n + m; ++i) {
		if (Adj[i].size() == 1) {
			int temp = SPFA(i);
			break;
		}
	}
	ans = SPFA(v1);
	printf("%d\n", ans);
	
	return 0;
}
