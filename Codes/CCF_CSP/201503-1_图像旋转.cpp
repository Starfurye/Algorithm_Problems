#include<cstdio>
const int maxn = 1005;
int n, m;
int mat[maxn][maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &mat[i][j]);
		}
	}
	for (int i = m - 1; i >= 0; --i) {
		for (int j = 0; j < n; ++j) {
			printf("%d", mat[j][i]);
			if (j < n - 1) printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
