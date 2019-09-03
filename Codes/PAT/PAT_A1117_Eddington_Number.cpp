#include<cstdio>

const int maxn = 101000;
int arr[maxn] = {0};
int N, maxmile = 0;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int mile;
		scanf("%d", &mile);
		++arr[mile];
		maxmile = mile > maxmile ? mile : maxmile;
	}
	if (maxmile == 0) {
		printf("0\n");
		return 0;
	}
	for (int i = maxmile - 1; i >= 0; --i) {
		int temp = arr[i];
		arr[i] += arr[i + 1];
		if (arr[i] - temp >= i) {
			printf("%d\n", i);
			return 0;
		}
	}
	
	return 0;
}
