#include<cstdio>
#include<algorithm>

using namespace std;

int N;
int d1[4], d2[4];

void changeTo(int N) {
	for (int i = 0; i <= 3; ++i) {
		d1[i] = N % 10;
		N /= 10;
	}
} 
void reverse() {
	for (int i = 0; i <= 3; ++i) {
		d2[3 - i] = d1[i];
	}
}
int changeBack(int d[]) {
	int result = 0;
	for (int i = 3; i >= 0; --i) {
		result = result * 10 + d[i];
	}
	return result;
}

int main()
{
	scanf("%d", &N);
	int C = N;
	do {
		changeTo(N); sort(d1, d1 + 4); reverse();
		int A = changeBack(d1), B = changeBack(d2);
		C = A - B;
		printf("%04d - %04d = %04d\n", A, B, C);
		N = C;
	}
	while (C != 6174 && C != 0);
	
	return 0;
}
