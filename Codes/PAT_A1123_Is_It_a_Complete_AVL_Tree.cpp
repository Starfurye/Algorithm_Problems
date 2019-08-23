#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;
int N;
bool CBT = true; 
struct node {
	int v, height;
	node *lchild, *rchild;
};
node* newNode(int v) {
	node* Node = new node;
	Node->v = v;
	Node->height = 1;
	Node->lchild = Node->rchild = NULL;
	return Node;
}
int getHeight(node* root) {
	if (root == NULL) return 0;
	return root->height;
}
int getBalanceFactor(node* root) {
	return getHeight(root->lchild) - getHeight(root->rchild);
}
void updateHeight(node* root) {
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
void L(node* &root) {
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void R(node* &root) {
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node* &root, int v) {
	if (root == NULL) {
		root = newNode(v);
		return;
	}
	if (v < root->v) {
		insert(root->lchild, v);
		updateHeight(root);
		if (getBalanceFactor(root) == 2) {
			if (getBalanceFactor(root->lchild) == 1) {
				R(root);
			}
			else if (getBalanceFactor(root->lchild) == -1) {
				L(root->lchild);
				R(root);
			}
		}
	}
	else {
		insert(root->rchild, v);
		updateHeight(root);
		if (getBalanceFactor(root) == -2) {
			if (getBalanceFactor(root->rchild) == -1) {
				L(root);
			}
			else if (getBalanceFactor(root->rchild) == 1) {
				R(root->rchild);
				L(root);
			}
		}
	}
}
node* Create(int data[], int n) {
	node* root = NULL;
	for (int i = 0; i < n; ++i) {
		insert(root, data[i]);
	}
	return root;
}
node* level[25];
int pt = 1;
void levelOrder(node* root) {
	if (root == NULL) return;
	queue<node*> Q;
	Q.push(root);
	while (!Q.empty()) {
		node* front = Q.front();
		Q.pop();
		level[pt++] = front;
		if (front->lchild != NULL) Q.push(front->lchild);
		if (front->rchild != NULL) Q.push(front->rchild);
	}
}

int main()
{
	node* Root;
	scanf("%d", &N);
	int data[25];
	for (int i = 0; i < N; ++i) scanf("%d", &data[i]);
	Root = Create(data, N);
	levelOrder(Root);
	for (int i = 1; i < pt; ++i) {
		printf("%d", level[i]->v);
		if (i < pt - 1) printf(" ");
	}
	for (int i = 1; i < pt; ++i) {
		if (2 * i < pt && (level[i]->lchild == NULL || level[i]->lchild->v != level[2 * i]->v)) {
			CBT = false;
			break;
		}
		else if (2 * i + 1 < pt && (level[i]->rchild == NULL || level[i]->rchild->v != level[2 * i + 1]->v)) {
			CBT = false;
			break;
		}
	}
	printf("\n%s\n", CBT ? "YES" : "NO");
	
	return 0;
}
