#include<iostream>
using namespace std;
int n;
int main()
{
	int ppre, pre;
	cin >> n;
	cin >> pre; cin >> ppre;
	cout << (ppre + pre) / 2;
	for (int i = 1; i < n - 1; i++) {
		cout << " ";
		int t;
		cin >> t;
		cout << (t + ppre + pre) / 3;
		pre = ppre; ppre = t;
	}
	cout << " ";
	cout << (ppre + pre) / 2;
	
	return 0;
}
