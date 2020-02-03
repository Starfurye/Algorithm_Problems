#include<iostream>
#include<string>
#include<cstdio>
#include<map>
#include<vector>
#include<cctype>
using namespace std;
map<string, string> dict;
vector<string> templist;

string trim(string s) {
	if (s.empty()) return s;
	return s.substr(s.find_first_not_of('0'));	
}
bool ismatch(string const& rule, string& url) {
	vector<string> para;
	int ix = 0;
	int p = 0;
	while (1) {
		if (ix >= url.size()) {
			break;
		}
		if (rule[p] == url[ix]) {
			ix++, p++;
		}
		else if (rule[p] == '<') {
			++p;
			string s;	
			switch (rule[p]) {
				case 'p':
					cout << dict[rule];
					for (int i = 0; i < para.size(); ++i) {
						cout << " " << para[i];
					}
					cout << " " << url.substr(ix) << endl;
					return true;
				case 'i':
					while (ix < url.size() && isdigit(url[ix])) {
						s += url[ix];
						++ix;
					}
					para.push_back(trim(s));
					p += 4;
					break;
				case 's':
					while (ix < url.size() && (isdigit(url[ix]) || isalpha(url[ix]))) {
						s += url[ix];
						++ix;
					}
					para.push_back(s);
					p += 4;
					break;
				default:
					break;
			}
		}
		else {
			return false;
		}
	}
	if (p >= rule.size()) {
		cout << dict[rule];
		for (int i = 0; i < para.size(); ++i) {
			cout << " " << para[i];
		}
		cout << endl;
		return true;
	}
	return false;
}
void solve(string& url) {
	auto it = templist.begin();
	bool flag = false;
	for (; it != templist.end(); ++it) {
		if (ismatch(*it, url)) {
			flag = true;
			break;
		}
	}
	if (!flag) {
		cout << "404" << endl;
	}
}
int main()
{
	int m, n;
	cin >> m >> n;
	string rule, name;
	for (int i = 0; i < m; ++i) {
		cin >> rule >> name;
		templist.push_back(rule);
		dict[rule] = name;
	}
	string url;
	for (int i = 0; i < n; ++i) {
		cin >> url;
		solve(url);
	}
	
	return 0;
}
