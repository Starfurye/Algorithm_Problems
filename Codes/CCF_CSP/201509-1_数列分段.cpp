#include<cstdio>
int n;
int counter = 1;
int main()
{
	scanf("%d", &n);
	int num; scanf("%d", &num);
	for (int i = 1; i < n; ++i) {
		int now; scanf("%d", &now);
		if (now != num) {
			++counter; num = now;
		}
	}
	printf("%d\n", counter);
	
	return 0;
}
