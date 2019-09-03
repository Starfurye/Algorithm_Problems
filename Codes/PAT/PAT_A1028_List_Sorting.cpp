#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

int N, C;
struct Student {
	int id;
	string name;
	int grade;
}stu[100010];

bool cmp1(Student a, Student b) {return a.id < b.id;}
bool cmp2(Student a, Student b) {
	if (a.name == b.name) {
		return a.id < b.id;
	}
	return a.name < b.name;
}
bool cmp3(Student a, Student b) {
	if (a.grade == b.grade) {
		return a.id < b.id;
	}
	return a.grade < b.grade;
}

int main()
{
	scanf("%d%d", &N, &C);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &stu[i].id);
		cin >> stu[i].name;
		scanf("%d", &stu[i].grade);
	}
	switch (C) {
		case 1: sort(stu, stu + N, cmp1); break;
		case 2: sort(stu, stu + N, cmp2); break;
		case 3: sort(stu, stu + N, cmp3); break;
		default: break;
	}
	for (int i = 0; i < N; ++i) {
		printf("%06d ", stu[i].id);
		cout << stu[i].name;
		printf(" %d\n", stu[i].grade);
	}
	
	return 0;
}
