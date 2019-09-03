#include<cstdio>

const int maxn = 10005;
int father[maxn], isRoot[maxn] = {0};
int N, Q, maxbird = 0;

int findFather(int x) {
	int a = x;
	while (x != father[x]) x = father[x];
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

int main()
{
	for (int i = 1; i < maxn; ++i) {
		father[i] = i;
	}
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int birdnum;
		scanf("%d", &birdnum);
		int first;
		scanf("%d", &first);
		maxbird = first > maxbird ? first : maxbird;
		int fx = findFather(first);
		for (int j = 1; j < birdnum; ++j) {
			int bird;
			scanf("%d", &bird);
			maxbird = bird > maxbird ? bird : maxbird;
			int fy = findFather(bird);
			if (fx != fy) father[fy] = fx;
		}
	}
	for (int i = 1; i <= maxbird; ++i) {
		++isRoot[findFather(i)];
	}
	int trees = 0, birds = 0; 
	for (int i = 1; i <= maxbird; ++i) {
		if (isRoot[i] != 0) {
			++trees;
			birds += isRoot[i];
		}
	}
	printf("%d %d\n", trees, birds);
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		int b1, b2;
		scanf("%d%d", &b1, &b2);
		if (findFather(b1) == findFather(b2)) {
			printf("Yes\n");
		}
		else printf("No\n");
	}
	
	return 0;
}
