#include<unordered_map>
#include<algorithm>
#include<string>
#include<cstdio>
#include<iostream>
using namespace std;
unordered_map<string, string> varDict;
int main()
{
	int lineNum, varNum;
	scanf("%d%d", &lineNum, &varNum);
	string inputStr, outputStr, temp;
	getchar();
	for (int i = 0; i < lineNum; ++i) {
		getline(cin, temp); inputStr += temp + '\n';
	}
	
	string varKey, varValue;
	for (int i = 0; i < varNum; ++i) {
		cin >> varKey;
		getline(cin, temp);
		int startQuote = temp.find("\""), endQuote = temp.rfind("\"");
		varValue = temp.substr(startQuote + 1, endQuote - startQuote - 1);
		varDict[varKey] = varValue;
	}
	int startPos, endPos, startPoint = 0;
	while(true) {
		startPos = inputStr.find("{{", startPoint);
		endPos = inputStr.find("}}", startPos);
		if (startPos < 0 || endPos < 0) break;
		varKey = inputStr.substr(startPos + 3, endPos - startPos - 4); varValue.clear();
		if (varDict.find(varKey) != varDict.end()) varValue = varDict[varKey];
		outputStr += inputStr.substr(startPoint, startPos - startPoint) + varValue;
		startPoint = endPos + 2;
	}
	outputStr += inputStr.substr(startPoint, inputStr.size());
	cout << outputStr;
	
	return 0;
}
