#include<iostream>
#include<cstring>

using namespace std;
int n, a[5][5], x;
bool judge(int k) {
	for (int i = 1; i <= 3; ++i) {
		if (a[i][1] == a[i][2] && a[i][2] == a[i][3] && a[i][3] == k) return true;
		if (a[1][i] == a[2][i] && a[2][i] == a[3][i] && a[3][i] == k) return true;
	}
	if (a[1][1] == k && a[2][2] == k && a[3][3] == k) return true;
	if (a[1][3] == k && a[2][2] == k && a[3][1] == k) return true;
	return false;
}
int dfs(int k)			// k's round
{
	int t = 0;
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			if (a[i][j] == 0) ++t;
		}
	}
	if (k == 1 && judge(2)) return -t - 1;
	if (k == 2 && judge(1)) return t + 1;
	if (t == 0) return 0;
	
	int mn = 10000000, mx = -1000000;
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			if (a[i][j] == 0) {
				a[i][j] = k;
				if (k == 1) mx = max(mx, dfs(2));
				if (k == 2) mn = min(mn, dfs(1));
				a[i][j] = 0;
			}
		}
	}
	if (k == 1) return mx;
	if (k == 2) return mn;
}
int main()
{
	cin >> n;
	while (n--) {
		for (int i = 1; i <= 3; ++i) {
			for (int j = 1; j <= 3; ++j) {
				cin >> a[i][j];
			}
		}
		x = dfs(1);
		cout << x << endl;
	}
	return 0;
}
