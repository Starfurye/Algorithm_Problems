#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct bign {
	int d[100];
	int len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
}Num1, Num2; 
int K;
bign change(char str[]) {
	bign a;
	a.len = strlen(str);
	for (int i = 0; i < a.len; ++i) {
		a.d[i] = str[a.len - 1 - i] - '0';
	}
	return a;
}
void reverse() {
	int i, j;
	Num2.len = Num1.len;
	for (i = 0, j = Num1.len - 1; i < Num1.len; ++i, --j) {
		Num2.d[j] = Num1.d[i];
	}
}
void add() {
	int flag = 0;
	for (int i = 0; i < Num1.len; ++i) {
		int temp = Num1.d[i] + Num2.d[i] + flag;
		Num1.d[i] = temp % 10;
		flag = temp / 10;
	}
	if (flag != 0) {
		Num1.d[Num1.len++] = flag;
	}
}
bool judge() {
	int i, j;
	for (i = 0, j = Num1.len - 1; i < j; ++i, --j) {
		if (Num1.d[i] != Num1.d[j])	return false;
	}
	return true;
}
void print() {for (int i = Num1.len - 1; i >= 0; --i)	printf("%d", Num1.d[i]);}

int main()
{
	char str[20];
	scanf("%s", str);
	Num1 = change(str);
	if (judge()) {
		print();
		printf("\n0");
		return 0;
	}
	scanf("%d", &K);
	for (int i = 1; i <= K; ++i) {
		reverse();
		add();
		if (judge()) {
			print();
			printf("\n%d", i);
			return 0;
		}
	}
	print();
	printf("\n%d", K);
	
	return 0;
}
