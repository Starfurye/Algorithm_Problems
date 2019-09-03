#include<cstdio>
#include<cmath>

struct factor {
    int x, cnt;
}fac[10];

int N;
const int maxn = 100000;
int prime[maxn], pNum = 0;
bool p[maxn] = {false};

void Find_Prime() {
    for (int i = 2; i < maxn; ++i) {
        if (p[i] == false) {
            prime[pNum++] = i;
            for (int j = i + i; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}

int main()
{
    scanf("%d", &N);

    Find_Prime();

    int sq = (int)sqrt(N);
    int facnum = 0;
	int n = N;
    for (int i = 0; i < pNum; ++i) {
        if (prime[i] > sq || n == 1)  break;
        if (n % prime[i] == 0) {
            fac[facnum].x = prime[i];
            fac[facnum].cnt = 0;
            while (n % prime[i] == 0) {
                ++fac[facnum].cnt;
                n /= prime[i];
            }
			++facnum;
        }
    }
	if (n != 1) {
		fac[facnum].x = n;
		fac[facnum++].cnt = 1;
	}

    printf("%d=", N);
    for (int i = 0; i < facnum; ++i) {
        printf("%d", fac[i].x);
        if (fac[i].cnt > 1) printf("^%d", fac[i].cnt);
        if (i != facnum - 1)    printf("*");
    }
	if (N == 1)	printf("1");
    printf("\n");

    return 0;
}
