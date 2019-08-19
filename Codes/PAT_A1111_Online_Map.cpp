#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int maxv = 502;
const int INF = 0x3f3f3f3f;
int n, m, src, dst;
int G[maxv][maxv];
int T[maxv][maxv];
int d[maxv], t[maxv];
bool vis[maxv] = {false};
vector<int> pre[maxv], preT[maxv];
void Dijkstra(int s) {
	fill(d, d + maxv, INF);
	d[s] = 0;
	for (int i = 0; i < n; ++i) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; ++j) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v= 0; v < n; ++v) {
			if (vis[v] == false && G[u][v] != INF) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[u] + G[u][v] == d[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}
void DijkstraT(int s) {
	fill(t, t + maxv, INF);
	t[s] = 0;
	for (int i = 0; i < n; ++i) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; ++j) {
			if (vis[j] == false && t[j] < MIN) {
				u = j;
				MIN = t[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; ++v) {
			if (vis[v] == false && T[u][v] != INF) {
				if (t[u] + T[u][v] < t[v]) {
					t[v] = t[u] + T[u][v];
					preT[v].clear();
					preT[v].push_back(u);
				}
				else if (t[u] + T[u][v] == t[v]) {
					preT[v].push_back(u);
				}
			}
		}
	}
}

int opttime = INF;
vector<int> path, tempPath;
void DFS(int v) {
	if (v == src) {
		tempPath.push_back(v);
		int value = 0;
		for (int i = tempPath.size() - 1; i > 0; --i) {
			int id = tempPath[i], idNext = tempPath[i - 1];
			value += T[id][idNext];
		}
		if (value < opttime) {
			opttime = value;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); ++i) {
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}

int optv = INF;
vector<int> pathT, tempPathT;
int W[maxv];
void DFST(int v) {
	if (v == src) {
		tempPathT.push_back(v);
		int value = 0;
		for (int i = tempPathT.size() - 1; i >= 0; --i) {
			int id = tempPathT[i];
			value += W[id];
		}
		if (value < optv) {
			optv = value;
			pathT = tempPathT;
		}
		tempPathT.pop_back();
		return;
	}
	tempPathT.push_back(v);
	for (int i = 0; i < preT[v].size(); ++i) {
		DFST(preT[v][i]);
	}
	tempPathT.pop_back();
}

int main()
{
	fill(G[0], G[0] + maxv * maxv, INF);
	fill(T[0], T[0] + maxv * maxv, INF);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int s, d, oneway, len, time;
		scanf("%d%d%d%d%d", &s, &d, &oneway, &len, &time);
		G[s][d] = len; T[s][d] = time;
		if (!oneway) {
			G[d][s] = len; T[d][s] = time;
		}
	}
	scanf("%d%d", &src, &dst);
	Dijkstra(src);
	DFS(dst);
	fill(vis, vis + n, false);
	fill(W, W + n, 1);
	DijkstraT(src);
	DFST(dst);
	if (path == pathT) {
		printf("Distance = %d; Time = %d: ", d[dst], t[dst]);
		for (int i = path.size() - 1; i >= 0; --i) {
			printf("%d", path[i]);
			if (i > 0) printf(" -> ");
		}
		printf("\n");
		return 0;
	}
	printf("Distance = %d: ", d[dst]);
	for (int i = path.size() - 1; i >= 0; --i) {
		printf("%d", path[i]);
		if (i > 0) printf(" -> ");
	}
	printf("\n");
	printf("Time = %d: ", t[dst]);
	for (int i = pathT.size() - 1; i >= 0; --i) {
		printf("%d", pathT[i]);
		if (i > 0) printf(" -> ");
	}
	printf("\n");
	
	return 0;
}
