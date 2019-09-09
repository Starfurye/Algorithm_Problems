#include<cstdio>
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};		// 0 to 11
int leapMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	// 0 to 11
int y, d;
int main()
{
	scanf("%d%d", &y, &d);
	int day = 0;
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
		int m = 0;
		while (day + leapMonth[m] < d) {
			day += leapMonth[m++];
		}
		printf("%d\n%d\n", m + 1, d - day);
	}
	else {
		int m = 0;
		while (day + month[m] < d) {
			day += month[m++];
		}
		printf("%d\n%d\n", m + 1, d - day);
	}
	
	return 0;
}
