#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
map<char, int>type;
map<char, string>para;
string s, s1, s2;
int N; 
int main() {
    cin >> s; 
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] != ':' && s[i + 1] == ':') {
            type[s[i]] = 1;				// para
        }
        else if (s[i] != ':')
            type[s[i]] = 2;
    }
    if (s[s.length() - 1] != ':') type[s[s.length() - 1]] = 2;
    scanf("%d", &N); getchar();
    bool flag;
    for (int i = 1; i <= N; i++) {
        getline(cin, s);
        flag = 0;
        para.clear();
        int p1, p2;
        while ((p1 = s.find(' ')) != -1) {
            s[p1] = 0;			// p1 - left bound
            p2 = s.find(' ');	// p2 - right bound
            if (p2 == -1) p2 = s.length();
            s2 = s.substr(p1 + 1, p2 - p1 - 1); // get command/para, '-' included(if exist)
            if (!flag) {						// flag is false, s2: command
                if (s2[0] != '-' || !type[s2[1]]) // not command / unknown command
                    break;
                if (type[s2[1]] == 2) {			// no para
                    para[s2[1]] = "*";
                }
                else {							// s1: command
                    s1 = s2;
                    flag = 1;
                }
            }
            else {								// flag is true, s2: para
                para[s1[1]] = s2;
                flag = 0;
            }
        }
        printf("Case %d:", i);
        for (auto it : para) {
            printf(" -%c", it.first);
            if (it.second[0] != '*') {
            	printf(" "); cout << it.second;
			}
        }
        printf("\n");
    }
    
    return 0;
}
