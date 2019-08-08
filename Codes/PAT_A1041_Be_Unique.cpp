#include<cstdio>

const int maxn = 10010;
const int maxc = 100010;

int N;
int numbers[maxn] = {0}, arr[maxc];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int num;
		scanf("%d", &num);
		arr[i] = num;
		++numbers[num];
	}
	for (int i = 0; i < N; ++i) {
		if (numbers[arr[i]] == 1) {
			printf("%d", arr[i]);
			return 0;
		}
	}
	printf("None");
	
	return 0;
}
