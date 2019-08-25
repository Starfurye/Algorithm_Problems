#include<cstdio>

int N, root;
struct node {
	char data[12];
	int lchild, rchild;
}Node[25];
void inOrder(int Root) {
	if (Node[Root].rchild != -1 && Root != root) printf("(");
	if (Node[Root].lchild != -1) inOrder(Node[Root].lchild);
	printf("%s", Node[Root].data);
	if (Node[Root].rchild != -1) inOrder(Node[Root].rchild);
	if (Node[Root].rchild != -1 && Root != root) printf(")");
}

int main()
{
	scanf("%d", &N);
	bool temp[25] = {false};
	for (int i = 1; i <= N; ++i) {
		scanf("%s", Node[i].data);
		int l, r;
		scanf("%d%d", &l, &r);
		Node[i].lchild = l; Node[i].rchild = r;
		temp[l] = true; temp[r] = true;
	}
	for (int i = 1; i <= N; ++i) {
		if (!temp[i]) {
			root = i; break;
		}
	}	
	inOrder(root);
	
	return 0;
}
