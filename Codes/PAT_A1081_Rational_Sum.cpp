#include<cstdio>
#include<cmath>

using namespace std;

typedef long long LL;

const int maxf = 105;
int N;
struct Fraction {
	LL up, down;
} frac[maxf];

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}
Fraction reduction(Fraction result) {
	if (result.down < 0) {
		result.up = -result.up;
        result.down = -result.down;
	}
    if (result.up == 0) {
        result.down = 1;
    }
    else {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}
void showResult(Fraction r) {
    r = reduction(r);
    if (r.down == 1)  {
        printf("%lld", r.up);
    }
    else if (abs(r.up) > r.down) {
		printf("%lld %lld/%lld", (long long)(r.up / r.down), (long long)(abs(r.up)) % r.down, r.down);
    }
    else {
        printf("%lld/%lld", r.up, r.down);
    }
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%lld/%lld", &frac[i].up, &frac[i].down);
		frac[i] = reduction(frac[i]);
	}
	for(int i = 1; i < N; ++i) {
		frac[0] = add(frac[0], frac[i]);
	}
	showResult(frac[0]);
	
	return 0;
}
