#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

const int maxn = 105;
int N;
int in[maxn];
struct node {
	int data;
	int lchild;
	int rchild;
} Node[maxn];
int inp = 0;
void inOrder(int root) {
	if (Node[root].lchild != -1) inOrder(Node[root].lchild);
	Node[root].data = in[inp++];
	if (Node[root].rchild != -1) inOrder(Node[root].rchild);
}
void layerOrder(int root) {
	int counter = 0;
	queue<int> Q;
	Q.push(root);
	while (!Q.empty()) {
		int front = Q.front();
		Q.pop();
		printf("%d", Node[front].data);
		++counter;
		if (counter < N) printf(" ");
		if (Node[front].lchild != -1) Q.push(Node[front].lchild);
		if (Node[front].rchild != -1) Q.push(Node[front].rchild);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", &Node[i].lchild, &Node[i].rchild);
	}
	for (int i = 0; i < N; ++i) {
		scanf("%d", &in[i]);
	}
	sort(in, in + N);
	inOrder(0);
	layerOrder(0);
	
	return 0;
}
