#include<cstdio>
#include<vector>
#include<set>
using namespace std;
int N, M, K;
const int maxn = 10010;
vector<int> v[maxn];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		v[v1].push_back(v2); v[v2].push_back(v1);
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++i) {
		int colors[maxn];
		set<int> st;
		for (int j = 0; j < N; ++j) {
			scanf("%d", &colors[j]);
			st.insert(colors[j]);
		}
		bool flag = true;
		for (int j = 0; j < N; ++j) {
			int c = colors[j];
			for (int k = 0; k < v[j].size(); ++k) {
				if (c == colors[v[j][k]]) {
					flag = false; break;
				}
			}
			if (flag == false) break;
		}
		if (flag) printf("%d-coloring\n", st.size());
		else printf("No\n");
	}
	
	return 0;
}
