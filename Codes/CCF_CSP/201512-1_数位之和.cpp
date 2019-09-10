#include<cstdio>
int main(){
	char c = getchar(); long long total = 0;
	while (c != '\n') {total += c - '0'; c = getchar();}
	printf("%lld\n", total);
	return 0; 
}
