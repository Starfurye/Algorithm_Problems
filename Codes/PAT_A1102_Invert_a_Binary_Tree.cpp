#include<cstdio>
#include<queue>

using namespace std;

int N;
struct node {
	int lchild;
	int rchild;
}Node[12];
int p = 0, q = 0;
int level[12], in[12];

void levelOrder(int root) {
	queue<int> Q;
	Q.push(root);
	while (!Q.empty()) {
		int front = Q.front();
		level[p++] = front;
		Q.pop();
		if (Node[front].lchild != -1) Q.push(Node[front].lchild);
		if (Node[front].rchild != -1) Q.push(Node[front].rchild);
	}
}
void inOrder(int root) {
	if (Node[root].lchild != -1) inOrder(Node[root].lchild);
	in[q++] = root;
	if (Node[root].rchild != -1) inOrder(Node[root].rchild);
}

int main()
{
	scanf("%d", &N);
	bool judgeroot[12];
	fill(judgeroot, judgeroot + 12, false);
	for (int i = 0; i < N; ++i) {
		char l, r;
		getchar();
		scanf("%c %c", &r, &l);
		if (l == '-') {
			Node[i].lchild = -1;
		}
		else {
			Node[i].lchild = l - '0';
			judgeroot[l - '0'] = true;
		}
		if (r == '-') {
			Node[i].rchild = -1;
		}
		else {
			Node[i].rchild = r - '0';
			judgeroot[r - '0'] = true;
		}
	}
	int root;
	for (int i = 0; i < N; ++i) {
		if (!judgeroot[i]) {
			root = i;
			break;
		}
	}
	levelOrder(root); inOrder(root);
	for (int i = 0; i < N; ++i) {
		printf("%d", level[i]);
		if (i < N - 1) printf(" ");
	}
	printf("\n");
	for (int i = 0; i < N; ++i) {
		printf("%d", in[i]);
		if (i < N - 1) printf(" ");
	}
	
	return 0;
}
