#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

const int maxn = 10010;

int N;
string digits[maxn];
bool cmp(string a, string b) {return a + b < b + a;}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {cin >> digits[i];}
	sort(digits, digits + N, cmp);
	string ans;
	for (int i = 0; i < N; ++i) {
		ans += digits[i];
	}
	while (ans.size() != 0 && ans[0] == '0') {
		ans.erase(ans.begin());
	}
	if (ans.size() == 0) printf("0");
	else cout << ans;
	
	return 0;
}
