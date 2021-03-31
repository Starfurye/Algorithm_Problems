/******************************************************
// S[0] = 0
// S[i] = x[0] + x[1] + x[2] + ... + x[i - 1] + x[i]
// x[i - 1] + x[i] = S[i] - S[i - 2]
// x[i - 2] + x[i - 1] + x[i] = S[i] - S[i - 3]
******************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 305;

int n;
int an[MAXN] = {0};
struct node {
	int v, w;
};
vector<node> Adj[MAXN];

void addEdge(int u, int v, int w) {
	node t;
	t.v = v; t.w = w;
	Adj[u].push_back(t);
}

int dis[MAXN];
bool inq[MAXN];
void SPFA(int s) {
	memset(inq, false, sizeof(inq));
	fill(dis, dis + MAXN, -1);
	
	queue<int> Q;
	Q.push(s);	inq[s] = true;	dis[s] = 0;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		inq[u] = false;
		for (int j = 0; j < Adj[u].size(); ++j) {
			int v = Adj[u][j].v, w = Adj[u][j].w;
			
			if (dis[u] + w > dis[v]) {
				dis[v] = dis[u] + w;
				if (!inq[v]) {
					Q.push(v);
					inq[v] = true;
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> an[i];
	}
	for (int i = 0; i <= n - 3; ++i) {
		addEdge(i, i + 3, 3 * an[i + 2]);			// S[i + 3] - S[i] >= 3a[i + 2]
		addEdge(i + 3, i, -(3 * an[i + 2] + 2));	// S[i] - S[i + 3] >= -(3a[i + 2] + 2)
	}
	addEdge(0, 2, 2 * an[1]);						// S[2] - S[0] >= 2a[1]
	addEdge(2, 0, -(2 * an[1] + 1));				// S[0] - S[2] >= -(2a[1] + 1)
	addEdge(n - 2, n, 2 * an[n]);					// S[n] - S[n - 2] >= 2 * a[n]
	addEdge(n, n - 2, -(2 * an[n] + 1));			// S[n - 2] - S[n] >= -(2a[n] + 1)
	for (int i = 1; i <= n; ++i) {					// S[i] - S[i - 1] >= 1
		addEdge(i - 1, i, 1);
	}
	SPFA(0);
	an[1] = dis[1];									// x[1] = S[1] - S[0]
	for (int i = 2; i <= n; ++i) {
		an[i] = dis[i] - dis[i - 1];				// x[i] = S[i] - S[i - 1]
	}
	for (int i = 1; i <= n; ++i) {
		if (i != 1) cout << " ";
		cout << an[i];
	}
	
	return 0;
}
