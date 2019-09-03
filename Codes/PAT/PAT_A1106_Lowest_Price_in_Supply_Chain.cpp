#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

const int maxn = 100007;
int N;
int minLevel = maxn, minretailer = 0;
vector<int> child[maxn];
double P, r;

void PreOrder(int root, int level) {
	if (child[root].size() == 0) {
		if (minLevel > level) {
			minLevel = level;
			minretailer = 1;
		}
		else if (minLevel == level) ++minretailer;
		return;
	}
	for (int i = 0; i < child[root].size(); ++i) {
		PreOrder(child[root][i], level + 1);
	}
}

int main()
{
	scanf("%d %lf %lf", &N, &P, &r);
	for (int i = 0; i < N; ++i) {
		int childs;
		scanf("%d", &childs);
		for (int j = 0; j < childs; ++j) {
			int ch;
			scanf("%d", &ch);
			child[i].push_back(ch);
		}
	}
	PreOrder(0, 0);
	printf("%.4f %d", P * pow(1 + r / 100, minLevel), minretailer);	
	return 0;
}
