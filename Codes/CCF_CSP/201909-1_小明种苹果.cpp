#include<iostream>
#include<cstdio>
using namespace std;

int N, M;
int main()
{
	// freopen("in.txt", "r", stdin);
	
	int T = 0, K, P;
	int allApple = 0;
	int da = 0, dt = 1;				// delete among all
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int app = 0, del = 0;
		cin >> app;
		for (int j = 0; j < M; ++j) {
			int td = 0;
			cin >> td;
			del += td; 
		}
		if (del < da) {
			da = del; dt = i + 1;
		}
		allApple += app + del;
	}
	cout << allApple << " " << dt << " " << -da << endl;
	
	// fclose(stdin);
	
	return 0;
}
