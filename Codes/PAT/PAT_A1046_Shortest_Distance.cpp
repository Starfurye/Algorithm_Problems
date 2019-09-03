#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 100007;

int N, M, total = 0;
int exits[maxn];

int calc(int e1, int e2) {
	if (e1 > e2) swap(e1, e2);
	int ans1 = exits[e2] - exits[e1];
	int ans2 = total - ans1;
	return min(ans1, ans2);
}

int main()
{
	scanf("%d", &N);
	exits[1] = 0;
	for (int i = 2; i <= N + 1; ++i) {
		int exit;
		scanf("%d", &exit);
		total += exit;
		exits[i] = exits[i - 1] + exit;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		int e1, e2;
		scanf("%d%d", &e1, &e2);
		printf("%d\n", calc(e1, e2));	
	}
	
	return 0;
}
