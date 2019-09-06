#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

typedef long long LL;
const int maxn = 210, INF = 0x3fffffff;
int n, m, k, r;
struct point {
	LL x, y;
}P[maxn];
struct node {
	int v;
	double c;
};
vector<node> adj[maxn];

int vis[maxn], num[maxn], cnt[maxn];
int Dijkstra(int s) {
	fill(vis, vis + maxn, 0);
	fill(num, num + maxn, INF);
	fill(cnt, cnt + maxn, 0);
	num[s] = 0;
	for (int i = 0; i < n + m; ++i) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n + m; ++j) {
			if (vis[j] == 0 && num[j] < MIN) {
				u = j; MIN = num[j];
			}
		}
		if (u == -1) break;
		vis[u] = 1;
		for (int j = 0; j < adj[u].size(); ++j) {
			int v = adj[u][j].v;
			if (vis[v] == 0 && num[u] + 1 < num[v]) {
				if (v < n) {
					num[v] = num[u] + 1;
					cnt[v] = cnt[u];
				}
				else {
					if (cnt[u] + 1 <= k) {
						num[v] = num[u] + 1;
						cnt[v] = cnt[u] + 1;
					}
				}
			}
		}
	}
	return num[1] - 1;
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &r);
	for (int i = 0; i < n; ++i) scanf("%lld%lld", &P[i].x, &P[i].y);
	for (int i = n; i < n + m; ++i) scanf("%lld%lld", &P[i].x, &P[i].y);
	for (int i = 0; i < n + m; ++i) {
		for (int j = i + 1; j < n + m; ++j) {
			double temp = sqrt((P[i].x - P[j].x) * (P[i].x - P[j].x) + (P[i].y - P[j].y) * (P[i].y - P[j].y));
			if (temp <= r * 1.0) {
				adj[i].push_back(node{j, temp}); adj[j].push_back(node{i, temp});
			}
		}
	}
	printf("%d\n", Dijkstra(0));
	
	return 0;
}
