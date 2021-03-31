#include<iostream>
using namespace std;

int n;
struct period {
	int l, r;
}PER[2005];
int p = 0;
int talk = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		PER[i].l = a; PER[i].r = b;
	}
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		bool flag = false;
		while (!flag) {
			if (b <= PER[p].l) {
				flag = true;
			}
			else if (a < PER[p].l && PER[p].l < b && PER[p].r > b) {
				talk += b - PER[p].l;
				flag = true;
			}
			else if (a >= PER[p].l && b <= PER[p].r) {
				talk += b - a;
				flag = true;
			}
			else if (a > PER[p].l && a < PER[p].r && b > PER[p].r) {
				talk += PER[p].r - a;
				a = PER[p].r;
			}
			else if (a >= PER[p].r) {
				++p;
				if (p == n) flag = true;
			}
			else if (a <= PER[p].l && b >= PER[p].r) {
				talk += PER[p].r - PER[p].l;
				a = PER[p].r;
				++p;
				if (p == n) flag = true;
			}
		}
	}
	cout << talk;
	
	return 0;
}
