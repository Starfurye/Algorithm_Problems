#include<cstdio>

int N;
const int maxn = 1005;
struct node {
	int data;
	int level;
	node *lchild;
	node *rchild;
}*T;
int levels[maxn] = {0};

void init() {
	T = NULL;
}
void insert(node* &root, int x, int level) {
	if (root == NULL) {
		node* Node = new node;
		Node->data = x;
		Node->lchild = Node->rchild = NULL;
		Node->level = level;
		++levels[level];
		root = Node;
		return;
	}
	if (x <= root->data) {
		insert(root->lchild, x, level + 1);
	}
	else {
		insert(root->rchild, x, level + 1);
	}
}

int main()
{
	init();
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int key;
		scanf("%d", &key);
		if (key >= -1000 && key <= 1000) insert(T, key, 0);
	}
	int pt = 0;
	while (levels[pt]) {
		++pt;
	}
	if (pt == 1) printf("%d + 0 = %d\n", levels[0], levels[0]);
	else if (pt == 0) printf("0 + 0 = 0\n");
	else printf("%d + %d = %d\n", levels[pt - 1], levels[pt - 2], levels[pt - 2] + levels[pt - 1]);
	
	return 0;
}
