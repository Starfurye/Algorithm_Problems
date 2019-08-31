#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
const int maxn = 10002;
int N, M, K;
struct edge {
	int ed;
	bool flag;
}Edge[maxn];
void init() {
	for (int i = 0; i < M; ++i) {
		Edge[i].flag = true;
	}
}
bool judge(int v) {
	for (int i = 0; i < M; ++i) {
		if (Edge[i].ed % 10000 == v && Edge[i].flag) {
			return false;
		}
	}
	return true;
}
void update(int v) {
	bool f = false;
	for (int i = 0; i < M; ++i) {
		if (Edge[i].ed / 10000 == v) {
			Edge[i].flag = false;
			f == true;
		}
		if (f) break;
	}
}
bool cmp(edge a, edge b) {
	return a.ed < b.ed;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		Edge[i].ed = v1 * 10000 + v2;
		Edge[i].flag = true;
	}
	sort(Edge, Edge + M, cmp);
	scanf("%d", &K);
	int query[102];
	int pt = 0;
	for (int i = 0; i < K; ++i) {
		if (i != 0) init();
		for (int j = 0; j < N; ++j) {
			int v;
			scanf("%d", &v);
			if (judge(v)) {
				update(v);
			}
			else {
				string str;
				getline(cin, str);
				query[pt++] = i;
				break;
			}
		}
	}
	for (int i = 0; i < pt; ++i) {
		printf("%d", query[i]);
		if (i < pt - 1) printf(" ");
	}
	return 0;
}
