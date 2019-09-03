#include<cstdio>
#include<cstring>
#include<stack>

using namespace std;

int N;
int preorder[30], inorder[30], postorder[30];
stack<int> st;
struct node {
	int data;
	node *lchild;
	node *rchild;
};
node* create(int preL, int preR, int inL, int inR) {
	if (preL > preR) return NULL;
	node *root = new node;
	root->data = preorder[preL];
	int k;
	for (k = inL; k <= inR; ++k) {
		if (inorder[k] == preorder[preL]) break;
	}
	int numLeft = k - inL;
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}
int post = 0;
void postord(node* root) {
	if (root == NULL) return;
	postord(root->lchild);
	postord(root->rchild);
	postorder[post++] = root->data;
}

int main()
{
	scanf("%d", &N);
	int pre = 0, in = 0;
	for (int i = 0; i < 2 * N; ++i) {
		char str[6];
		int node;
		scanf("%s", str);
		if (strcmp(str, "Push") == 0) {
			scanf("%d", &node);
			st.push(node);
			preorder[pre++] = node;
		}
		else {
			node = st.top();
			st.pop();
			inorder[in++] = node;
		}
	}
	node* Tree = create(0, N - 1, 0, N - 1);
	postord(Tree);
	for (int i = 0; i < N; ++i) {
		printf("%d", postorder[i]);
		if (i < N - 1) printf(" ");
	}
	
	return 0;
}
