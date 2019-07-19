#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

struct Fraction {
    long long up, down;
}f1, f2;

long long gcd(long long a, long long b) {
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
        long long d = gcd(abs(result.up), abs(result.down));
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

Fraction sub(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction mul(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction div(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

void showResult(Fraction r) {
    r = reduction(r);
	if (r.up < 0) printf("(");
    if (r.down == 1)  {
        printf("%lld", r.up);
    }
    else if (abs(r.up) > r.down) {
		printf("%lld %lld/%lld", (long long)(r.up / r.down), (long long)(abs(r.up)) % r.down, r.down);
    }
    else {
        printf("%lld/%lld", r.up, r.down);
    }
	if (r.up < 0) printf(")");
}

int main()
{
    scanf("%lld/%lld", &f1.up, &f1.down);
    scanf("%lld/%lld", &f2.up, &f2.down);

    Fraction sum = add(f1, f2);
    Fraction difference = sub(f1, f2);
    Fraction product = mul(f1, f2);
    Fraction quotient;
    if (f2.up) quotient = div(f1, f2);

	showResult(f1);
    printf(" + ");
	showResult(f2);
    printf(" = ");
    showResult(sum);
	printf("\n");

	showResult(f1);
    printf(" - ");
	showResult(f2);
    printf(" = ");
    showResult(difference);
	printf("\n");

	showResult(f1);
    printf(" * ");
	showResult(f2);
    printf(" = ");
    showResult(product);
	printf("\n");

	showResult(f1);
    printf(" / ");
	showResult(f2);
    printf(" = ");
    if (f2.up)  showResult(quotient);
    else printf("Inf");
	printf("\n");

    return 0;
}
