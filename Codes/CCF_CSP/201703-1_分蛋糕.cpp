#include<iostream>
using namespace std;
int n, k;
int main()
{
	cin >> n >> k;
	int counter = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		int cake;
		cin >> cake;
		if (counter == 0) ++ans;
		counter += cake;
		if (counter >= k) {
			counter = 0; 
		}
	}
	cout << ans;
	
	return 0;
}
