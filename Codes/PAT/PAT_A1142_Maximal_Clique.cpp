#include<cstdio>
#include<algorithm>

using namespace std;
const int maxn = 202;
int G[maxn][maxn];	// 1 to Nv
int Nv, Ne, M;
bool V[maxn];

int main()
{
	fill(G[0], G[0] + maxn * maxn, 0);
	scanf("%d%d", &Nv, &Ne);
	for (int i = 0; i < Ne; ++i) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		G[v1][v2] = G[v2][v1] = 1;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		fill(V, V + Nv + 1, false);
		int K, j;
		scanf("%d", &K);
		int query[maxn];
		for (j = 0; j < K; ++j) {
			int q;
			scanf("%d", &q);
			query[j] = q;
			V[q] = true;
		}
		int flag = 1;
		for (int p = 0; p < j; ++p) {
			for (int q = p + 1; q < j; ++q) {
				if (G[query[p]][query[q]] == 0) {
					flag = 0;
					break;
				}
			}
			if (flag == 0) break;
		}
		if (flag == 1) {
			for (int p = 1; p <= Nv; ++p) {
				if (V[p] == false) {
					bool flag2 = true;
					for (int q = 0; q < j; ++q) {
						if (G[p][query[q]] == 0) {
							flag2 = false; break;
						}
					}
					if (flag2) {
						flag = 2; break;
					}
				}
			}
		}
		if (flag == 0) printf("Not a Clique\n");
		else if (flag == 2) printf("Not Maximal\n");
		else printf("Yes\n");
	}
	
	return 0;
}
