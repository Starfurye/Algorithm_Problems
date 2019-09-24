#include<iostream>
#include<string>
#include<cstdio>
#include<map>
using namespace std;
int n, m;
map<string, string> mp;
void parseWord(string& word) {
	for (int i = 0; i < word.size(); ++i) {
		if (word[i] == '\\') {
			word.erase(word.begin() + i);
		}
	}
}
void parseLine(string line, string father) {
	for (int i = 1; i < line.size(); ++i) {
		if (line[i] == '"') {
			int j = line.find(':', i + 1);
			string key = line.substr(i + 1, j - i - 2); parseWord(key);
			if (father != "") key = father + "." + key;
			if (line[j + 1] == '"') {
				i = j + 1; j = line.find(',', i + 1);
				if (j == string::npos) j = line.size() - 1;
				string value = line.substr(i + 1, j - i - 2); parseWord(value); i = j;
				mp[key] = value;
			}
			else if (line[j + 1] == '{') {
				int counts = 1, k;
				for (k = j + 2; k < line.size(); ++k) {
					if (line[k] == '{') ++counts;
					else if (line[k] == '}') --counts;
					if (counts == 0) break;
				}
				string next = line.substr(j + 1, k - j); i = k + 1;
				mp[key] = next;
				parseLine(next, key);
			}
		}
	}
}
int main()
{
// freopen("in.txt", "r", stdin);
	cin >> n >> m; getchar();
	string line, s;
	for (int i = 0; i < n; ++i) {  // erase all space
		getline(cin, s);
		for (string::iterator it = s.begin(); it != s.end();) {
			if (isspace(*it)) it = s.erase(it);
			else ++it;
		}
		line += s;
	}
	s.clear();
	int pt = 1;
	parseLine(line, s);
	for (int i = 0; i < m; ++i) {
		string query;
		getline(cin, query);
		if (mp.find(query) != mp.end()) {
			if (mp[query][0] == '{') {
				cout << "OBJECT" << endl;
			}
			else {
				cout << "STRING " << mp[query] << endl;
			}
		}
		else cout << "NOTEXIST" << endl;
	}
// fclose(stdin);
	return 0;
}
