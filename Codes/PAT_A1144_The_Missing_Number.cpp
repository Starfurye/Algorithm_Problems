#include<cstdio>
#include<set>

using namespace std;
int N;
set<int> st;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int num;
		scanf("%d", &num);
		if (num > 0) st.insert(num);
	}
	int k = 1;
	bool flag = true;
	for (set<int>::iterator it = st.begin(); it != st.end(); ++it) {
		if (k != *it) {
			printf("%d\n", k);
			flag = false;
			break;
		}
		++k;
	}
	if (flag) printf("%d\n", k);
	
	return 0;
}
