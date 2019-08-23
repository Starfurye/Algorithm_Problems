#include<cstdio>
#include<algorithm>

using namespace std;

const int maxv = 210;
int G[maxv][maxv];
int N, M, K;

int main()
{
	fill(G[0], G[0] + maxv * maxv, 0);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		G[v1][v2] = G[v2][v1] = 1;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++i) {
		int q;
		scanf("%d", &q);
		if (q != N + 1) {
			printf("NO\n");
			int temp;
			for (int j = 0; j < q; ++j) {
				scanf("%d", &temp);
			}
			continue;
		}
		int hashtable[maxv] = {0};
		int first, last, now;
		scanf("%d", &last);
		first = last;
		hashtable[last] = 1;
		bool flag = true;
		for (int j = 1; j < q - 1; ++j) {
			scanf("%d", &now);
			if (G[last][now] == 0 || hashtable[now] == 1) {
				flag = false;
			}
			else {
				hashtable[now] = 1;
				last = now;
			}
		}
		if (flag) {
			scanf("%d", &now);
			if (G[last][now] == 0 || now != first) {
				flag = false;
			}
		}
		else {
			int temp;
			scanf("%d", &temp);
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
