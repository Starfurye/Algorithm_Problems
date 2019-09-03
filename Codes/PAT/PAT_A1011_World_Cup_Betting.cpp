#include<cstdio>

int main()
{
	double arr[3];
	int sel[3];
	double result = 1;
	for (int i = 0; i < 3; ++i) {
		scanf("%lf%lf%lf", &arr[0], &arr[1], &arr[2]);
		double max = arr[0];
		sel[i] = 0;
		if (arr[1] > max) {
			max = arr[1];	sel[i] = 1;
		}
		if (arr[2] > max) {
			max = arr[2];	sel[i] = 2;
		}
		result *= max;
	}
	for (int i = 0; i < 3; ++i) {
		switch(sel[i]) {
			case 0: printf("W "); break;
			case 1: printf("T "); break;
			case 2: printf("L "); break;
			default: break;
		}
	}
	result = (result * 0.65 - 1) * 2;
	printf("%.2f", result);
}
