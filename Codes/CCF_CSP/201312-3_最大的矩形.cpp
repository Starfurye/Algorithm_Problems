#include<cstdio>
const int maxn = 1010;
int n;
int blocks[maxn];
int main()
{
	int maxb = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &blocks[i]);
		maxb = blocks[i] > maxb ? blocks[i] : maxb;
	}
	int maxarea = maxb; 
	for (int i = 1; i <= maxb; ++i) {
		int temparea = 0;	//*
		for (int j = 0; j < n; ++j) {
			if (blocks[j] >= i) {
				temparea += i;
			}
			else temparea = 0;
			if (temparea > maxarea) maxarea = temparea;
		}
	}
	printf("%d\n", maxarea);
	
	return 0;
}
