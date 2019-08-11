#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

struct Science {
	char pos;
	int expo, dot;
	int d[20000];
}Num;

int main()
{
	int p = 0;
	char c;
	c = getchar();
	if (c == '0') {
		printf("0"); return 0;
	}
	while (c != 'E') {
		if (c == '+' || c == '-') Num.pos = c;
		else if (c == '.') Num.dot = p;
		else if (c <= '9' && c >= '0'){
			Num.d[p++] = c - '0';
		}
		c = getchar();
	}
	c = getchar();
	scanf("%d", &Num.expo);
	if (c == '-') {
		Num.expo = -Num.expo;
	}
	if (Num.pos == '-') printf("%c", Num.pos);
	if (Num.expo < 0) {
		printf("0.");
		for (int i = 1; i < -Num.expo; ++i) {
			printf("0");
		}
		for (int i = 0; i < p; ++i) {
			printf("%d", Num.d[i]);
		}
	}
	else {
		Num.dot += Num.expo;
		int j;
		bool flag = false;
		for (j = 0; j < min(Num.dot, p); ++j) {
			if (flag == false) {
				if (Num.d[j] != 0) {
					flag = true;
					printf("%d", Num.d[j]);
				}
			}
			else printf("%d", Num.d[j]);
		}
		if (j < p) {
			printf(".");
			for (; j < p; ++j) printf("%d", Num.d[j]);
		}
		else if (j == p) {
			for (; j < Num.dot; ++j) printf("0");
		}
		
	}
	
	return 0;
}
