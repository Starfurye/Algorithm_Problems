#include<cstdio>
#include<algorithm>

using namespace std;

int N, K;

const int beginTime = 8 * 60 * 60, endTime = 17 * 60 * 60, INF = 0x3f3f3f3f;

struct Person {
	int arrive;
	int process;
}person[10010];


int windows[102];
int totalwait = 0;

int convert(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}
bool cmp(Person a, Person b) {
	return a.arrive < b.arrive;
}
int getmin() {
	int min = 0, minTime = INF;
	for (int i = 0; i < K; ++i) {
		if (windows[i] == beginTime) return i;
		if (windows[i] < minTime) {
			min = i;	minTime = windows[i];
		}
	}
	return min;
}

int main()
{
	fill(windows, windows + 102, beginTime);
	scanf("%d%d", &N, &K);
	int p = 0;
	for (int i = 0; i < N; ++i) {
		int h, m, s, process;
		scanf("%d:%d:%d%d", &h, &m, &s, &process);
		if (process > 60)	process = 60;
		person[p].arrive = convert(h, m, s);
		person[p].process = process * 60;
		++p;
	}
	sort(person, person + N, cmp);
	for (int i = 0; i < N; ++i) {
		if (person[i].arrive < beginTime) {
			totalwait += beginTime - person[i].arrive;
			person[i].arrive = beginTime;
		}
		else break;
	}
	int pers = 0, win = 0;
	while (pers < N) {
		win = getmin();
		if (windows[win] != beginTime && windows[win] > person[pers].arrive) {
			totalwait += windows[win] - person[pers].arrive;
			windows[win] += person[pers].process;
		}
		else {
			windows[win] = person[pers].arrive + person[pers].process;
		}
		++pers;
		if (person[pers].arrive > endTime) {break;}
	}
	printf("%.1f", totalwait / (pers * 60.0));
	
	return 0;
}
