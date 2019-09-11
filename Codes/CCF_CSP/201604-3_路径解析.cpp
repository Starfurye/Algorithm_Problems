#include<vector>
#include<iostream>
#include<sstream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	string path, s, str;
	cin >> path;
	getchar();
	for (int i = 0; i < n; ++i) {
		getline(cin, str);
		if (str.size() == 0) str = path;
		if (str[0] != '/') str = path + '/' + str;
		for (int j = 0; j < str.size(); ++j) {
			if (str[j] == '/') str[j] = ' ';		// change '/' to space
		}
		vector<string> sta;
		stringstream ss(str);
		while (ss >> s) {
			if (s == ".") continue;
			else if (s == ".." && !sta.empty()) sta.pop_back();
			else if (s != "..") sta.push_back(s);
		}
		printf("/");
		for (int j = 0; j < sta.size(); ++j) {
			if (j) printf("/");
			cout << sta[j];
		}
		printf("\n");
	}	
	
	return 0;
} 
