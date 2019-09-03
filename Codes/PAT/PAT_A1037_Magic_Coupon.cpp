#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 100010;
typedef long long LL;

int Nc, Np;
LL coupon[maxn], products[maxn];
LL money; 
bool cmp(LL a, LL b)	{return a > b;}

int main()
{
	scanf("%d", &Nc);
	for (int i = 0; i < Nc; ++i) {scanf("%lld", &coupon[i]);}
	scanf("%d", &Np);
	for (int i = 0; i < Np; ++i) {scanf("%lld", &products[i]);}
	sort(coupon, coupon + Nc, cmp);
	sort(products, products + Np, cmp);
	int p = 0, q = 0;
	while (coupon[p] > 0 && products[q] > 0) {
		money += coupon[p] * products[q];
		++p; ++q;
	}
	p = Nc - 1, q = Np - 1;
	while (coupon[p] < 0 && products[q] < 0) {
		money += coupon[p] * products[q];
		--p; --q;
	}
	printf("%lld", money);
	
	return 0;
}
