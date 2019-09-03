#include<cstdio>
#include<algorithm>

using namespace std;

int N, b, bit = 0;
int arr[33];

void change() {
	int n = N;
	while (n > 0) {
		arr[bit++] = n % b;
		n /= b;
	}
}

bool judge() {
	int i = 0, j = bit - 1;
	bool flag = true;
	while (i <= j) {
		if (arr[i] != arr[j]) {
			flag = false;	break;
		}
		++i; --j;
	}
	return flag;
}

void print() {
	for (int i = bit - 1; i >= 0; --i) {
		printf("%d", arr[i]);
		if (i > 0)	printf(" ");
	}
}

int main()
{
	scanf("%d%d", &N, &b);
	if (N == 0) {
		printf("Yes\n0");
		return 0;
	}
	change();
	if (judge()) {
		printf("Yes\n");
		print();
	}
	else {
		printf("No\n");
		print();
	}
	
	return 0;
}
