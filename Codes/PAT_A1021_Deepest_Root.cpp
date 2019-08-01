#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 100010;

struct Node {
    int vertex;
    int depth;
}node[maxn];

vector<int> Adj[maxn];
int N, maxDepth, p = 0;	// p is pointer of node
bool vis[maxn];

bool cmp(Node a, Node b) {
    if (a.depth == b.depth) return a.vertex < b.vertex;
    else return a.depth > b.depth;
}

void DFS(int u, int depth) {
    maxDepth = max(depth, maxDepth);
    vis[u] = true;
    for (int i = 0; i < Adj[u].size(); ++i) {
        int v = Adj[u][i];
        if (vis[v] == false) {
            DFS(v, depth + 1);
        }
    }
}

void DFSTrave() {
	for (int u = 1; u <= N; ++u) {
		maxDepth = 0;
		fill(vis + 1, vis + N + 1, false);
		if (vis[u] == false) {
			DFS(u, 1);
		}
		node[p].vertex = u;
		node[p].depth = maxDepth;
		++p;
	}
}

int compCounter() {
	int comp = 0;
	for (int u = 1; u <= N; ++u) {
		if (vis[u] == false) {
			++comp;
			DFS(u, 1);
		}
	}
	return comp;
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i < N; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        Adj[v1].push_back(v2);
		Adj[v2].push_back(v1);
    }
    bool flag = true;
	int comp = 0;
	DFS(1, 1);
	for (int i = 1; i <= N; ++i) {
		if (vis[i] == false) {
			flag = false;
			break;
		}
	}
	fill(vis + 1, vis + N + 1, false);

	if (flag) {
		DFSTrave();
		sort(node, node + p, cmp);
		printf("%d\n", node[0].vertex);
		int d = node[0].depth;
		for (int i = 1; i < p; ++i) {
			if (node[i].depth == d) printf("%d\n", node[i].vertex);
			else break;
		}
	}
	else {
		int counts = compCounter();
		printf("Error: %d components\n", counts);
	}

    return 0;
}
