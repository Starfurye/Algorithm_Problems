#include<cstdio>
#include<unordered_map>
#include<string>
#include<iostream>

using namespace std;

int N;
string digit1[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string digit2[12] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
unordered_map<string, int> marsToEarth;
unordered_map<int, string> earthToMars;

void init() {
	marsToEarth["tret"] = 0;
	earthToMars[0] = "tret";
	for (int i = 0; i < 12; ++i) {
		marsToEarth[digit1[i]] = i + 1;
		earthToMars[i + 1] = digit1[i];
	}
	for (int i = 0; i < 12; ++i) {
		marsToEarth[digit2[i]] = i + 13;
		earthToMars[i + 13] = digit2[i];
	}
}

int main()
{
	init();
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; ++i) {
		string str;
		getline(cin, str);
		if (str[0] <= '9') {
			int num;
			sscanf(str.c_str(), "%d", &num);
			if (num % 13 == 0 && num > 0) {
				cout << earthToMars[num / 13 + 12] << endl;
				continue;
			}
			if (num > 13) {
				cout << earthToMars[num / 13 + 12] << " ";
			}
			cout << earthToMars[num % 13] << endl;
		}
		else {
			if (str.size() > 4) {
				int num = 0;
				num += 13 * (marsToEarth[str.substr(0, 3)] - 12); 
				num += marsToEarth[str.substr(4, 3)];
				printf("%d\n", num);
			}
			else {
				int num = marsToEarth[str];
				if (num > 12) {
					num = 13 * (num - 12);
				}
				printf("%d\n", num);
			}
		}
	}
	
	return 0;
}
