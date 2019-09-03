#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

double nums[1007], result[2014];
bool flag[2014] = {false};
int counter = 0;
int nonzero[1007];
int p = 0;

void mult(double other, int exp) {
	for (int i = 0; i < p; ++i) {
		result[nonzero[i] + exp] += other * nums[nonzero[i]];
		if (flag[nonzero[i] + exp] == false && result[nonzero[i] + exp] != 0) {
			flag[nonzero[i] + exp] = true;
			++counter;
		}
		else if (flag[nonzero[i] + exp] == true && result[nonzero[i] + exp] == 0){
			flag[nonzero[i] + exp] = false;
			--counter;
		}
	}
}

int main()
{
	memset(nums, 0, sizeof(nums));
	memset(result, 0, sizeof(result));
	int k, n;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", &n);
		scanf("%lf", &nums[n]);
		nonzero[p++] = n;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", &n);
		double other;
		scanf("%lf", &other);
		mult(other, n);
	}
	
	printf("%d", counter);
	for (int i = 2013; i >= 0; --i) {
		if (flag[i]) {
			printf(" %d %.1f", i, result[i]);
		}
	}

	return 0;
}
