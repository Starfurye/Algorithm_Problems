#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 1012;
struct bign {
	int d[maxn];
	int len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
}Num1, Num2, Num3; 
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
	Num3.len = Num1.len;
	for (int i = 0; i < Num1.len; ++i) {
		int temp = Num1.d[i] + Num2.d[i] + flag;
		Num3.d[i] = temp % 10;
		flag = temp / 10;
	}
	if (flag != 0) {
		Num3.d[Num3.len++] = flag;
	}
}
bool judge(bign Num) {
	int i, j;
	for (i = 0, j = Num.len - 1; i < j; ++i, --j) {
		if (Num.d[i] != Num.d[j])	return false;
	}
	return true;
}
void print(bign Num) {for (int i = Num.len - 1; i >= 0; --i)	printf("%d", Num.d[i]);}

int main()
{
	char str[maxn];
	scanf("%s", str);
	Num1 = change(str);
	if (judge(Num1)) {
		print(Num1);
		printf(" is a palindromic number.\n");
		return 0;
	}
	for (int i = 1; i <= 10; ++i) {
		reverse();
		add();
		print(Num1); printf(" + "); print(Num2); printf(" = "); print(Num3); printf("\n");
		if (judge(Num3)) {
			print(Num3);
			printf(" is a palindromic number.\n");
			return 0;
		}
		Num1.len = Num3.len;
		for (int j = 0; j < Num3.len; ++j) {
			Num1.d[j] = Num3.d[j];
		}
	}
	printf("Not found in 10 iterations.\n");
	
	return 0;
}

