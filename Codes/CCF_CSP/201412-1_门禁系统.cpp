#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int n;
int arr[maxn];
int main()
{
	fill(arr, arr + maxn, 1);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int num;
		scanf("%d", &num);
		printf("%d", arr[num]++);
		if (i < n - 1) printf(" ");
	}
	
	return 0;
}
