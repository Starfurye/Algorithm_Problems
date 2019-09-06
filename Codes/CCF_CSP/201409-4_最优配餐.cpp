#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int dist[1001][1001];
bool visited[1001][1001];
int width, numStore, numClient, numHole;
struct Pos {
	int x, y, val;
	Pos(int _x, int _y) : x(_x), y(_y) {}
	Pos() {}
};
bool legal(int x, int y) {
	return x >= 1 && y >= 1 && x <= width && y <= width;
}
Pos dir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int main() {
	scanf("%d%d%d%d", &width, &numStore, &numClient, &numHole);
	queue<Pos> stores;
	vector<Pos> holes, clients;

	Pos p;
	for (int i = 0; i < numStore; i++) {
		scanf("%d%d", &p.x, &p.y);
		stores.push(p);
		dist[p.x][p.y] = 0;
		visited[p.x][p.y] = true;
	}
	for (int i = 0; i < numClient; i++) {
		scanf("%d%d%d", &p.x, &p.y, &p.val);
		clients.push_back(p);
	}
	for (int i = 0; i < numHole; i++) {
		scanf("%d%d", &p.x, &p.y);
		dist[p.x][p.y] = -1;
		visited[p.x][p.y] = true;
	}
	while (!stores.empty()) {
		p = stores.front();
		stores.pop();
		for (int i = 0; i < 4; i++) {
			Pos np(p.x + dir[i].x, p.y + dir[i].y);
			if (!visited[np.x][np.y] && legal(np.x, np.y)) {
				visited[np.x][np.y] = true;
				dist[np.x][np.y] = dist[p.x][p.y] + 1;
				stores.push(np);
			}
		}
	}
	long long cost = 0;
	for (int i = 0; i < numClient; i++) {
		cost += dist[clients[i].x][clients[i].y] * clients[i].val;
	}
	printf("%lld\n", cost);

	return 0;
}
