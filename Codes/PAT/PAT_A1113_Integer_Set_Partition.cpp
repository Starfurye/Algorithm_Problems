#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 100005;
int N;
int nums[maxn];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &nums[i]);
	}
	sort(nums, nums + N);
	int total1 = 0, total2 = 0;
	for (int i = 0; i < N / 2; ++i) total1 += nums[i];
	for (int i = N / 2; i < N; ++i) total2 += nums[i];
	if (N % 2 == 0) {
		printf("0 %d\n", total2 - total1);
	}
	else {
		printf("1 %d\n", total2 - total1);
	}
	
	return 0;
}
