#include<cstdio>
#include<cmath>
int n;
int main()
{
	scanf("%d", &n);
	int last, now, wave = 0;
	scanf("%d", &last);
	for (int i = 1; i < n; ++i) {
		scanf("%d", &now);
		if (abs(now - last) > wave) {
			wave = abs(now - last);
		}
		last = now;
	}
	printf("%d\n", wave);
	
	return 0;
}
