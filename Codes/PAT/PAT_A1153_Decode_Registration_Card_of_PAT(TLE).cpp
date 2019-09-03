#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>

using namespace std;
const int maxn = 10002;
int N, M;
struct type2 {
	int total;
	int num;
};
map<string, type2> sitenum;
struct type3 {
	string site;
	int num;
}dates[maxn];
struct Stu {
	string card, site, date, number;
	char type;
	int score;	
}stu[maxn];
int pt3;
bool cmp1(Stu &a, Stu &b) {
	if (a.score == b.score) {
		return a.card < b.card;
	}
	return a.score > b.score;
}
bool cmp3(type3 &a, type3 &b) {
	if (a.num == b.num) {
		return a.site < b.site;
	}
	return a.num > b.num;
}

int main()
{
	int T = 0, A = 0, B = 0;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		cin >> stu[i].card; scanf("%d", &stu[i].score);
		stu[i].type = stu[i].card[0]; 
		if (stu[i].type == 'T') ++T;
		else if (stu[i].type == 'A') ++A;
		else ++B;
		stu[i].site = stu[i].card.substr(1, 3); 
		if (sitenum.find(stu[i].site) == sitenum.end()) {
			sitenum[stu[i].site].num = 1; sitenum[stu[i].site].total = stu[i].score; 
		}
		else {
			++sitenum[stu[i].site].num; sitenum[stu[i].site].total += stu[i].score;
		}
		stu[i].date = stu[i].card.substr(4, 6); stu[i].number = stu[i].card.substr(10, 3);
	}
	sort(stu, stu + N, cmp1);
	for (int i = 0; i < M; ++i) {
		int Type;
		scanf("%d ", &Type);
		if (Type == 1) {
			char term; scanf("%c", &term); getchar();
			int counter = 0, comp;
			printf("Case %d: 1 ", i + 1); printf("%c\n", term);
			if (term == 'T') comp = T;
			else if (term == 'A') comp = A;
			else comp = B;
			if (comp == 0) printf("NA\n");
			else {
				for (int j = 0; j < N; ++j) {
					if (stu[j].type == term) {
						++counter;
						printf("%s %d\n", stu[j].card.c_str(), stu[j].score);
					}
					if (counter == comp) break;
				}
			}
		}
		else if (Type == 2) {
			string site; cin >> site;
			printf("Case %d: 2 ", i + 1); printf("%s\n", site.c_str());
			if (sitenum.find(site) == sitenum.end()) printf("NA\n");
			else printf("%d %d\n", sitenum[site].num, sitenum[site].total); 
		}
		else {
			pt3 = 0;
			char date[7]; scanf("%s", date);
			map<string, int> m;
			for (int j = 0; j < N; ++j) {
				if (strcmp(stu[j].date.c_str(), date) == 0) {
					if (m.find(stu[j].site) == m.end()) {
						m[stu[j].site] = 1; 
					}
					else ++m[stu[j].site];
				}
			}
			for (auto j : m) {
				dates[pt3].site = j.first; dates[pt3++].num = j.second;
			}
			printf("Case %d: 3 ", i + 1); printf("%s\n", date);
			if (pt3 == 0) printf("NA\n");
			else {
				sort(dates, dates + pt3, cmp3);
				for (int j = 0; j < pt3; ++j) {
					printf("%s %d\n", dates[j].site.c_str(), dates[j].num);
				}	
			}
		}
	}
	
	return 0;
}
