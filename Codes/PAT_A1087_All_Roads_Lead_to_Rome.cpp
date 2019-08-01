#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>

using namespace std;

const int maxn = 220;
const int INF = 0x3f3f3f3f;

map<string, int> cityToIndex;
map<int, string> indexToCity;

int G[maxn][maxn];
int weight[maxn], d[maxn], num[maxn];
vector<int> pre[maxn];
bool vis[maxn] = {false};

int N, K;
string st;

void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    fill(num, num + maxn, 0);
    num[0] = 1;
    d[0] = 0;
    for (int i = 0; i < N; ++i) {
        int u = -1, MIN = INF;
        for(int j = 0; j < N; ++j) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)    return;
        vis[u] = true;
        for (int v = 0; v < N; ++v) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    num[v] = num[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (d[u] + G[u][v] == d[v]) {
                    num[v] += num[u];
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int optValue = 0;
vector<int> path, tempPath;

void DFS(int v) {
    if (v == 0) {
        tempPath.push_back(v);
        int value = 0;
        for (int i = tempPath.size() - 1; i >= 0; --i) {
            int id = tempPath[i];
            value += weight[id];
        }
        if (value > optValue) {
            optValue = value;
            path = tempPath;
        }
		tempPath.pop_back();
		return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); ++i) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main()
{
    fill(G[0], G[0] + maxn * maxn, INF);
    cin >> N >> K >> st;
    weight[0] = 0;
    cityToIndex[st] = 0;
    indexToCity[0] = st;
    for (int i = 1; i < N; ++i) {
        string name;
        cin >> name >> weight[i];
        cityToIndex[name] = i;
        indexToCity[i] = name;
    }
    for (int i = 0; i < K; ++i) {
        string c1, c2;
        cin >> c1 >> c2;
        cin >> G[cityToIndex[c1]][cityToIndex[c2]];
        G[cityToIndex[c2]][cityToIndex[c1]] = G[cityToIndex[c1]][cityToIndex[c2]];
    }
    Dijkstra(0);
    DFS(cityToIndex["ROM"]);
    cout << num[cityToIndex["ROM"]] << " " << d[cityToIndex["ROM"]] << " " << optValue << " " << (int)(optValue / (path.size() - 1)) << endl;
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << indexToCity[path[i]];
        if (i > 0)  cout << "->";
    }

    return 0;
}
