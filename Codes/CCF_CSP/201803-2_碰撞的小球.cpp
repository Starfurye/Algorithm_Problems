#include<cstdio>

using namespace std;
int n, L, t;
int balls[1010] = {0};
struct ball{
	int place;
	int dir;	// 1: +, 0: -
}Ball[108];

void dealborder(int ord, int pl) {
	if (pl == 0 || pl == L) Ball[ord].dir = 1 - Ball[ord].dir;
}
void move() {
	for (int i = 1; i <= n; ++i) {
		int p = Ball[i].place;
		dealborder(i, p);
		int d = Ball[i].dir;
		balls[p] = 0;
		if (d) Ball[i].place++;
		else Ball[i].place--;
		p = Ball[i].place;
		if (balls[p]) {
			Ball[i].dir = 1 - Ball[i].dir;
			Ball[balls[p]].dir = 1 - Ball[i].dir;
			balls[p] = 0;
		}
		else balls[p] = i;
	}
}
int main()
{
	scanf("%d%d%d", &n, &L, &t);
	for (int i = 1; i <= n; ++i) {
		int p;
		scanf("%d", &p);
		balls[p] = i;
		Ball[i].place = p; Ball[i].dir = 1;
	}
	int time = 0;
	while (++time <= t) {
		move();
	}
	
	for (int i = 1; i <= n; ++i) {
		printf("%d", Ball[i].place);
		if (i < n) printf(" ");
	}
	printf("\n");
	return 0;
}
