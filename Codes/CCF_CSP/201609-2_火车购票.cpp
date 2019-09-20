#include<cstdio>
#include<algorithm>
using namespace std;
int n;
bool all[20][5] = {false};
int empty[20];
void select(int seats) {
	for (int i = 0; i < 20; ++i) {
		if (empty[i] >= seats) {
			int counts = 0;
			for (int j = 0; j < 5; ++j) {
				if (all[i][j] == false) { 
					++counts; all[i][j] = true; --empty[i]; printf("%d ", i * 5 + j + 1);
				}
				if (counts == seats) {
					printf("\n"); return;
				}
			}
		}		
	}
	for (int i = 0; i < 20; ++i) {
		int counts = 0;
		if (empty[i] > 0) {
			for (int j = 0; j < 5; ++j) {
				if (all[i][j] == false) {
					all[i][j] = true; --empty[i]; printf("%d ", i * 5 + j + 1);
				}
				if (counts == seats) {
					printf("\n"); return;
				}
			}
		}
	}
}
int main()
{
	fill(empty, empty + 20, 5);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int seats;
		scanf("%d", &seats);
		select(seats);
	}
	
	return 0;
}
