#include<bits/stdc++.h>
using namespace std;
string parseE(string text) {
	string result;
    result += "<em>"; result += text; result += "</em>";
    return result;
}
string parseLink(string text, string link) {
    string result;
    result += "<a href=\"";
    result += link;
    result += "\">";
    result += text;
    result += "</a>";
    return result;
}
string parseLine(string line) {
	string result;
	int i = 0;
	while (i < line.size()) {
		if (line[i] == '[') {
			string text, link; int j = i + 1;
			while (line[j] != ']') ++j;
			text = line.substr(i + 1, j - i - 1);
			i = j + 1;
			while (line[j] != ')') ++j;
			link = line.substr(i + 1, j - i - 1);
			text = parseLine(text); link = parseLine(link);
			result += parseLink(text, link);
			i = j + 1;
		}
		else if (line[i] == '_') {
			string text; int j = i + 1;
			while (line[j] != '_') ++j;
			text = line.substr(i + 1, j - i - 1);
			text = parseLine(text);
			result += parseE(text);
			i = j + 1;
		}
		else {
			result += line[i++];
		}
	}
	return result;
}
string parseP(vector<string>& contents) {
	string result;
	result += "<p>";
	for (int i = 0; i < contents.size(); ++i) {
		result += parseLine(contents[i]);
		if (contents.size() != 0 && i != contents.size() - 1) result += '\n';
	}
	result += "</p>\n";
	return result;
}
string parseH(vector<string>& contents) {
	int level = 1, i = 0;
	string heading = parseLine(contents[0]);
	while (heading[i] == '#') ++i;
	level = i;
	while (heading[i] == ' ') ++i;
	string result;
	result += "<h"; result += to_string(level); result += ">";
	result += heading.substr(i,-1);
    result += "</h"; result += to_string(level); result += ">\n";
    return result;
}
string parseU(vector<string>& contents) {
	string result;
	result += "<ul>\n";
	int j;
	for (int i = 0; i < contents.size(); ++i) {
		result += "<li>"; j = 1;
		while (contents[i][j] == ' ') ++j;
		result += parseLine(contents[i].substr(j, -1));
		result += "</li>\n";
	}
	result += "</ul>\n";
	return result;
}
int main()
{
	ios::sync_with_stdio(false);
// freopen("in.txt", "r", stdin);
	string line;
	vector<string> contents;
	int blockType; // 0:empty, 1:paragraph, 2:heading, 3:unordered list
	string result;
	while (getline(cin, line) || contents.size() > 0) {
		if (line.empty()) {
			if (blockType) {
				switch(blockType) {
					case 1: result += parseP(contents); break;
					case 2: result += parseH(contents); break;
					case 3: result += parseU(contents); break;
				}
				contents.clear();
				blockType = 0;
			}
		}
		else if (line[0] == '#') {
			contents.push_back(line);
			blockType = 2;
		}
		else if (line[0] == '*') {
			contents.push_back(line);
			blockType = 3;
		}
		else {
			contents.push_back(line);
			blockType = 1;
		}
		line.clear();
	}
// fclose(stdin);	
	cout << result;
	return 0;
}
