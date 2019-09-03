#include<cstdio>
#include<unordered_map>
#include<set>

const int maxs = 10005;
using namespace std;
unordered_map<int, int> F2M, M2F;
int N, M;
set<int> single;
int hashtable[100000] = {0};

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int f, m;
		scanf("%d%d", &f, &m);
		F2M[f] = m; M2F[m] = f;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		int member, other;
		scanf("%d", &member);
		if (F2M.find(member) != F2M.end()) {
			other = F2M[member];
		}
		else if (M2F.find(member) != M2F.end()) {
			other = M2F[member];
		}
		else {
			single.insert(member);
			continue;
		}
		if (hashtable[other] == 0) {
			hashtable[member] = 1;
			single.insert(member);
		}
		else {
			hashtable[other] = 0;
			single.erase(single.find(other));
		}
	}
	int arr[maxs];
	int pt = 0;
	for (set<int>::iterator it = single.begin(); it != single.end(); ++it) {
		arr[pt++] = *it;
	}
	printf("%d\n", pt);
	for (int i = 0; i < pt; ++i) {
		printf("%05d", arr[i]);
		if (i < pt - 1) printf(" ");
	}
	
	return 0;
}
