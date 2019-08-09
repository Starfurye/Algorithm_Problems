#include<cstdio>
int main(){
	int a, b, c, d, e, f;
	scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &d, &e, &f);
	a += d; b += e; c += f;
	f = c % 29; e = b + c / 29; 
	d = a + e / 17; e = e % 17;
	printf("%d.%d.%d", d, e, f);
	return 0;
}
