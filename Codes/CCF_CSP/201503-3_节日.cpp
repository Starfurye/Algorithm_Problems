#include<cstdio>
int firstday[205];
bool leap[205] = {false};
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};		// 0 to 11
int leapMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	// 0 to 11
void init() {
	int last = 2; firstday[0] = 2;
	for (int i = 1850; i < 2050; ++i) {
		if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) {
			last += 2; leap[i - 1850] = true;
		}	
		else {
			last += 1; leap[i - 1850] = false;
		}
		if (last > 7) last -= 7;
		firstday[i + 1 - 1850] = last; 
	}
}
int a, b, c, y1, y2;

int main()
{
	init();
	scanf("%d%d%d%d%d", &a, &b, &c, &y1, &y2);
	for (int i = y1; i <= y2; ++i) {
		int tempday = 1;
		if (firstday[i - 1850] <= c) tempday += c - firstday[i - 1850];
		else tempday += 7 - (firstday[i - 1850] - c);
		int allmonth = 0;
		if (leap[i - 1850]) {
			for (int j = 0; j < a - 1; ++j) {
				allmonth += leapMonth[j];
			}
		}
		else {
			for (int j = 0; j < a - 1; ++j) {
				allmonth += month[j];
			}
		}
		while (tempday < allmonth) tempday += 7;
		tempday -= allmonth;
		if (tempday == 0) tempday += 7;
		for (int j = 1; j < b; ++j) tempday += 7;
		if (leap[i - 1850] && tempday > leapMonth[a - 1] || !leap[i - 1850] && tempday > month[a - 1]) printf("none\n");
		else printf("%d/%02d/%02d\n", i, a, tempday); 
	}
	
	return 0;
}
