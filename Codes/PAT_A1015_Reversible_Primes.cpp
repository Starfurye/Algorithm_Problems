#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0)	return false;
    }
    return true;
}

int main()
{
    int N, D;
    while (scanf("%d", &N) != EOF) {
        if (N < 0)  break;
        scanf("%d", &D);

        int z[40];
        int y = N, bit = 0;
        do {
            z[bit++] = y % D;
            y /= D;
        } while(y != 0);

        int revNum = 0, m;
        for (int j = bit - 1; j >= 0; --j) {
            m = (int)pow(D, bit - 1 - j);
            revNum += z[j] * m;
        }
        if (isPrime(N) && isPrime(revNum))  printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
