#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 10007;
int N, K, M;
int marks[5];
struct User {
	int id;
	int marks[5];
	int total, perfect;
	bool flag;
	User() {
		id = 0; fill(marks, marks + 5, -1); total = 0; perfect = 0; flag = false;
	}
} user[10007];

void judgePerfect() {
	for (int i = 1; i < maxn; ++i) {
		if (user[i].id == 0) continue;
		else {
			for (int j = 0; j < K; ++j) {
				if (user[i].marks[j] == marks[j]) ++user[i].perfect;
				if (user[i].marks[j] != -1) {
					user[i].total += user[i].marks[j];
				}	
			}
		}
	}
}
bool cmp(User a, User b) {
	if (a.flag == b.flag) {
		if (a.total == b.total) {
			if (a.perfect == b.perfect) {
				return a.id < b.id;
			}
			return a.perfect > b.perfect;
		}
		return a.total > b.total;
	}
	return a.flag > b.flag;
}

int main()
{
	scanf("%d%d%d", &N, &K, &M);
	for (int i = 0; i < K; ++i) {
		scanf("%d", &marks[i]);
	}
	for (int i = 0; i < M; ++i) {
		int id, prob, marks; 
		scanf("%d%d%d", &id, &prob, &marks);
		user[id].id = id; 
		if (marks != -1) {
			user[id].flag = true;
			if (marks > user[id].marks[prob - 1]) {
				user[id].marks[prob - 1] = marks;
			}
		}
		else {
			if (user[id].marks[prob - 1] == -1)	user[id].marks[prob - 1] = 0;
		}
	}
	judgePerfect();
	sort(user, user + maxn, cmp);
	
	int last = user[0].total, rank = 1;
	printf("%d %05d %d ", rank, user[0].id, user[0].total);
	for (int i = 0; i < K; ++i) {
		if (user[0].marks[i] == -1) printf("-");
		else printf("%d", user[0].marks[i]);
		if (i < K - 1) printf(" ");
	}
	printf("\n");
	for (int i = 1; i < maxn; ++i) {
		if (user[i].flag == false) break;
		else if (user[i].total == last) {
			printf("%d %05d %d ", rank, user[i].id, user[i].total);
		}
		else {
			rank = i + 1; last = user[i].total;
			printf("%d %05d %d ", rank, user[i].id, user[i].total);
		}
		for (int j = 0; j < K; ++j) {
			if (user[i].marks[j] == -1) printf("-");
			else printf("%d", user[i].marks[j]);
			if (j < K - 1) printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
