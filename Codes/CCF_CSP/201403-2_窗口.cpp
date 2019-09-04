#include<cstdio>
#include<algorithm>
using namespace std;
int N, M;
struct win {
	int x1, y1, x2, y2;
	int name;
	int order;
}Win[12];
bool cmp(win a, win b) {
	return a.order > b.order;
}
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d%d%d", &Win[i].x1, &Win[i].y1, &Win[i].x2, &Win[i].y2); Win[i].order = i; Win[i].name = i + 1;
	}
	sort(Win, Win + N, cmp);
	int ord = 100;
	for (int i = 0; i < M; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		int j;
		for (j = 0; j < N; ++j) {
			if (x >= Win[j].x1 && x <= Win[j].x2 && y >= Win[j].y1 && y <= Win[j].y2) {
				Win[j].order = ord++; printf("%d\n", Win[j].name); break;
			}
		}
		if (j == N) printf("IGNORED\n");
		sort(Win, Win + N, cmp);
	}
	
	return 0;
}
