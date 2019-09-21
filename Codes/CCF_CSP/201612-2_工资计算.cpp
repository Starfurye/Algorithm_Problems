#include<iostream>
using namespace std;
double wage[7] = {3500.0, 4955.0, 7655.0, 11255.0, 30755.0, 44755.0, 61005.0};
double wage_no[7] = {3500.0, 5000.0, 8000.0, 12500.0, 38500.0, 58500.0, 83500.0};
double ratio[7] = {0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45};
double T;
int main()
{
	cin >> T;
	for (int i = 0; i < 7; ++i) {
		if (wage[i] > T) {
			int ans = wage_no[i - 1] + (T - wage[i - 1]) / (1 - ratio[i - 1]);
			printf("%d\n", ans);
			return 0;
		}
	}
	int ans = 83500 + (T - wage[6]) / 0.55;
	printf("%d\n", ans);
	
	return 0;
}
