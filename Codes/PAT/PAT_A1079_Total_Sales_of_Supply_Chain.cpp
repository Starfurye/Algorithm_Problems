#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

const int maxn = 100007;
int N;
double total = 0;
struct node {
	int product;
	int level;
	vector<int> child;
} Node[maxn];
double P, r;

void calc(int product, int level) {
	total += P * product * pow(1 + r / 100, level);
}
void PreOrder(int root, int level) {
	Node[root].level = level;
	if (Node[root].child.size() == 0) {
		calc(Node[root].product, Node[root].level);
		return;
	}
	for (int i = 0; i < Node[root].child.size(); ++i) {
		PreOrder(Node[root].child[i], level + 1);
	}
}

int main()
{
	scanf("%d %lf %lf", &N, &P, &r);
	for (int i = 0; i < N; ++i) {
		int childs;
		scanf("%d", &childs);
		if (childs == 0) {
			int product;
			scanf("%d", &product);
			Node[i].product = product;
			continue;
		}
		for (int j = 0; j < childs; ++j) {
			int child;
			scanf("%d", &child);
			Node[i].child.push_back(child);
		}
	}
	PreOrder(0, 0);
	printf("%.1f", total);	
	return 0;
}
