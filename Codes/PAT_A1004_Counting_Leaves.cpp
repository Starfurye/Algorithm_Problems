#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int maxn = 102;

int N, M;
struct Node {
	int layer;
	vector<int> childs;
} nodes[maxn];
int counter[maxn];
int maxlayer = 0;

void LayerOrder(int root) {
	queue<int> Q;
	Q.push(root);
	nodes[root].layer = 0;
	while (!Q.empty()) {
		int front = Q.front();
		int layer = nodes[front].layer;
		if (layer > maxlayer)	maxlayer = layer;
		Q.pop();
		for (int i = 0; i < nodes[front].childs.size(); ++i) {
			int child = nodes[front].childs[i];
			Q.push(child);
			nodes[child].layer = nodes[front].layer + 1;
		}
		if (nodes[front].childs.size() == 0) {
			++counter[layer];
		}
	}
}

int main()
{
	fill(counter, counter + maxn, 0);
	scanf("%d", &N);
	if (N == 0) {
		printf("0");
		return 0;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		int root, childs;
		scanf("%d%d", &root, &childs);
		for (int j = 0; j < childs; ++j) {
			int child;
			scanf("%d", &child);
			nodes[root].childs.push_back(child);
		}
	}
	LayerOrder(1);
	int i = 0;
	while (i <= maxlayer) {
		printf("%d", counter[i]);
		if (i < maxlayer) printf(" ");
		++i;
	}
	
	return 0;
}
