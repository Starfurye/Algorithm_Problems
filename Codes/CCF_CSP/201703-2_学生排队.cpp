#include<iostream>
#include<map>
#include<vector>
using namespace std;
int n, m;
map<int, int> id2idx;
int stu[1010];
void movepre(int idx, int pace) {
	int temp = stu[idx];
	for (int i = idx; i > idx - pace; --i) {
		++id2idx[stu[i - 1]];
		stu[i] = stu[i - 1]; 
	}
	stu[idx - pace] = temp; id2idx[temp] = idx - pace;
}
void moveback(int idx, int pace) {
	int temp = stu[idx];
	for (int i = idx; i < idx + pace; ++i) {
		--id2idx[stu[i + 1]];
		stu[i] = stu[i + 1]; 
	}
	stu[idx + pace] = temp; id2idx[temp] = idx + pace;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		stu[i] = i; id2idx[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		int id, op;
		cin >> id >> op;
		if (op > 0) {
			moveback(id2idx[id], op);
		}
		else {
			movepre(id2idx[id], -op);
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << stu[i] << " ";
	}
	
	return 0;
}
