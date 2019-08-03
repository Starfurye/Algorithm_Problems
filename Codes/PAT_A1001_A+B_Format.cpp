#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int a, b, c, arr[7];
	scanf("%d%d", &a, &b);
	c = a + b;
	if (c < 0) c = -c;
	else if (c == 0) {
		printf("0");
		return 0;
	}
	
	int i = 0;
	while (c > 0) {
		arr[i++] = c % 10;
		c /= 10;
	}
	if (a + b < 0) {
		printf("-");
	}
	for (int j = i - 1; j >= 0; --j) {
		printf("%d",arr[j]);
		if (j % 3  == 0 && j > 0) printf(",");
	}
	
	return 0;
}
