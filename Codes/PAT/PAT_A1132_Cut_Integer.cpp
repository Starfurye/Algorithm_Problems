#include<cstdio>
#include<cstring>

int N;
int power(int n) {
	int res = 1;
	for (int i = 0; i < n; ++i) {
		res *= 10;
	}
	return res;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		char num[12];
		scanf("%s", num);
		int temp = power(strlen(num) / 2);
		int number;
		sscanf(num, "%d", &number);
		int product = (number % temp) * (number / temp);
		if (product != 0 && number % product == 0) printf("Yes\n");
		else printf("No\n"); 
	}
	
	return 0;
}
