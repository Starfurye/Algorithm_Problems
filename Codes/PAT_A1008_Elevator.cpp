#include<cstdio>

const int uptime = 6, downtime = 4, maintain = 5;

int main()
{
	int N, cur = 0, time = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int next, diff;
		scanf("%d", &next);
		diff = next - cur;
		if (diff > 0) {
			time += diff * uptime + maintain;
		}
		else {
			time += -diff * downtime + maintain;
		}
		cur = next;
	}
	printf("%d", time);
	
	return 0;
}
