#include<cstdio>
#include<vector>
using namespace std;
int heap[1010];
vector<int> tempPath;
int m;
int cnt; 
int flag1 = 0;
int flag2 = 0;
void printleafpath(int n) {
	if (n > m)	return;
	if (2 * n > m) { 
		tempPath.push_back(heap[n]);  
		for (int i = 0; i < tempPath.size(); i++) {
			printf("%d", tempPath[i]);
			if (i < tempPath.size() - 1) printf(" ");
		}
		for (int i = 0; i < tempPath.size(); i++) {      
			for (int j = i + 1; j < tempPath.size(); j++) {
				if (tempPath[i] < tempPath[j]) flag1 = 1;
				if (tempPath[i] > tempPath[j]) flag2 = 1;
			}
		}
		cnt--;
		if (cnt > 0)
			printf("\n");  
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(heap[n]);
	printleafpath(2 * n + 1);
	printleafpath(2 * n);
	tempPath.pop_back();
}
int main() {
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &heap[i]);
	}
	cnt = m - m / 2; 
	printleafpath(1);
	printf("\n");
	if (flag1 == 1 && flag2 == 1) { 
		printf("Not Heap");
	}
	else if (flag2 == 1) {
		printf("Max Heap");
	}
	else if (flag1 == 1) {
		printf("Min Heap");
	}
	return 0;
}
