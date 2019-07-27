#include<cstdio>
#include<queue>

using namespace std;

int m, n, l, t;
const int maxm = 1290, maxn = 130, maxl = 62;

struct node {
    int x, y, z;
} Node;

int matrix[maxm][maxn][maxl];
bool inq[maxm][maxn][maxl] = {false};
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

bool judge(int x, int y, int z) {
    if (x >= m || x < 0 || y >= n || y < 0 || z >= l || z < 0) return false;
    if (matrix[x][y][z] == 0 || inq[x][y][z] == true)   return false;
    return true;
}

int BFS(int x, int y, int z) {
    queue<node> Q;
    int pixels = 1;
    Node.x = x; Node.y = y; Node.z = z;
    Q.push(Node);
    inq[x][y][z] = true;
    while (!Q.empty()) {
        node top = Q.front();
        Q.pop();
        for (int i = 0; i < 6; ++i) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            int newZ = top.z + Z[i];
            if (judge(newX, newY, newZ)) {
                ++pixels;
                Node.x = newX;  Node.y = newY;  Node.z = newZ;
                Q.push(Node);
                inq[newX][newY][newZ] = true;
            }
        }
    }
    if (pixels >= t) return pixels;
    else return 0;
}

int main()
{
    scanf("%d%d%d%d", &m, &n, &l, &t);
    for (int z = 0; z < l; ++z) {
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                scanf("%d", &matrix[x][y][z]);
            }
        }
    }
    int ans = 0;
    for (int z = 0; z < l; ++z) {
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (matrix[x][y][z] == 1 && inq[x][y][z] == false) {
                    ans += BFS(x, y, z);
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
