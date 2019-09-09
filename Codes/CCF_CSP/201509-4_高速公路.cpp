#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 10005;
stack<int> s;
vector<int> G[maxn];
int DFN[maxn], LOW[maxn], vis[maxn], instack[maxn];
int res = 0, order = 0, n, m;
void Tarjan(int u) {
	DFN[u] = LOW[u] = ++order;
	s.push(u); instack[u] = 1; vis[u] = 1;
	for (int j = 0; j < G[u].size(); ++j) {
		int v = G[u][j];
		if (vis[v] == 0) {
			Tarjan(v);
			LOW[u] = min(LOW[u], LOW[v]);
		}
		else if (instack[v]) {
			LOW[u] = min(LOW[u], DFN[v]);
		}
	}
	if (DFN[u] == LOW[u]) {
		int cnt = 0;
		int m;
		do {
			m = s.top(); 
			instack[m] = 0; s.pop();
			++cnt;
		}while (m != u);
		if (cnt > 1) {
			res += cnt * (cnt - 1) / 2;
		}
	}	
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		G[v1].push_back(v2);
	}
	for (int i = 1; i <= n; ++i) {
		if (vis[i] == 0) {
			vis[i] = 1; 
			Tarjan(i);
		}
	}
	printf("%d\n", res);
	
	return 0;
}
