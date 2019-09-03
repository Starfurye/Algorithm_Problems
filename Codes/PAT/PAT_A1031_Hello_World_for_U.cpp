#include<cstdio>
#include<cstring>

char str[85];
int len, n1, n2, n3;
int getn() {
	int max = 0;
	for (n2 = 3; n2 <= len; ++n2) {
		if ((len + 2 - n2) % 2 == 0) {
			n1 = n3 = (len + 2 - n2) / 2;
			if (n1 <= n2 && n1 > max) {
				max = n1;
			}
		}
	}
	return max;
}
void print() {
	int midspace = n2 - 2;
	for (int lr = 0; lr < n1 - 1; ++lr) {
		printf("%c", str[lr]);
		for (int space = 0; space < midspace; ++space) {
			printf(" ");
		}
		printf("%c\n", str[len - 1 - lr]);
	}
	for (int bottom = n1 - 1; bottom < n1 + n2 - 1; ++bottom) {
		printf("%c", str[bottom]);
	}
}

int main()
{
	scanf("%s", str);
	len = strlen(str);
	n1 = n3 = getn();
	n2 = len + 2 - 2 * n1;
	print();
	
	return 0;
}
