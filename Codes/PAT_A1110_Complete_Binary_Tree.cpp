#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;
const int maxn = 100;
int N, root;
struct node {
	int lchild;
	int rchild;
}Node[maxn];
bool indice[maxn];
int getroot() {
	for (int i = 0; i < N; ++i) {
		if (!indice[i]) return i;
	}
	return -1;
}
int level[maxn];
int pt = 0;
bool levelOrder(int Root) {
	queue<int> Q;
	Q.push(Root);
	while (!Q.empty()) {
		int front = Q.front();
		Q.pop();
		if (front == -1) {
			if (pt < N) return false;
			else return true;
		}
		level[pt++] = front;
		Q.push(Node[front].lchild);
		Q.push(Node[front].rchild);
	}
}

int main()
{
	fill(indice, indice + N, false);
	fill(level, level + N, -1);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		char cl[3], cr[3];
		scanf("%s %s", &cl, &cr);
		if (cl[0] == '-') {
			Node[i].lchild = -1;
		}
		else {
			int lc; sscanf(cl, "%d", &lc);
			Node[i].lchild = lc;
		}
		if (cr[0] == '-') {
			Node[i].rchild = -1;
		}
		else {
			int rc; sscanf(cr, "%d", &rc);
			Node[i].rchild = rc;
		}
		if (Node[i].lchild != -1) indice[Node[i].lchild] = true;
		if (Node[i].rchild != -1) indice[Node[i].rchild] = true;
	}
	root = getroot();
	if(levelOrder(root)) printf("YES %d\n", level[N - 1]);
	else printf("NO %d\n", root);
	
	return 0;
}
