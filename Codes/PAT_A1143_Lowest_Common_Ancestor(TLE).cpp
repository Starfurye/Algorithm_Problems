#include<cstdio>
#include<vector>

using namespace std;
int M, N;
struct node {
	int data;
	node* lchild; 
	node* rchild;
}*Root;
node* create(node* root, int x) {
	if (root == NULL) {
		root = new node;
		root->data = x;
		root->lchild = root->rchild = NULL;
	}
	else if (x < root->data) {
		root->lchild = create(root->lchild, x);
	}
	else {
		root->rchild = create(root->rchild, x);
	}
	return root;
}
vector<int> path1, path2;
bool flag1, flag2;
void search1(node* root, int x) {
	path1.push_back(root->data);
	if (root->data == x) {
		flag1 = true;
		return;
	}
	if (x < root->data && root->lchild) {
		search1(root->lchild, x);
	}
	else if (x >= root->data && root->rchild){
		search1(root->rchild, x);
	}
}
int pt, LCA;
void search2(node* root, int x) {
	path2.push_back(root->data);
	if (root->data == x) {
		flag2 = true;
		return;
	}
	if (x < root->data && root->lchild) {
		search2(root->lchild, x);
	}
	else if (x >= root->data && root->rchild){
		search2(root->rchild, x);
	}
}

int main()
{
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; ++i) {
		int key;
		scanf("%d", &key);
		Root = create(Root, key);	
	}
	for (int i = 0; i < M; ++i) {
		path1.clear(); path2.clear(); flag1 = flag2 = false; pt = 0;
		int U, V;
		scanf("%d%d", &U, &V);
		search1(Root, U); search2(Root, V);
		if (flag1 == false && flag2) printf("ERROR: %d is not found.\n", U);
		else if (flag1 && flag2 == false) printf("ERROR: %d is not found.\n", V);
		else if (flag1 == false && flag2 == false) printf("ERROR: %d and %d are not found.\n", U, V);
		else {
			for (int j = 0; j < min(path1.size(), path2.size()); ++j) {
				if (path1[j] == path2[j]) LCA = path1[j];
				else break;	
			}
			if (LCA == U) printf("%d is an ancestor of %d.\n", U, V);
			else if (LCA == V) printf("%d is an ancestor of %d.\n", V, U);
			else printf("LCA of %d and %d is %d.\n", U, V, LCA);
		}
	}
	
	return 0;
}
