#include<cstdio>
#include<cmath>
using namespace std;
int hashtable[1010] = {0};
int N;
int main()
{
	scanf("%d", &N);
	int counter = 0;
	for (int i = 0; i < N; ++i) {
		int num;
		scanf("%d", &num);
		if (hashtable[abs(num)] == 0) hashtable[abs(num)] = num / abs(num);
		else if (num > 0 && hashtable[abs(num)] < 0 || num < 0 && hashtable[abs(num)] > 0) ++counter;
	}
	printf("%d", counter);
	
	return 0;
}
