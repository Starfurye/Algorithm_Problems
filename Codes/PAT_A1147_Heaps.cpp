#include<cstdio>

const int maxn = 1005;
int M, N;
int level[maxn];
int judge() {		// 0: Not heap, 1: Max heap, 2: Min heap
	int method = -1;
	for (int i = 1; i * 2 <= N; ++i) {
		if (level[i] >= level[i * 2] && (i * 2 + 1 > N || level[i] >= level[i * 2 + 1])) {
			if (method == -1) method = 1;
			else if (method == 2) return 0;
		}
		else if (level[i] <= level[i * 2] && (i * 2 + 1 > N || level[i] <= level[i * 2 + 1])) {
			if (method == -1) method = 2;
			else if (method == 1) return 0;
		}
		else return 0;
	}
	return method;
}
int post[maxn];
int pp;
void postOrder(int root) {
	if (root * 2 <= N) postOrder(root * 2);
	if (root * 2 + 1 <= N) postOrder(root * 2 + 1);
	post[pp++] = level[root];
}

int main()
{
	scanf("%d%d", &M, &N);
	for (int i = 0; i < M; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &level[j]);
		}
		int res = judge();
		if (res == 0) printf("Not Heap\n");
		else if (res == 1) printf("Max Heap\n");
		else printf("Min Heap\n");
		pp = 0;
		postOrder(1);
		for (int j = 0; j < N; ++j) {
			printf("%d", post[j]);
			if (j < N - 1) printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
