#include<cstdio>
int n;
int main()
{
	int count = 0, last, now; bool flag = false; // false: down, true: up
	scanf("%d", &n);
	if (n == 1){
		printf("0\n"); return 0;
	}
	scanf("%d%d", &last, &now);
	flag = now < last ? false : true;
	last = now;
	for (int i = 2; i < n; ++i) {
		scanf("%d", &now);
		if (now > last && flag == false) {
			++count; flag = true;
		}
		else if (now < last && flag == true) {
			++count; flag = false;
		}
		last = now;
	}
	printf("%d\n", count);
	
	return 0;
}
