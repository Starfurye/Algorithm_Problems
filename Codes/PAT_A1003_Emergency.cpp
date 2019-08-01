#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 507;
const int INF = 0x3f3f3f3f;
int G[maxn][maxn];
int weight[maxn], d[maxn], w[maxn], num[maxn];
bool vis[maxn] = {false};
int N, M, C1, C2;

void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    d[s] = 0;
    fill(w, w + maxn, 0);
    w[s] = weight[s];
    fill(num, num + maxn, 0);
    num[s] = 1;
    for (int i = 0; i < N; ++i) {
        int u = -1, MIN = INF;
        for (int j = 0; j < N; ++j) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < N; ++v) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                }
                else if (d[u] + G[u][v] == d[v]) {
                    num[v] += num[u];
                    if (w[u] + weight[v] > w[v]) {
                         w[v] = w[u] + weight[v];
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &N, &M, &C1, &C2);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &weight[i]);
    }
	fill(G[0], G[0] + maxn * maxn, INF);
    for (int i = 0; i < M; ++i) {
        int c1 = 0, c2 = 0;
		scanf("%d%d", &c1, &c2);
		scanf("%d", &G[c1][c2]);
        G[c2][c1] = G[c1][c2];
    }
    Dijkstra(C1);
    printf("%d %d\n", num[C2], w[C2]);

    return 0;
}
