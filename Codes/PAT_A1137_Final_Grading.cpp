#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<unordered_map>

using namespace std;

const int maxs = 10010;
int P, M, N;
struct Stu {
	string id;
	int p, m, f, final;
	bool flag;
	Stu() {
		p = m = f = final = -1; flag = false;
	}
}stu[maxs];
int pt = 0;
unordered_map<string, int> id2idx;
bool cmp(Stu a, Stu b) {
	if (a.flag == b.flag) {
		if (a.final == b.final) {
			return a.id < b.id;
		}
		return a.final > b.final;
	}
	return a.flag > b.flag;
}

int main()
{
	scanf("%d%d%d", &P, &M, &N);
	for (int i = 0; i < P; ++i) {
		string id; int pr;
		cin >> id; scanf("%d", &pr);
		stu[pt].id = id; stu[pt].p = pr;
		if (pr >= 200) stu[pt].flag = true;
		id2idx[id] = pt++;
	}
	for (int i = 0; i < M; ++i) {
		string id; int mid;
		cin >> id; scanf("%d", &mid);
		if (id2idx.find(id) != id2idx.end()) {
			stu[id2idx[id]].m = mid;
		}
	}
	for (int i = 0; i < N; ++i) {
		string id; int fin;
		cin >> id; scanf("%d", &fin);
		if (id2idx.find(id) != id2idx.end()) {
			int idx = id2idx[id];
			stu[idx].f = fin;
			if (stu[idx].flag) {
				stu[idx].final = stu[idx].m > stu[idx].f ? (int)round(stu[idx].m * 0.4 + stu[idx].f * 0.6) : stu[idx].f;
				if (stu[idx].final < 60 || stu[idx].final > 100) {
					stu[idx].flag = false;
				}
			}
		}
	}
	for (int i = 0; i < pt; ++i) {
		if (stu[i].f == -1) stu[i].flag = false;
	}
	sort(stu, stu + pt, cmp);
	for (int i = 0; i < pt && stu[i].flag; ++i) {
		cout << stu[i].id;
		printf(" %d %d %d %d\n", stu[i].p, stu[i].m, stu[i].f, stu[i].final);
	}
	
	return 0;
}
