#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 100007;
const int INF = 0x3f3f3f3f;

int N, M;
struct Diamond {
	int value;
	int prevalue;
	Diamond() {
		value = 0; prevalue = 0;
	}
}dia[maxn];
struct Pay {
	int left, right;
};
vector<Pay> pay;

bool cmp(Pay a, Pay b) {return a.left < b.left;}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		int value;
		scanf("%d", &dia[i].value);
	}
	dia[1].prevalue = dia[1].value;
	for (int i = 2; i <= N; ++i) {dia[i].prevalue = dia[i - 1].prevalue + dia[i].value;}
	int p1, p2, diff;
	int minv = INF;
	for (p1 = 1, p2 = 1; p1 <= p2 && p2 <= N;) {
		diff = dia[p2].prevalue - dia[p1 - 1].prevalue;
		if (diff == M) {
			if (minv != M)	{
				pay.clear(); minv = M;
			}
			Pay p;
			p.left = p1; p.right = p2;
			pay.push_back(p);
			++p1; ++p2;
		}
		else if (diff < M) {++p2;}
		else {
			if (diff < minv) {
				pay.clear(); minv = diff;
				Pay p;
				p.left = p1; p.right = p2; pay.push_back(p);
			}
			else if (diff == minv) {
				Pay p;
				p.left = p1; p.right = p2; pay.push_back(p);
			}
			if (p1 == p2) ++p2;
			++p1;
		}
	}
	sort(pay.begin(), pay.end(), cmp);
	int counter = pay.size();
	for (int i = 0; i < counter; ++i) {
		printf("%d-%d\n", pay[i].left, pay[i].right);
	}

	return 0;
}
