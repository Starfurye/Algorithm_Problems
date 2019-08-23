#include<cstdio>
#include<iostream>
#include<set>
#include<string>

using namespace std;
int M, N, S;
set<string> lucky;

int main()
{
	scanf("%d%d%d", &M, &N, &S);
	string fl;
	if (M < S) {
		printf("Keep going...\n");
		return 0;
	}
	for (int i = 1; i < S; ++i) cin >> fl;
	int skip = 0;
	for (int i = S; i <= M; ++i) {
		cin >> fl;
		if (skip == 0) {
			if (lucky.find(fl) == lucky.end()) {
				lucky.insert(fl);
				cout << fl << endl;
				skip = N - 1;
			}
			else continue;
		}
		else --skip;
	}
	if (lucky.size() == 0) printf("Keep going...\n");
	
	return 0;
}
