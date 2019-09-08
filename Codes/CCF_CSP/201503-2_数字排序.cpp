#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int n;
struct num {
	int value;
	int times;
	num() {
		value = 1002; times = 0;
	}
}Num[maxn];
bool cmp(num a, num b) {
	if (a.times == b.times) return a.value < b.value;
	return a.times > b.times; 
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int t; scanf("%d", &t);
		++Num[t].times; Num[t].value = t;
	}
	sort(Num, Num + maxn, cmp);
	int i = 0;
	while (Num[i].times != 0) {
		printf("%d %d\n", Num[i].value, Num[i].times);
		++i;
	}
	
	return 0;
}
