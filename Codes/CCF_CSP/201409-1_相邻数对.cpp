#include<cstdio>
const int maxn = 10005;
int n;
int arr[maxn] = {0};
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int num; scanf("%d", &num);
		arr[num] = 1;
	}
	bool flag = false;
	int counter = 0;
	for (int i = 0; i <= 10000; ++i) {
		if (arr[i] == 1) {
			if (flag == false) flag = true;
			else ++counter;
		}
		else flag = false;
	}
	printf("%d\n", counter);
	
	return 0;
}
