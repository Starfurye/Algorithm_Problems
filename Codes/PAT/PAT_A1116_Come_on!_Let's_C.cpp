#include<cstdio>

const int maxn = 10005;
int rewards[maxn] = {0}; 
char re[5][20] = {"Are you kidding?", "Chocolate", "Minion", "Mystery Award", "Checked"};
int N, K;
	
const int maxp = 10005;
int pNum = 0;	
bool p[maxp] = {0};	
void Find_Prime() {
    for (int i = 2; i < maxp; ++i) {
        if (p[i] == false) {
            ++pNum;
            for (int j = i + i; j < maxp; j += i) {	
                p[j] = true;		
            }
        }
    }
}

int main()
{
	Find_Prime();
	scanf("%d", &N);
	int person;
	scanf("%d", &person);
	rewards[person] = 3;
	for (int i = 1; i < N; ++i) {
		scanf("%d", &person);
		rewards[person] = !p[i + 1] ? 2 : 1;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++i) {
		scanf("%d", &person);
		printf("%04d: %s\n", person, re[rewards[person]]);
		if (rewards[person]) {
			rewards[person] = 4;
		}
	}
	
	return 0;
}
