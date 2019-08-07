#include<cstdio>

int r, g, b;
int red[2], green[2], blue[2];
void change() {
	red[0] = r % 13;
	red[1] = r / 13 % 13;
	green[0] = g % 13;
	green[1] = g / 13 % 13;
	blue[0] = b % 13;
	blue[1] = b / 13 % 13;
}
void print(int v) {
	switch (v) {
		case 10: printf("A"); break;
		case 11: printf("B"); break;
		case 12: printf("C"); break;
		default: printf("%d", v);
	}
}

int main()
{
	scanf("%d%d%d", &r, &g, &b);
	change();
	printf("#");
	print(red[1]); print(red[0]); print(green[1]); print(green[0]); print(blue[1]); print(blue[0]);
	
	return 0;
}
