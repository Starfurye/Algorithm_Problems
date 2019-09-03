#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 1020;
const int INF = 0x3f3f3f3f;

int G[maxn][maxn];
int d[maxn];
bool vis[maxn];
int N, M, K, Ds;

void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    d[s] = 0;
    for (int i = 1; i <= N + M; ++i) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= N + M; ++j) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)    return;
        vis[u] = true;
        for (int v = 1; v <= N + M; ++v) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                }
            }
        }
    }
}

int getID(char str[]) {
    int i = 0, len = strlen(str), ID = 0;
    while (i < len) {
        if (str[i] != 'G') {
            ID = ID * 10 + (str[i] - '0');
        }
        ++i;
    }
    if (str[0] == 'G') return N + ID;
    else return ID;
}

int main()
{
    scanf("%d%d%d%d", &N, &M, &K, &Ds);
    fill(G[0], G[0] + maxn * maxn, INF);
    for (int i = 0; i < K; ++i) {
        char c1[6], c2[6];
        int g1, g2;
        scanf("%s %s ", c1, c2);
        g1 = getID(c1); g2 = getID(c2);
        scanf("%d", &G[g1][g2]);
        G[g2][g1] = G[g1][g2];
    }

    double ansDis = -1, ansAvg = INF;
    int ansID = -1;
    for (int i = N + 1; i <= N + M; ++i) {
        double minDis = INF, totaldis = 0;
        fill(vis, vis + maxn, false);
        Dijkstra(i);
        for (int j = 1; j <= N; ++j) {
            if (d[j] > Ds) {
                minDis = -1;
                break;
            }
            totaldis += d[j];
            if (d[j] < minDis) minDis = d[j];
        }
        if (minDis == -1) continue;
        double avg = totaldis / N;
        if (minDis > ansDis) {
            ansID = i;  ansDis = minDis;    ansAvg = avg;
        }
        else if (minDis == ansDis && avg < ansAvg) {
            ansID = i;
            ansAvg = avg;
        }
    }
    if (ansID == -1)   printf("No Solution\n");
    else {
        printf("G%d\n", ansID - N);
        printf("%.1f %.1f\n", ansDis, ansAvg);
    }

    return 0;
}
