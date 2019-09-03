#include<cstdio>
char str[14];
int main()
{
	scanf("%s", str);
	int temp = str[0] - '0';
	for (int i = 2; i <= 4; ++i) {
		temp += (str[i] - '0') * i;
	}
	for (int i = 6; i <= 10; ++i) {
		temp += (str[i] - '0') * (i - 1);
	}
	if (str[12] - '0' == temp % 11 || str[12] == 'X' && temp % 11 == 10) {
		printf("Right\n");
	}
	else {
		if (temp % 11 == 10) str[12] = 'X';
		else str[12] = temp % 11 + '0';
		printf("%s\n", str);
	}
	
	return 0;
}
