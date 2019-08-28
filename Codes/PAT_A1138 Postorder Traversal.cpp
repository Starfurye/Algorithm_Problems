#include<cstdio>

int N;
const int maxn = 50010;
int pre[maxn], in[maxn];
int last;
int findk(int inL, int inR, int preL) {
	int k;
	for (k = inL; k <= inR; ++k) {
		if (in[k] == pre[preL]) break;
	}
	return k;
}
void judge(int preL, int preR, int inL, int inR) {
	while (preL < preR) {
		last = pre[preL];
		int k = findk(inL, inR, preL);
		int numLeft = k - inL;
		if (numLeft > 0) {
			preL = preL + 1; preR = preL + numLeft; inR = k - 1;
		}
		else if (preR > k) {
			preL = preL + numLeft + 1; inL = k + 1;
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < N; ++i) {
		scanf("%d", &in[i]);
	}
	judge(0, N - 1, 0, N - 1);
	printf("%d\n", last);
	
	return 0;
}
