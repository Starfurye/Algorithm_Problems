#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

map<int, int> mp;
int M, N, counter = 0;

int main()
{
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			++counter;
			int pixel;
			scanf("%d", &pixel);
			if (mp.find(pixel) == mp.end())	mp[pixel] = 1;
			else ++mp[pixel];
		}
	}
	int p, maxc = 0;
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
		if (it->second > maxc) {
			p = it->first;	maxc = it->second;	
		}
	}
	printf("%d", p);
	
	return 0;
}
