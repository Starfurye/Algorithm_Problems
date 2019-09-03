#include<cstdio>
#include<map>
#include<string>
#include<iostream>

using namespace std;

const int maxn = 1048577;

map<string, int> words;

string str;

int main()
{
    getline(cin, str);
    string word;
    int i = 0;
    while (i < str.size()) {
        if (str[i] >= 'A' && str[i] <= 'Z')	str[i] += 32;
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <='z')) {
            word += str[i];
        }
        else {
            if (word.size() > 0) {
                ++words[word];
                word.clear();
            }
        }
        ++i;
    }
    if (word.size() > 0) {
        ++words[word];
        word.clear();
    }

    int maxword = 0;
    map<string, int>::iterator it;
    for (it = words.begin(); it != words.end(); ++it) {
        if (it->second > maxword) {
            maxword = it->second;
            word = it->first;
        }
    }
    cout << word << " " << maxword << endl;

    return 0;
}
