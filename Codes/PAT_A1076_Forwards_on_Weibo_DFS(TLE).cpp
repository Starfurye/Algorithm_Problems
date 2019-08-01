#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 1010;
const int INF = 0x3f3f3f3f;

int G[maxn][maxn] = {0};
bool vis[maxn];
int N, L, K;
int layer[maxn];

void DFS(int u, int depth) {
    if (depth > L)  return;
    vis[u] = true;
	layer[u] = depth;
    for (int v = 1; v <= N; ++v) {
		if (G[u][v] == 1) {
			if (vis[v] == false || depth + 1 < layer[v]) {
				DFS(v, depth + 1);
			}	
		}
    }
}

int main()
{
	scanf("%d%d", &N, &L);
    for (int i = 1; i <= N; ++i) {
        int j, k, follow;
		scanf("%d", &k);
        for(j = 1; j <= k; ++j) {
			scanf("%d", &follow);
            G[follow][i] = 1;
        }
    }

	scanf("%d", &K);
    for (int i = 1; i <= K; ++i) {
        int source;
        int forwards = 0;
		fill(vis + 1, vis + N + 1, false);
		fill(layer + 1, layer + N + 1, INF);
		scanf("%d", &source);
        DFS(source, 0);
		for (int i = 1; i <= N; ++i) {
			if (vis[i])	++forwards;
		}
        printf("%d\n", forwards - 1);
    }

    return 0;
}
