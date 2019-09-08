#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXV = 1005;
int n, m;
struct Node {
	int v;
	long long dis;
};
vector<Node> Adj[MAXV];
long long d[MAXV];
bool vis[MAXV] = {false};
long long prim() {
	fill(d, d + MAXV, INF);
	d[0] = 0;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; ++j) {
			if (vis[j] == false && d[j] < MIN) {
				u = j; MIN = d[j];
			}
		}
		if (u == -1) return -1;
		vis[u] = true;
		ans += d[u];
		for (int j = 0; j < Adj[u].size(); ++j) {
			int v = Adj[u][j].v;
			if (vis[v] == false && Adj[u][j].dis < d[v]) {
				d[v] = Adj[u][j].dis;
			}
		}
	}
	return ans;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int v1, v2; long long p;
		scanf("%d %d %lld", &v1, &v2, &p);
		Adj[v1 - 1].push_back(Node{v2 - 1, p});
		Adj[v2 - 1].push_back(Node{v1 - 1, p});
	}
	printf("%lld\n", prim());
	
	return 0;
}
