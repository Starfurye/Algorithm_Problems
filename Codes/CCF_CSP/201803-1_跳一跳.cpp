#include<cstdio>
#include<iostream>
using namespace std;
int sum = 0, mul = 0;

int main()
{
	int score;
	scanf("%d", &score);
	while (score != 0) {
		if (score == 1) {
			sum += 1; mul = 0;
		}
		else {
			mul += 2;
			sum += mul;
		}
		scanf("%d", &score);
	}
	printf("%d\n", sum);
	
	return 0;
}
