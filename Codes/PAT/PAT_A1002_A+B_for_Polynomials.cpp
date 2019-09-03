#include<cstdio>
#include<algorithm>
#include<cstring>

int main()
{
	double expa[1007], expb[1007];
	memset(expa, 0, sizeof(expa));
	memset(expb, 0, sizeof(expb));
	int K1, K2;
	scanf("%d", &K1);
	for (int i = 0; i < K1; ++i) {
		int N1;
		scanf("%d", &N1);
		scanf("%lf", &expa[N1]);
	}
	scanf("%d", &K2);
	for (int i = 0; i < K2; ++i) {
		int N2;
		scanf("%d", &N2);
		scanf("%lf", &expb[N2]);
	}
	int bit[1007];
	int counter = 0, p = 0;
	for (int i = 0; i < 1001; ++i) {
		expa[i] += expb[i];
		if (expa[i] != 0) {
			++counter;
			bit[p++] = i;
		}
	}
	printf("%d", counter);
	for (int i = p - 1; i >= 0; --i) {
		printf(" %d %.1f", bit[i], expa[bit[i]]);
	}
	
	return 0;
}
