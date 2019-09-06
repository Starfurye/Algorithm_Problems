#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 105;
int n;
int board[maxn][maxn];
void draw(int x1, int y1, int x2, int y2) {
	for (int i = x1; i < x2; ++i) {
		for (int j = y1; j < y2; ++j) {
			board[i][j] = 1;
		}
	}
}
int main()
{
	fill(board[0], board[0] + maxn * maxn, 0);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		draw(x1, y1, x2, y2);
	}
	int t = 0;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (board[i][j] == 1) ++t;
		}
	}
	printf("%d\n", t);
	return 0;
}
