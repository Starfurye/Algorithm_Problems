#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 507;
const int INF = 0x3f3f3f3f;

int G[maxn][maxn];
int weight[maxn], d[maxn];
vector<int> pre[maxn];
bool vis[maxn] = {false};
int Cmax, N, Sp, M;

void Dijkstra() {
    fill(d, d + maxn, INF);
    d[0] = 0;
    for (int i = 0; i <= N; ++i) {
        int u = -1, MIN = INF;
        for(int j = 0; j <= N; ++j) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)    return;
        vis[u] = true;
        for (int v = 0; v <= N; ++v) {
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

int optbring = INF, optback = INF;
vector<int> path, tempPath;

void DFS(int v) {
    if (v == 0) {
        tempPath.push_back(v);
        int value = 0;
        int bring = 0, brback = 0;
        for (int i = tempPath.size() - 1; i >= 0; --i) {
            int id = tempPath[i];
            value += weight[id] - Cmax / 2;
            if (value < 0) {
                bring += (-value);
                value = 0;
            }
        }
        brback = value < 0 ? 0 : value;
        if (bring < optbring) {
            optbring = bring;
            optback = brback;
            path = tempPath;
        }
        else if (bring == optbring && brback < optback) {
            optback = brback;
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

int main()
{
    scanf_s("%d%d%d%d", &Cmax, &N, &Sp, &M);
    fill(G[0], G[0] + maxn * maxn, INF);
    weight[0] = Cmax / 2;
    for (int i = 1; i <= N; ++i) {
        scanf_s("%d", &weight[i]);
    }
    for (int i = 0; i < M; ++i) {
        int s1, s2;
        scanf_s("%d%d", &s1, &s2);
        scanf_s("%d", &G[s1][s2]);
        G[s2][s1] = G[s1][s2];
    }
    Dijkstra();
    DFS(Sp);
    printf("%d ", optbring);
    for (int i = path.size() - 1; i >= 0; --i) {
        printf("%d", path[i]);
        if (i > 0)  printf("->");
    }
    printf(" %d\n", optback);
	system("pause");

    return 0;
}
