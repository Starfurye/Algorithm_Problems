#include<cstdio>
#include<unordered_map>
#include<set>

using namespace std;
int M, N; 
const int maxn = 12000;
unordered_map<int, int> inidx, idxin, preidx, idxpre;
int v1, v2, LCA;
void preOrder(int inL, int inR, int preL, int preR) {
	if (preL > preR || inL > inR) return;
	int rootidx = inidx[idxpre[preL]];
	if (rootidx <= inidx[v1] && rootidx >= inidx[v2] || rootidx >= inidx[v1] && rootidx <= inidx[v2]) {
		LCA = idxpre[preL];
		return;
	}
	else if (rootidx <= inidx[v1] && rootidx <= inidx[v2]) {
		preOrder(rootidx + 1, inR, preL + rootidx - inL + 1, preR);
	}
	else if (rootidx >= inidx[v1] && rootidx >= inidx[v2]) {
		preOrder(inL, rootidx - 1, preL + 1, preL + rootidx - inL);
	}
}

int main()
{
	set<int> st;
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; ++i) {
		int v;
		scanf("%d", &v);
		inidx[v] = i; idxin[i] = v;
	}
	for (int i = 0; i < N; ++i) {
		int v;
		scanf("%d", &v);
		st.insert(v);
		preidx[v] = i; idxpre[i] = v;
	}
	for (int i = 0; i < M; ++i) {
		scanf("%d%d", &v1, &v2);
		bool flag1 = true, flag2 = true;
		if (st.find(v1) == st.end()) flag1 = false;
		if (st.find(v2) == st.end()) flag2 = false;
		if (!flag1 && !flag2) printf("ERROR: %d and %d are not found.\n", v1, v2);
		else if (flag1 && !flag2) printf("ERROR: %d is not found.\n", v2);
		else if (!flag1 && flag2) printf("ERROR: %d is not found.\n", v1);
		else {
			if (v1 == v2) printf("%d is an ancestor of %d.\n", v1, v2);
			else {
				preOrder(0, N - 1, 0, N - 1);
				if (LCA != v1 && LCA != v2) {
					printf("LCA of %d and %d is %d.\n", v1, v2, LCA);
				}
				else if (LCA == v1 && LCA != v2) {
					printf("%d is an ancestor of %d.\n", v1, v2);
				}
				else if (LCA != v1 && LCA == v2) {
					printf("%d is an ancestor of %d.\n", v2, v1);
				}
			}
		}
	}
	
	return 0;
}
