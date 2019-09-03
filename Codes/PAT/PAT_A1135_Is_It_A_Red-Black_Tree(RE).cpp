#include<cstdio>
#include<algorithm>

using namespace std;
int K;
bool Flag;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
int pre[50], in[50];
bool cmp(int a, int b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	return a < b;
}
node* create(int preL, int preR, int inL, int inR) {
	if (preL > preR) return NULL;
	node* root = new node;
	root->data = pre[preL];
	int k;
	for (k = inL; k <= inR; ++k) {
		if (in[k] == pre[preL]) break;
	}
	int numLeft = k - inL;
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}
int black;
void dfs(node* root, int tempb) {
	if (root == NULL) {
		if (black == -1) black = tempb;
		else if (tempb != black) {
			Flag = false; 
		}
		return;
	}
	int inc = 0;
	if (root->data < 0) {
		if (root->lchild && root->lchild->data < 0) {		
			Flag = false; return;
		} 
		else if (root->rchild && root->rchild->data < 0) {
			Flag = false; return;
		}
	} 
	else if (root->data > 0) inc = 1;
	dfs(root->lchild, tempb + inc);
	dfs(root->rchild, tempb + inc);
}

int main()
{
	scanf("%d", &K);
	for (int i = 0; i < K; ++i) {
		int N;
		scanf("%d", &N);
		for (int j = 0; j < N; ++j) {
			scanf("%d", &pre[j]);
			in[j] = pre[j];
		}
		sort(in, in + N, cmp);
		node* Root = create(0, N - 1, 0, N - 1);
		Flag = true; black = -1;
		if (Root && Root->data < 0) Flag = false;		
		else {
			dfs(Root, 0);
		}
		printf("%s\n", Flag ? "Yes" : "No");
	}
	
	return 0;
}
