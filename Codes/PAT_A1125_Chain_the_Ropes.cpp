#include<cstdio>
#include<algorithm>

using namespace std;

const int maxs = 10005;
int N;
double segs[maxs];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%lf", &segs[i]);
	}
	sort(segs, segs + N);
	double ans = segs[0];
	for (int i = 1; i < N; ++i) {
		ans = (ans + segs[i]) / 2;
	}
	printf("%d\n", int(ans));
	
	return 0;
}
