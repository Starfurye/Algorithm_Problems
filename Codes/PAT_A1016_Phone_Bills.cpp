#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

const int maxn = 1005;

int hourbill[24];
string month;
map<string, int> nameToIndex;
struct Rec {
    string record;
    bool onoff;
};
struct Person {
	Rec records[500];
	int recnum;
} persons[maxn];

bool cmp(Rec a, Rec b){
    return a.record < b.record;
}

int calc(string a, string b) {
    char A[10], B[10];
    for(int i = 3; i < a.size(); ++i) {A[i - 3] = a[i];}
    for(int i = 3; i < b.size(); ++i) {B[i - 3] = b[i];}
    int d1, h1, m1, d2, h2, m2;
    sscanf(A, "%d:%d:%d", &d1, &h1, &m1);
    sscanf(B, "%d:%d:%d", &d2, &h2, &m2);
    int allmin = (d2 - d1) * 24 * 60 + (h2 - h1) * 60 + (m2 - m1);
    printf("%d ", allmin);

    int allbill = 0;
    if (d2 == d1 && h2 == h1) return (m2 - m1) * hourbill[h1];
    if (d2 == d1) {
        for (int i = h1 + 1; i <= h2; ++i) {
            int tempmin = 1 * 60 - m1;
            allbill += hourbill[h1] * tempmin;
            h1 = i; m1 = 0;
        }
        allbill += m2 * hourbill[h2];
    }
    else {
        for (int i = d1 + 1; i <= d2; ++i) {
            for (int j = h1 + 1; j <= 24; ++j) {
                int tempmin = 60 - m1;
                allbill += hourbill[h1] * tempmin;
                h1 = j; m1 = 0;
            }
            h1 = 0;
        }
        for (int i = h1 + 1; i <= h2; ++i) {
            int tempmin = 1 * 60 - m1;
            allbill += hourbill[h1] * tempmin;
            h1 = i; m1 = 0;
        }
        allbill += m2 * hourbill[h2];
    }
    return allbill;
}

int main()
{
	for (int i = 0; i < 24; ++ i) {
		scanf("%d", &hourbill[i]);
	}
	int records;
	scanf("%d", &records);
	int counter = 0;
	for (int i = 0; i < records; ++i) {
		string name, record, onoff;
		cin >> name >> record >> onoff;
		if (nameToIndex.find(name) == nameToIndex.end()) {
            nameToIndex[name] = counter;
            persons[counter].recnum = 0;
            ++counter;
		}
		int index = nameToIndex[name];
		persons[index].records[persons[index].recnum].onoff = onoff == "on-line" ? true : false;
		persons[index].records[persons[index].recnum++].record = record;
	}
	month = persons[0].records[0].record.substr(0, 2);
	for (map<string, int>::iterator it = nameToIndex.begin(); it != nameToIndex.end(); ++it) {
        int index = it->second;
        int recnum = persons[index].recnum;
        sort(persons[index].records, persons[index].records + recnum, cmp);
        int total = 0, tempbill;
		bool flag = false;
        for (int i = 0; i < recnum - 1;) {
            if (persons[index].records[i].onoff == true && persons[index].records[i + 1].onoff == false) {
				if (flag == false) {
					cout << it->first << " " << month << endl;
					flag = true;
				}
                cout << persons[index].records[i].record.substr(3, 8) << " " << persons[index].records[i + 1].record.substr(3, 8) << " ";
                tempbill = calc(persons[index].records[i].record, persons[index].records[i + 1].record);
                total += tempbill;
                printf("$%.2f\n", tempbill / 100.00);
				i += 2;
            }
            else ++i;
        }
		if (flag) {
			printf("Total amount: $%.2f\n", total / 100.00);
		}
	}

	return 0;
}
