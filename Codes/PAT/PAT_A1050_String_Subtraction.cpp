#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

string str1;
bool asc[256];

int main()
{
	fill(asc, asc + 256, true);
	getline(cin, str1);
	char c = getchar();
	while (c != '\n') {
		asc[c] = false;
		c = getchar();
	}
	int len = str1.size();
	for (int i = 0; i < len; ++i) {
		if (asc[str1[i]]) printf("%c", str1[i]);
	}
	
	return 0;
}
