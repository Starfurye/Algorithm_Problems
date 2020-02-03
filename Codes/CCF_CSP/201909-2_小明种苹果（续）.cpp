#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int N;
struct Node {
	int drop;
	int pre;
	int next;
};
vector<Node> appleTree;
int allApples = 0;
int dropTrees = 0;
int dropGroup = 0;
int firstNoDrop = 0;

int main()
{
	// freopen("in.txt", "r", stdin);
	
	appleTree.push_back(Node{0, 0, 1});
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int m, lastApples, tempDrops = 0;
		cin >> m;
		cin >> lastApples;
		for (int j = 0; j < m - 1; ++j) {
			int temp;
			cin >> temp;
			if (temp > 0) {
				tempDrops += lastApples - temp;
				lastApples = temp;
			}
			else {
				lastApples += temp;
			}
		}
		if (tempDrops == 0) {
			if (firstNoDrop == 0) firstNoDrop = i + 1;
		}
		else ++dropTrees;
		allApples += lastApples;
		appleTree.push_back(Node{tempDrops, i, i + 2});
	}
	appleTree[N].next = 1;
	
	// calc drops
	if (firstNoDrop == 0) {
		dropGroup = N >= 3 ? N : 0;
		cout << allApples << " " << dropTrees << " " << dropGroup << endl;
	}
	else {
		int p = firstNoDrop + 1;
		int counts = 0;
		while (p != firstNoDrop) {
			if (appleTree[p].drop > 0) {
				++counts;
			}
			else {
				if (counts >= 3) {
					dropGroup += counts - 2;
				}
				counts = 0;
			}
			p = appleTree[p].next;
		}
		if (counts >= 3) {
			dropGroup += counts - 2;
		}
		cout << allApples << " " << dropTrees << " " << dropGroup << endl;
	}
	
	// fclose(stdin);
	return 0;
}
