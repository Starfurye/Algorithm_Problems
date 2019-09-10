#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
char G[100][100];
int m, n, q;
struct node {
	int x, y;
};
void drawline(int x1, int y1, int x2, int y2) {
	if (y1 == y2) { 
        for (int i = x1; i <= x2; ++i) {
			if (G[i][y1] == '|' || G[i][y1] == '+') {
				G[i][y1] = '+';
			}
			else G[i][y1] = '-';
		}
    } else {
        for (int i = y1; i <= y2; ++i) { 
			if (G[x1][i] == '-' || G[x1][i] == '+') {
				G[x1][i] = '+';
			}
			else G[x1][i] = '|';
		}
    }
}
int X[4] = {0, 1, 0, -1};
int Y[4] = {1, 0, -1, 0};
bool check(int x, int y) {
	if (G[x][y] != '-' && G[x][y] != '|' && G[x][y] != '+' && x >= 0 && x < n && y >= 0 && y < m) return true;
	else return false;
}
void filling(int x, int y, char c) {
	int inq[100][100] = {};
	queue<node> Q;
	Q.push(node{x, y});	inq[x][y] = true;
	while (!Q.empty()) {
		int fx = Q.front().x, fy = Q.front().y;
		G[fx][fy] = c; Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = fx + X[i], ny = fy + Y[i];
            if (inq[nx][ny] || !check(nx, ny)) continue;
            inq[nx][ny] = true;	
            Q.push(node{nx, ny});
        }
	}
}

int main()
{
	fill(G[0], G[0] + 100 * 100, '.');
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < q; ++i) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int x, y; char c;
			scanf("%d %d %c", &x, &y, &c);
			filling(x, y, c);
		}
		else {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if (x1 > x2) swap(x1, x2);
			if (y1 > y2) swap(y1, y2);
			drawline(x1, y1, x2, y2);
		}
	}
	for (int i = m - 1; i >= 0; --i) {
		for (int j = 0; j < n; ++j) {
			printf("%c", G[j][i]);
		}
		printf("\n");
	}
	
	return 0;
}
