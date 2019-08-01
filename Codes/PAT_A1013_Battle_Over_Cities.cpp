#include<cstdio>
#include<cstring>

using namespace std;

const int maxn = 1010;
const int INF = 0x3f3f3f3f;

int G[maxn][maxn] = {0};
bool vis[maxn] = {false};
int N, M, K, del;

void DFS(int u) {
    vis[u] = true;
    for (int v = 1; v <= N; ++v) {
        if (v == del)   continue;
        if (vis[v] == false && G[u][v] == 1) {
            DFS(v);
        }
    }
}

int DFSTrave() {
    int counter = 0;
    for (int u = 1; u <= N; ++u) {
        if (u == del)   continue;
        if (vis[u] == false) {
            ++counter;
            DFS(u);
        }
    }
    return counter;
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    int v1, v2;
    for (int i = 1; i <= M; ++i) {
        scanf("%d%d", &v1, &v2);
        G[v1][v2] = G[v2][v1] = 1;
    }

    for (int i = 1; i <= K; ++i) {
        memset(vis, false, sizeof(vis));
        scanf("%d", &del);
        printf("%d\n", DFSTrave() - 1);
    }

    return 0;
}
