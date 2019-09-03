#include<cstdio>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<string>
#include<iostream>

using namespace std;

const int maxn = 100002;
int N;
unordered_map<string, int> sch2idx;
struct Sch {
	string name;
	int sct, sca, scb, total;
	set<int> stu;
	Sch() {
		sct = sca = scb = total = 0;
	}
}sch[maxn];
int pt = 0;
bool cmp(Sch a, Sch b) {
	if (a.total == b.total) {
		if (a.stu.size() == b.stu.size()) {
			return a.name < b.name;
		}
		return a.stu.size() < b.stu.size();
	}
	return a.total > b.total;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		char rank;	int id, score;
		getchar();
		scanf("%c", &rank);	scanf("%d%d", &id, &score);
		string school;
		cin >> school;
		for (int j = 0; j < school.size(); ++j) {
			if (school[j] <= 'Z' && school[j] >= 'A') school[j] = 'a' + school[j] - 'A';
		}
		if (sch2idx.find(school) == sch2idx.end()) {
			sch2idx[school] = pt;
			sch[pt].name = school;
			sch[pt].stu.insert(id);
			if (rank == 'T') sch[pt].sct += score;
			else if (rank == 'A') sch[pt].sca += score;
			else sch[pt].scb += score;
			++pt;
		}
		else {
			int idx = sch2idx[school];
			sch[idx].stu.insert(id);
			if (rank == 'T') sch[idx].sct += score;
			else if (rank == 'A') sch[idx].sca += score;
			else sch[idx].scb += score;
		}
	}
	for (int i = 0; i < pt; ++i) {
		sch[i].total = sch[i].scb / 1.5 + sch[i].sca + sch[i].sct * 1.5;
	}
	sort(sch, sch + pt, cmp);
	printf("%d\n", pt);
	int last = sch[0].total, rank = 1;
	printf("%d ", rank); cout << sch[0].name; printf(" %d %d\n", sch[0].total, sch[0].stu.size());
	for (int i = 1; i < pt; ++i) {
		if (sch[i].total != last) {
			rank = i + 1; last = sch[i].total;
		}
		printf("%d ", rank); cout << sch[i].name; printf(" %d %d\n", sch[i].total, sch[i].stu.size());
	}
	
	return 0;
}
