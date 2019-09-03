#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

const int maxn = 100007;
int N, maxl = 0, nums = 0, Root;
vector<int> child[maxn];
double P, r;
void PreOrder(int root, int level) {
	if (child[root].size() == 0) {
		if (level > maxl) {
			maxl = level;
			nums = 1;
		}
		else if (level == maxl) ++nums;
		return;
	}
	for (int i = 0; i < child[root].size(); ++i) {
		PreOrder(child[root][i], level + 1);
	}
}

int main()
{
	scanf("%d %lf %lf", &N, &P, &r);
	r /= 100;
	for (int i = 0; i < N; ++i) {
		int parent;
		scanf("%d", &parent);
		if (parent == -1) Root = i;
		else child[parent].push_back(i);
	}
	PreOrder(Root, 0);
	printf("%.2f %d\n", P * pow(1 + r, maxl), nums);
	
	return 0;
}
