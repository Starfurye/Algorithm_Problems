#include<cstdio>
#include<vector>

using namespace std;

const int maxn = 107;
vector<int> child[maxn];
int levelmem[maxn] = {0};
int N, M;
void PreOrder(int root, int level) {
	++levelmem[level];
	if (child[root].size() == 0) return;
	for (int i = 0; i < child[root].size(); ++i) {
		PreOrder(child[root][i], level + 1);
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int id, childnum;
		scanf("%d%d", &id, &childnum);
		for (int j = 0; j < childnum; ++j) {
			int ch;
			scanf("%d", &ch);
			child[id].push_back(ch);
		}
	}
	PreOrder(1, 1);
	int i = 1, maxmem = 0, maxlevel = 0;
	while(levelmem[i] != 0) {
		if (levelmem[i] > maxmem) {
			maxmem = levelmem[i];
			maxlevel = i;
		}
		++i;
	}
	printf("%d %d\n", maxmem, maxlevel);
	
	return 0;
}
