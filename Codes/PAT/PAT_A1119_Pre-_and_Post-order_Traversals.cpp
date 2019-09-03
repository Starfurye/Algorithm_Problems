#include<cstdio>

const int maxn = 35;
int N, index = 0;
bool flag = true;
struct Node {
	int data;
	Node *lchild, *rchild;
} *Root;
int pre[maxn], post[maxn];
Node *create(int preL, int preR, int postL, int postR) {
	if (preL > preR) return NULL;
	Node* node = new Node;
	node->data = pre[preL];
	node->lchild = NULL;
	node->rchild = NULL;
	if (preL == preR) return node;
	int k = 0;
	for (k = preL + 1; k <= preR; ++k) {
		if (pre[k] == post[postR - 1]) break;
	}
	if (k - preL > 1) {
		node->lchild = create(preL + 1, k - 1, postL, postL + k - preL - 2);
		node->rchild = create(k, preR, postL + k - preL - 1, postR - 1);
	}
	else {
		flag = false;
		node->rchild = create(k, preR, postL + k - preL - 1, postR - 1);
	}
	return node;
}
void inOrder(Node* root) {
	if (root == NULL) return;
	inOrder(root->lchild);
	if (index < N - 1) {
		printf("%d ", root->data);
	}
	else printf("%d\n", root->data);
	++index;
	inOrder(root->rchild);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < N; ++i) {
		scanf("%d", &post[i]);
	}
	Root = create(0, N - 1, 0, N - 1);
	if (flag) printf("Yes\n");
	else printf("No\n");
	inOrder(Root);
	
	return 0;
}
