#include<cstdio>
#include<algorithm>
using namespace std;
struct number {
	int value;
	int counts;
	number() {
		
		value = 10010; counts = 0;
	}
}Nums[10010];
bool cmp(number a, number b) {
	if (a.counts == b.counts) {
		return a.value < b.value;
	}
	return a.counts > b.counts;
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int t; scanf("%d", &t);
		Nums[t].value = t; ++Nums[t].counts;
	}
	sort(Nums, Nums + 10010, cmp);
	printf("%d\n", Nums[0].value);
	
	return 0;
}
