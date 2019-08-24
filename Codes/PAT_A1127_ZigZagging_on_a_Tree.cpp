#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn = 32;
struct node {
    int data;
    node* lchild;
    node* rchild;
};
int pre[maxn], in[maxn], post[maxn];
int n;

node* create(int postL, int postR, int inL, int inR) {
    if (postL > postR)  return NULL;
    node* root = new node;
    root->data = post[postR];
    int k;
    for (k = inL; k <= inR; ++k) {
        if (in[k] == post[postR]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    return root;
}

vector<int> levels[maxn];
int num = 0, maxlevel = 0;
void dfs(node* root, int level) {
	maxlevel = max(maxlevel, level);
	levels[level].push_back(root->data);
	if (root->lchild != NULL) dfs(root->lchild, level + 1);
	if (root->rchild != NULL) dfs(root->rchild, level + 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }
	for (int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }
    node* root = create(0, n - 1, 0, n - 1);
    dfs(root, 0);
    int p = 0;
    while (p <= maxlevel) {
    	if (p % 2 == 0) {
    		reverse(levels[p].begin(), levels[p].end());
		}
		for (int i = 0; i < levels[p].size(); ++i) {
			printf("%d", levels[p][i]);
			if (p != maxlevel || i < levels[p].size() - 1) {
				printf(" ");
			}
		}
		++p;
	}

    return 0;
}

