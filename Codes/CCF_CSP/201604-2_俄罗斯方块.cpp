#include<cstdio>
int G[18][18], block[4][4];
int main()
{
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 10; ++j) {
			scanf("%d", &G[i][j]);
		}
	}
	int low[4] = {0}, mov[4] = {14, 14, 14, 14};
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			scanf("%d", &block[i][j]);
			if (block[i][j] == 1) {
				low[j] = i + 1;
			}
		}
	}
	int col;
	scanf("%d", &col);
	for (int i = col - 1; i < col + 3; ++i) {
		if (low[i - col + 1] != 0) {
			int k;
			for (k = 0; k < 15; ++k) {
				if (G[k][i] == 1) {
					break;	
				}
			}
			mov[i - col + 1] = k + 1 - low[i - col + 1];
		}
	}
	int lowmov = 20;
	for (int i = 0; i < 4; ++i) {lowmov = lowmov > mov[i] ? mov[i] : lowmov;}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (block[i][j] == 1) {
				G[i + lowmov - 1][col + j - 1] = 1;
			}
		}
	}
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 10; ++j) {
			printf("%d", G[i][j]);
			if (j < 9) printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
