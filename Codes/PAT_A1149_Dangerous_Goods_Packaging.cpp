#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
int N, M;
const int maxn = 100000;
const int maxl = 1010;
vector<int> goods[maxn];
bool flag[maxn];
int list[maxl];
bool judge(int len) {
	for (int i = 0; i < len; ++i) {
		if (flag[list[i]] == true) {
			return false;
		}
		for (int j = 0; j < goods[list[i]].size(); ++j) {
			flag[goods[list[i]][j]] = true;
		}
	}
	return true;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		int g1, g2;
		scanf("%d%d", &g1, &g2);
		goods[g1].push_back(g2); goods[g2].push_back(g1);
	}
	for (int i = 0; i < M; ++i) {
		fill(flag, flag + maxn, false);
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; ++j) {
			scanf("%d", &list[j]);
		}
		printf("%s\n", judge(num) ? "Yes" : "No");
	}
	
	return 0;
}
