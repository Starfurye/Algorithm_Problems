#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
const int maxn = 105;
int nextt[maxn];
char str[maxn], strtmp[maxn];
void getNext(char s[], int len) {
	int j = -1;
	nextt[0] = -1;
	for (int i = 1; i < len; ++i) {
		while (j != -1 && s[i] != s[j + 1]) {
			j = nextt[j];
		}
		if (s[i] == s[j + 1]) {
			++j;
		}
		nextt[i] = j;
	}
}
bool KMP(char text[], char pattern[]) {
	int n = strlen(text), m = strlen(pattern);
	getNext(pattern, m);
	int j = -1;
	for (int i = 0; i < n; ++i) {
		while (j != -1 && text[i] != pattern[j + 1]) {
			j = nextt[j];
		}
		if (text[i] == pattern[j + 1]) {
			++j;
		}
		if (j == m - 1) {
			return true;
		}
	}
	return false;
} 
bool Cap;
int main()
{
	scanf("%s", str);
	strcpy(strtmp, str);
	for (int i = 0; i < strlen(strtmp); ++i) {
		if (strtmp[i] <= 'Z' && strtmp[i] >= 'A') {
			strtmp[i] -= 'A' - 'a';
		}
	}
	int n;
	scanf("%d", &n); Cap = n == 1 ? true : false;
	scanf("%d", &n);
	for (int j = 0; j < n; ++j) {
		char test[maxn]; bool same = false;
		scanf("%s", test); 
		if (!Cap) {
			char temp[maxn];
			strcpy(temp, test);
			for (int i = 0; i < strlen(temp); ++i) {
				if (temp[i] <= 'Z' && temp[i] >= 'A') {
					temp[i] -= 'A' - 'a';
				}
			}
			if (KMP(temp, strtmp)) same = true;	
		}
		else {
			if (KMP(test, str)) same = true;
		}
		if (same) printf("%s\n", test);
	}
	
	
	return 0;
}
