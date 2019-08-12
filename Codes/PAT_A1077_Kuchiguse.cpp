#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;
int N;
string hanashi[101];
char kcgs[258];

int main()
{
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; ++i) {
		getline(cin, hanashi[i]);
		reverse(hanashi[i].begin(), hanashi[i].end());
	}
	int p = 0;
	for (int i = 0; i < 258; ++i) {
		bool flag = true;
		char c = hanashi[0][i];
		for (int j = 1; j < N; ++j) {
			if (hanashi[j][i] != c) {
				flag = false; break;
			}
		}
		if (flag == false) {
			int len = strlen(kcgs);
			if (len == 0) {
				printf("nai");
			}
			else {
				for (int k = len - 1; k >= 0; --k) {
					printf("%c", kcgs[k]);
				}
			}
			return 0;
		}
		else {
			kcgs[p++] = c;
		}
	}
	
	return 0;
}
