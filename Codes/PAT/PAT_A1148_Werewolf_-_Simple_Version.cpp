#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;
const int maxn = 110;
int v[maxn], a[maxn];	// 1: human, -1: werewolf
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			fill(a, a + maxn, 1);
			vector<int> liar;
			a[i] = a[j] = -1;
			for (int k = 1; k <= n; ++k) {
				if (v[k] * a[abs(v[k])] < 0) liar.push_back(k);
			}
			if (liar.size() == 2 && a[liar[0]] + a[liar[1]] == 0) {
				printf("%d %d\n", i, j);
				return 0;
			}
		}
	}
	printf("No Solution\n");
	
	return 0;
}
