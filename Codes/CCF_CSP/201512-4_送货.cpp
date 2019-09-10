#include<cstdio>
#include<set>
#include<vector>
using namespace std;
int n, m;
int main()
{
	scanf("%d%d", &n, &m);
	vector<set<int> > G(n);
	for (int i = 0; i < m; ++i) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		G[v1 - 1].insert(v2 - 1); G[v2 - 1].insert(v1 - 1);
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (G[i].size() & 1) ++cnt;
	}
	if (cnt != 0 && cnt != 2) {
		printf("-1\n"); return 0;
	}
	if (cnt == 2 && !(G[0].size() & 1)) {	 
		printf("-1\n"); return 0;
	}
	vector<int> path, circuit;
	path.push_back(0);
	while (!path.empty() && path.size() + circuit.size() < m + 1) {
		int cur = path.back();
		if (G[cur].empty()) {
			path.pop_back();
			circuit.push_back(cur);
		}
		else {
			int v = *G[cur].begin();
			G[cur].erase(G[cur].begin());
			G[v].erase(cur);
			path.push_back(v);
		}
	}
	if (path.empty()) {
		printf("-1\n"); return 0;
	}
	while (!circuit.empty()) {
		path.push_back(circuit.back());
		circuit.pop_back();
	}
	printf("1");
	for (int i = 1; i <= m; ++i) {
		printf(" %d", path[i] + 1);
	}
	printf("\n");
	return 0;
}
