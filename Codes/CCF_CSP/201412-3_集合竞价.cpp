#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 5005;
const int INF = 0x3f3f3f3f;
struct Info {
	double price;
	long long num;
	int type;
	int cancel;
}buy[maxn], sell[maxn], record[maxn];
bool cmp1(Info a, Info b) {return a.price > b.price;}
bool cmp2(Info a, Info b) {return a.price < b.price;}
long long pbuy[maxn], psell[maxn];
int main()
{
	int cnt = 0; char str[10]; double a; int b;
	while (scanf("%s", str) != EOF) {
		if (strcmp(str, "buy") == 0) {
			scanf("%lf %lld", &record[cnt].price, &record[cnt].num);
			record[cnt].type = 1; record[cnt].cancel = 0; ++cnt;
		}
		else if (strcmp(str, "sell") == 0) {
			scanf("%lf %lld",&record[cnt].price,&record[cnt].num);
            record[cnt].type = 0; record[cnt].cancel = 0; ++cnt;
		}
		else if (strcmp(str, "cancel") == 0) {
			int id; scanf("%d", &id);
			record[id - 1].cancel = 1; record[cnt].cancel = 1; ++cnt;
		}
	}
	int cnta = 1, cntb = 1;
	for (int i = 0; i < cnt; ++i) {
		if (record[i].type == 1 && record[i].cancel == 0) {
			buy[cnta++] = record[i];
		}
		if (record[i].type == 0 && record[i].cancel == 0) {
			sell[cntb++] = record[i];
		}
	}
	sort(buy + 1, buy + cnta, cmp1); sort(sell + 1, sell + cntb, cmp2); sort(record, record + cnt, cmp1);
	pbuy[0] = 0; psell[0] = 0; pbuy[1] = buy[1].num; psell[1] = sell[1].num;
	for (int i = 2; i < cnta || i < cntb; ++i) {
		if (i < cnta) pbuy[i] = pbuy[i - 1] + buy[i].num;
		if (i < cntb) psell[i] = psell[i - 1] + sell[i].num;
	}
	double ansp = 0;
    long long ansn = 0;
    int k = 1, j;
    for (int i = 0; i < cnt; ++i) {
    	if (record[i].cancel == 1) continue;
    	for (; k < cnta; ++k) {
    		if (buy[k].price < record[i].price) break;
		}
		for (j = 1; j < cntb; ++j) {
			if (sell[j].price > record[i].price) break;
		}
		long long res = min(psell[j - 1], pbuy[k - 1]);
		if (res > ansn) {
			ansn = res; ansp = record[i].price;
		}
		else if (res == ansn) {
			ansp = max(record[i].price, ansp);
		}
	}
	printf("%.2f %lld\n", ansp, ansn);
	
	return 0;
}
