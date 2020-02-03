#include<iostream>
using namespace std;
const int maxn = 10010;
int n;
int a[maxn] = {0};
int main()
{
	int minn = maxn;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		minn = minn > m ? m : minn;
		if (a[m] == 1) {
			printf("0\n");
			return 0;
		}
		else a[m] = 1;
	}
	int c = 1, minc = maxn;
	for (int i = minn + 1; i < maxn; ++i) {
		if (a[i] == 1) {
			minc = minc > c ? c : minc;
			if (minc == 1) {
				printf("1\n");
				return 0;
			}
			c = 1;
		}
		else {
			++c;
		}
	}
	printf("%d\n", minc);
	
	return 0;
}
