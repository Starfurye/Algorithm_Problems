#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 100007;

int N, K, vN = 0;;
struct Rich {
	char name[10];
	int age;
	int money;
}rich[maxn], temp[maxn];
int Ages[maxn] = { 0 };

bool cmp(Rich a, Rich b) {
	if (a.money == b.money) {
		if (a.age == b.age){
			return strcmp(a.name, b.name) < 0;
		}
		return a.age < b.age;
	}
	return a.money > b.money;
}

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) {
		scanf("%s %d %d", temp[i].name, &temp[i].age, &temp[i].money);
	}
	sort(temp, temp + N, cmp);
	for (int i = 0; i < N; ++i) {
		if (Ages[temp[i].age] < 100) {
			rich[vN++] = temp[i];
			++Ages[temp[i].age];
		}
	}
	for (int i = 0; i < K; ++i) {
		int counts, left, right, nums = 0;
		scanf("%d%d%d", &counts, &left, &right);
		printf("Case #%d:\n", i + 1);
		for (int i = 0; i < vN && nums < counts; ++i) {
			if (rich[i].age >= left && rich[i].age <= right) {
				printf("%s %d %d\n", rich[i].name, rich[i].age, rich[i].money);
				++nums;
			}
		}
		if (nums == 0) printf("None\n");
	}
	
	return 0;
}
