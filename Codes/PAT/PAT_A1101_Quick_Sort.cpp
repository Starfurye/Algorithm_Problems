#include<cstdio>

const int maxn = 100005;
const int INF = 1000000001;
int N;
int nums[maxn];
int maxleft[maxn];
int ans[maxn];
int p = 0;

int main()
{
	scanf("%d", &N);
	int left = 0, right = INF;
	for (int i = 0; i < N; ++i) {
		int x;
		scanf("%d", &x);
		nums[i] = x;
		if (x > left) {
			left = x;
		}
		maxleft[i] = left;
	}
	int counts = 0;
	for (int i = N - 1; i >= 0; --i) {
		if (nums[i] < right) {
			right = nums[i];
		}
		if (nums[i] >= maxleft[i] && nums[i] <= right) {
			ans[p++] = nums[i];
		}
	}
	printf("%d\n", p);
	for (int i = p - 1; i >= 0; --i) {
		printf("%d", ans[i]);
		if (i > 0) printf(" ");
	}
	printf("\n");
	
	return 0;
}
