#include<cstdio>

const int maxn = 10010;
int Msize, N, M;
int hashtable[maxn] = {0};

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}
bool insert(int num) {
	for (int step = 0; step < Msize; ++step) {
		int temp = num + step * step;
		if (hashtable[temp % Msize] == 0) {
			hashtable[temp % Msize] = num;
			return true;
		}
	}
	return false;
}
int find(int num) {
	int counter = 0;
	for (int step = 0; step <= Msize; ++step) {
		++counter;
		int temp = num + step * step;
		if (hashtable[temp % Msize] == num || hashtable[temp % Msize] == 0) {
			return counter;
		}
	}
	return counter;
}

int main()
{
	scanf("%d%d%d", &Msize, &N, &M);
	while (Msize < N || isPrime(Msize) == false) { ++Msize; }
	for (int i = 0; i < N; ++i) {
		int num;
		scanf("%d", &num);
		if (insert(num) == false) printf("%d cannot be inserted.\n", num);
	}
	int ans = 0;
	for (int i = 0; i < M; ++i) {
		int num;
		scanf("%d", &num);
		ans += find(num);
	}
	printf("%.1f\n", ans * 1.0 / M);

	return 0;
}
