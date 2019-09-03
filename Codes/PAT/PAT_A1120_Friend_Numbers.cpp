#include<cstdio>
#include<cstring>
#include<set>

const int maxn = 100000;
using namespace std;
int N;
set<int> nums;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		char str[6];
		scanf("%s", str);
		int len = strlen(str);
		int total = 0;
		for (int j = 0; j < len; ++j) {
			total += str[j] - '0';
		}
		nums.insert(total);
	}
	int arr[maxn];
	int pt = 0;
	for (set<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
		arr[pt++] = *it;
	}
	printf("%d\n", pt);
	for (int i = 0; i < pt; ++i) {
		printf("%d", arr[i]);
		if (i < pt - 1) printf(" ");
	}
	
	return 0;	
} 
