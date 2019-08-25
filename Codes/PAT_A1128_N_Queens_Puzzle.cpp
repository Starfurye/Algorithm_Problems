#include<cstdio>

const int maxn = 1100;
int K;
int queens[maxn];

bool judge(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (queens[j] - queens[i] == j - i || queens[i] - queens[j] == j - i || queens[i] == queens[j]) {
				return false;
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d", &K);
	for (int i = 0; i < K; ++i) {
		int N;
		scanf("%d", &N);
		for (int j = 0; j < N; ++j) {
			scanf("%d", &queens[j]);
		}
		if (judge(N) == false) {
			printf("NO\n");
		}
		else printf("YES\n");
	}
	
	return 0;
}
