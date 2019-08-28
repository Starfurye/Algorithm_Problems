#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

unordered_map<int, bool> arr;		// friends
struct node {	// answer
	int a, b;
};
bool cmp(node x, node y) {return x.a == y.a ? x.b < y.b : x.a < y.a;}

int main()
{
	int n, m, k;
	scanf("%d%d", &n, &m);
	vector<int> v[10000];			// friends of same gender
	for (int i = 0; i < m; ++i) {
		string a, b;
		cin >> a >> b;
		if (a.size() == b.size()) {
			v[abs(stoi(a))].push_back(abs(stoi(b)));
			v[abs(stoi(b))].push_back(abs(stoi(a)));
		}
		arr[abs(stoi(a)) * 10000 + abs(stoi(b))] = arr[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		int c, d;
		scanf("%d%d", &c, &d);
		vector<node> ans;
		for (int j = 0; j < v[abs(c)].size(); ++j) {
			for (int k = 0; k < v[abs(d)].size(); ++k) {
				if (v[abs(c)][j] == abs(d) || v[abs(d)][k] == abs(c)) continue;	// friend of A(B) is B(A), skip
				if (arr[v[abs(c)][j] * 10000 + v[abs(d)][k]] == true) {
					ans.push_back(node{v[abs(c)][j], v[abs(d)][k]});
				}
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		printf("%d\n", (int)ans.size());
		for (int j = 0; j < ans.size(); ++j) {
			printf("%04d %04d\n", ans[j].a, ans[j].b);
		}
	}
	
	return 0;
}
