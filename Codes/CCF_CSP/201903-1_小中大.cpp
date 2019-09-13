#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
double arr[3];
int pt = 0;
bool cmp(double a, double b) { return a > b; }
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		double num, temp;
		scanf("%lf", &num);
		if (i == 0 || i == n - 1) arr[pt++] = num;
		if (n & 1 && i == n / 2) arr[pt++] = num;
		else if (!(n & 1)) {
			if (i == n / 2 - 1) {
				temp = num;
			}
			else if (i == n / 2) {
				temp += num; arr[pt++] = round(temp * 10 / 2) / 10;
			}
		}
	}
	sort(arr, arr + 3, cmp);
	printf("%.0f ", arr[0]);
	if (arr[1] != round(arr[1])) printf("%.1f ", arr[1]);
	else printf("%.0f ", arr[1]);
	printf("%.0f", arr[2]);
	
	return 0;
}
