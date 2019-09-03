#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 10000;

struct Student {
	char name[12];
	char id[12];
	int grade;
} student[maxn];
int N;
bool cmp(Student a, Student b) {
	return a.grade > b.grade;
}

int main()
{
	scanf("%d", &N);
	int p = 0;
	for (int i = 0; i < N; ++i) {
		scanf("%s %s %d", student[p].name, student[p].id, &student[p].grade);
		++p;
	}
	int left, right;
	scanf("%d%d", &left, &right);
	sort(student, student + N, cmp);
	p = 0;
	if (student[0].grade < left || student[N - 1].grade > right) printf("NONE");
	while (p < N) {
		if (student[p].grade >= left && student[p].grade <= right) {
			printf("%s %s\n", student[p].name, student[p].id);
		}
		++p;
	}
	
	return 0;
}
