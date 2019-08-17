#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;
const int maxn = 100000;
const int maxrl = 1000;
int N, m, n;
int nums[maxn];
int pt = 0;
int matrix[maxrl][maxrl];
int currow = 0, curcol = 0;

bool cmp(int a, int b) {return a > b;}
void decidemn() {
	int sqr = (int)sqrt(N);
	for (m = sqr; m <= N; ++m) {
		if (N % m == 0) {
			n = N / m;
			if (n > m) swap(m, n);
			return;
		}
	}
}
// mtd = 0, 1, 2, 3 -> right, down, left, up
void getMatrix(int mtd) {
	switch (mtd) {
		case 0: {
			while (matrix[currow][++curcol] == 0) {
				matrix[currow][curcol] = nums[pt++];
			}
			--curcol;
			break;
		}
		case 1: {
			while (matrix[++currow][curcol] == 0) {
				matrix[currow][curcol] = nums[pt++];
			}
			--currow;
			break;
		}
		case 2: {
			while (matrix[currow][--curcol] == 0) {
				matrix[currow][curcol] = nums[pt++];
			}
			++curcol;
			break;
		}
		case 3: {
			while (matrix[--currow][curcol] == 0) {
				matrix[currow][curcol] = nums[pt++];
			}
			++currow;
			break;
		}
		default: break;
	}
}
void printMatrix() {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d", matrix[i][j]);
			if (j < n - 1) printf(" ");
		}
		printf("\n");
	}
}

int main()
{
	for (int i = 0; i < maxrl; ++i) {
		for (int j = 0; j < maxrl; ++j) {
			matrix[i][j] = -1;
		}
	}
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &nums[i]);
	}
	sort(nums, nums + N, cmp);
	decidemn();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			matrix[i][j] = 0;
		}
	}
	matrix[currow][curcol] = nums[pt++];
	int mtd = 0;
	while (pt < N) {
		getMatrix((mtd++) % 4);
	}
	printMatrix();
	
	return 0;
}
