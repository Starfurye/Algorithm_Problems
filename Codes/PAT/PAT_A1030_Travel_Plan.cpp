#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 507;
const int INF = 0x3f3f3f3f;

int G[maxn][maxn];
int V[maxn][maxn];
int d[maxn];
vector<int> pre[maxn];
bool vis[maxn] = {false};
int N, M, S, D;

void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    d[s] = 0;
    for (int i = 0; i < N; ++i) {
        int u = -1, MIN = INF;
        for (int j = 0; j < N; ++j) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)    return;
        vis[u] = true;
        for (int v = 0; v < N; ++v) {
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

int optvalue = INF;
vector<int> path, tempPath;

void DFS(int v) {
    if (v == S) {
        tempPath.push_back(v);
        int value = 0;
        for (int i = tempPath.size() - 1; i > 0; --i) {
            int id = tempPath[i], idNext = tempPath[i - 1];
            value += V[id][idNext];
        }
        if (value < optvalue) {
            optvalue = value;
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
    scanf("%d%d%d%d", &N, &M, &S, &D);
    fill(G[0], G[0] + maxn * maxn, INF);
    fill(V[0], V[0] + maxn * maxn, INF);
    for (int i = 0; i < M; ++i) {
        int c1, c2;
        scanf("%d%d", &c1, &c2);
        scanf("%d%d", &G[c1][c2], &V[c1][c2]);
        G[c2][c1] = G[c1][c2];
        V[c2][c1] = V[c1][c2];
    }
    Dijkstra(S);
    DFS(D);
    for (int i = path.size() - 1; i >= 0; --i) {
        printf("%d ", path[i]);
    }
    printf("%d %d\n", d[D], optvalue);

    return 0;
}
