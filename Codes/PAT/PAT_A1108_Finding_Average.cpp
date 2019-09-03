#include<cstdio>
#include<cstring>

using namespace std;

int N;
int counts = 0;
double total = 0;

bool judge(char str[], int len) {
	if (len > 8) return false;
	if (str[0] == '-') {
		if (len == 1 || str[1] < '0' || str[1] > '9') return false;
		bool dot = false;
		for (int i = 2; i < len; ++i) {
			if (str[i] == '.') {
				if (dot) return false;
				else {
					if (len - 1 - i > 2) return false;
					dot = true;
				}
			}
			else if (str[i] < '0' || str[i] > '9') return false;
		}
	}
	else if (str[0] <= '9' && str[0] >= '0') {
		bool dot = false;
		for (int i = 1; i < len; ++i) {
			if (str[i] == '.') {
				if (dot) return false;
				else {
					if (len - 1 - i > 2) return false;
					dot = true;
				}
			}
			else if (str[i] < '0' || str[i] > '9') return false;
		}
	}
	else return false;
	return true;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		char str[100000];
		scanf("%s", str);
		int len = strlen(str);
		if (!judge(str, len)) printf("ERROR: %s is not a legal number\n", str);
		else {
			double num;
			sscanf(str, "%lf", &num);
			if (num < -1000 || num > 1000) {
				printf("ERROR: %s is not a legal number\n", str);
				continue;
			}
			++counts;
			total += num;
		}
	}
	printf("The average of ");
	if (counts == 0) {
		printf("0 numbers is Undefined\n");
	}
	else if (counts == 1){
		printf("1 number is %.2f\n", total);
	}
	else {
		printf("%d numbers is %.2f\n", counts, total / counts);
	}
	
	return 0;
}
