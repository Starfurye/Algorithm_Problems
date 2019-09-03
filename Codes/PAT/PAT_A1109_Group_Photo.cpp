#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int maxn = 10005;
int N, K;
struct Person {
	char name[10];
	int height;
}person[maxn];
int block[maxn][maxn];

bool cmp(Person a, Person b) {
	if (a.height == b.height) {
		return strcmp(a.name, b.name) < 0;
	}
	return a.height > b.height;
}

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) {
		scanf("%s %d", person[i].name, &person[i].height);
	}
	sort(person, person + N, cmp);
	int rowpeople = N / K;
	int lastrow = rowpeople + N % K;
	int pt = 0;
	// last row
	int cur = lastrow / 2;
	block[0][cur] = pt++;
	int pace = 0; bool paceflag = false;
	for (int i = 1; i < lastrow; ++i) {
		pace = abs(pace) + 1;
		if (paceflag == false) {
			pace = -pace;
			paceflag = true;
		}
		else paceflag = false;
		cur += pace;
		block[0][cur] = pt++;
	}
	// other rows
	for (int i = 1; i < K; ++i) {
		cur = rowpeople / 2;
		block[i][cur] = pt++;
		pace = 0; paceflag = false;
		for (int j = 1; j < rowpeople; ++j) {
			pace = abs(pace) + 1;
			if (paceflag == false) {
				pace = -pace;
				paceflag = true;
			}
			else paceflag = false;
			cur += pace;
			block[i][cur] = pt++;
		}
	}
	for (int i = 0; i < lastrow; ++i) {
		printf("%s", person[block[0][i]].name);
		if (i < lastrow - 1) printf(" ");
	}
	printf("\n");
	for (int i = 1; i < K; ++i) {
		for (int j = 0; j < rowpeople; ++j) {
			printf("%s", person[block[i][j]].name);
			if (j < rowpeople - 1) printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
