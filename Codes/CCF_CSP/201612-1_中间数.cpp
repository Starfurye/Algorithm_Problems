#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int> v;
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int num; cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int l, r;
	if (v.size() & 1) { l = 0; r = 0; }
	else { l = 0; r = 1; }
	int mididx = v.size() / 2;
	int midnum = v[mididx];
	for (int i = mididx; i >= 0; --i) {
		if (v[i] == midnum) ++l;
		else break;
	}
	for (int i = mididx; i < v.size(); ++i) {
		if (v[i] == midnum) ++r;
		else break;
	}
	if (l == r) {
		cout << midnum << endl;
	}
	else cout << -1 << endl;
	
	return 0;
}
