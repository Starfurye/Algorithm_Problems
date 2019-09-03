#include<cstdio>
#include<cstring>

int N;
struct Member {
	char name[12];
	char pass[12];
} mem[1010];

bool check(char (&str)[12]) {
	bool flag = false;
	for (int i = 0; i < strlen(str); ++i) {
		switch (str[i]) {
			case '1': str[i] = '@'; flag = true; break;
			case '0': str[i] = '%'; flag = true; break;
			case 'l': str[i] = 'L'; flag = true; break;
			case 'O': str[i] = 'o'; flag = true; break;
			default : break;
		}
	}
	return flag;
}

int main()
{
	scanf("%d", &N);
	int counter = 0;
	for (int i = 0; i < N; ++i) {
		char name[12], pass[12];
		scanf("%s %s", name, pass);
		if (check(pass)) {
			strcpy(mem[counter].name, name);
			strcpy(mem[counter].pass, pass);
			++counter;
		}
	}
	if (counter == 0) {
		if (N == 1) {
			printf("There is 1 account and no account is modified");
		}
		else {
			printf("There are %d accounts and no account is modified", N);
		}
	}
	else {
		printf("%d\n", counter);
		for (int i = 0; i < counter; ++i) {
			printf("%s %s\n", mem[i].name, mem[i].pass);
		}
	}
	
	return 0;
}
