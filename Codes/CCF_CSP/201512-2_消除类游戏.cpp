#include<cstdio>
const int maxn = 35;
int n, m;
struct block {
	int color;
	bool flag;
};
block G[maxn][maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &G[i][j].color);
			G[i][j].flag = false;
		}
	}
	int last, counter;
	for (int i = 0; i < n; ++i) {
		last = G[i][0].color; counter = 0;
		for (int j = 1; j < m; ++j) {
			if (G[i][j].color == last) {
				++counter;
			}
			else {
				if (counter >= 2) {
					for (int k = j - counter - 1; k < j; ++k) { G[i][k].flag = true; }		
				}
				counter = 0;
			}
			if (j == m - 1 && counter >= 2) {
				for (int k = j - counter; k <= j; ++k) { G[i][k].flag = true; }
			}
			last = G[i][j].color;
		}
	}
	for (int i = 0; i < m; ++i) {
		last = G[0][i].color; counter = 0;
		for (int j = 1; j < n; ++j) {
			if (G[j][i].color == last) {
				++counter;
			}
			else {
				if (counter >= 2) {
					for (int k = j - counter - 1; k < j; ++k) { G[k][i].flag = true; }		
				}
				counter = 0;
			}
			if (j == n - 1 && counter >= 2) {
				for (int k = j - counter; k <= j; ++k) { G[k][i].flag = true; }
			}
			last = G[j][i].color;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d", G[i][j].flag ? 0 : G[i][j].color);
			if (j < m - 1) printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
