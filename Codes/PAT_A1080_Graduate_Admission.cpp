#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int maxg = 40007;
const int maxs = 105;

int N, M, K;
struct School {
	int quota;
	vector<int> stu;
	int lastGE, lastTotal;
} school[maxs];
struct App {
	int GE;
	int GI;
	int total;
	int ord;
	int pre[5];
} app[maxg];
bool cmp(App a, App b) {
	if (a.total == b.total) {
		return a.GE > b.GE;
	}
	return a.total > b.total;
}

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < M; ++i) {
		scanf("%d", &school[i].quota);
	}
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", &app[i].GE, &app[i].GI);
		app[i].total = app[i].GE + app[i].GI;
		app[i].ord = i;
		for (int j = 0; j < K; ++j) {
			scanf("%d", &app[i].pre[j]);
		}
	}
	sort(app, app + N, cmp);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			int sch = app[i].pre[j];
			if (school[sch].quota > 0) {
				--school[sch].quota;
				school[sch].stu.push_back(app[i].ord);
				school[sch].lastGE = app[i].GE;
				school[sch].lastTotal = app[i].total;
				break;
			}
			else {
				if (school[sch].lastGE == app[i].GE && school[sch].lastTotal == app[i].total) {
					school[sch].stu.push_back(app[i].ord);
					break;
				}
			}
			
		}
	}
	for (int i = 0; i < M; ++i) {
		int stus = school[i].stu.size();
		sort(school[i].stu.begin(), school[i].stu.end());
		for (int j = 0; j < stus; ++j) {
			printf("%d", school[i].stu[j]);
			if (j < stus - 1) printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
