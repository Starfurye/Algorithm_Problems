#include<cstdio>
#include<algorithm>

using namespace std;
const int maxv = 502;
int G[maxv][maxv];
int N, M;
bool noedge = false;

bool vis[maxv] = {false};
int visnum = 0;
void dfs(int v) {
	++visnum;
	vis[v] = true;
	for (int i = 1; i <= N; ++i) {
		if (vis[i] == false && G[v][i] == 1) {
			dfs(i);
		}
	}
}
int getdegree(int v) {
	int deg = 0;
	for (int i = 1; i <= N; ++i) {
		deg += G[v][i];
	}
	if (deg == 0) noedge = true;
	return deg;
}

int main()
{
	int degs[maxv] = {0};
	fill(G[0], G[0] + maxv * maxv, 0);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		G[v1][v2] = G[v2][v1] = 1;
		++degs[v1]; ++degs[v2];
	}
	int odd = 0;
	for (int i = 1; i <= N; ++i) {
		printf("%d", degs[i]);
		if (i < N) printf(" ");
		if (degs[i] % 2 != 0) ++odd;
	}
	printf("\n");
	dfs(1);
	if (odd == 0 && visnum == N) printf("Eulerian\n");
	else if (odd == 2 && visnum == N) printf("Semi-Eulerian\n");
	else printf("Non-Eulerian\n"); 
	
	return 0;
}
