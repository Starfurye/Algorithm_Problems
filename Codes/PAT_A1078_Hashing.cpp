#include<cstdio>

const int maxn = 10007;

int M, N;
int hashTable[maxn] = {0};

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)	return false;
    }
    return true;
}
int insert(int num) {
	if (hashTable[num % M] == 0) {
		hashTable[num % M] = num;
		return num % M;
	}
	else {
		for (int step = 1; step < M; ++step) {
			int temp = num + step * step;
			if (hashTable[temp % M] == 0) {
				hashTable[temp % M] = num;
				return temp % M;
			}	
		}
		return -1;
	}
}

int main()
{
	scanf("%d%d", &M, &N);
	while (M < N || isPrime(M) == false) {++M;}
	for (int i = 0; i < N; ++i) {
		int num;
		scanf("%d", &num);
		int result = insert(num);
		if (result == -1) printf("-");
		else printf("%d", result);
		if (i < N - 1) printf(" ");
	}
	
	return 0;
}
