#include<cstdio>
#include<cmath>

using namespace std;
int L, K;
bool isPrime(int n) {
    if (n <= 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0)	return false;
    }
    return true;
}
int intlen(int n) {
	int len = 0;
	while (n != 0) {
		n /= 10; ++len;
	}
	return len;
}

int main()
{
	int num, exp = 1;
	char c;
	scanf("%d%d", &L, &K); getchar();
	if (K > L) {
		printf("404"); return 0;
	}
	for (int i = 1; i < K; ++i) exp *= 10;
	scanf("%c", &c); num = c - '0';
	for (int i = 1; i < K; ++i) {
		scanf("%c", &c);
		num = num * 10 + c - '0'; 
	}
	if (isPrime(num)) {
		printf("%d", num); return 0;
	}
	for (int i = K; i < L; ++i) {
		num %= exp;
		scanf("%c", &c);
		num = num * 10 + c - '0';
		if (isPrime(num)) {
			int len = intlen(num);
			for (int j = 0; j < K - len; ++j) printf("0");
			printf("%d", num); return 0;
		}
	}
	printf("404");
	
	return 0;
}
