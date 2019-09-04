#include<cstdio>
#include<algorithm>
using namespace std;
const long long mod = 1000000007;
long long n;
long long states[1005][6] = {0};
int main()
{
	scanf("%lld", &n);
	for (long long i = 1; i <= n; ++i) {
		states[i][0] = 1;
		states[i][1] = (states[i - 1][0] * 1 + states[i - 1][1] * 2) % mod;
		states[i][2] = (states[i - 1][0] * 1 + states[i - 1][2] * 1) % mod;
		states[i][3] = (states[i - 1][1] * 1 + states[i - 1][3] * 2) % mod;
		states[i][4] = (states[i - 1][1] * 1 + states[i - 1][2] * 1 + states[i - 1][4] * 2) % mod;
		states[i][5] = (states[i - 1][3] * 1 + states[i - 1][4] * 1 + states[i - 1][5] * 2) % mod;
	}
	printf("%lld\n", states[n][5]);
	
	return 0;
}



