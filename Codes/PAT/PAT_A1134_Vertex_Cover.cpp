#include<cstdio>
#include<vector>

using namespace std;

const int maxv = 10002;
int N, M, K;
vector<int> G[maxv];
bool hashtable[maxv];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		G[v1].push_back(i);	G[v2].push_back(i);
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++i) {
		int nums;
		scanf("%d", &nums);
		fill(hashtable, hashtable + M, false);
		for (int j = 0; j < nums; ++j) {
			int v;
			scanf("%d", &v);
			for (int k = 0; k < G[v].size(); ++k) {
				hashtable[G[v][k]] = true;
			}
		}
		bool flag = true;
		for (int j = 0; j < M; ++j) {
			if (hashtable[j] == false) {
				flag = false; break;
			}
		}
		printf("%s\n", flag ? "Yes" : "No");
	}
	
	return 0;
}
