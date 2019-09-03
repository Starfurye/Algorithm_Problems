#include<map>
#include<string>
#include<set>
#include<cstdio>
#include<iostream>

using namespace std;

map<string, set<int> > mpTitle, mpAuthor, mpKey, mpPub, mpYear;
int N;

void query(map<string, set<int> >& mp, string& s) {
	if (mp.find(s) == mp.end()) {
		printf("Not Found\n");
	}
    else {
        for (set<int>::iterator it = mp[s].begin(); it != mp[s].end(); ++it) {
            printf("%07d\n", *it);
        }
    }
}

int main()
{
    int id;
    string title, author, key, publisher, year;
    char c;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> id;
        c = getchar();      // receive '\n'
        getline(cin, title);
        mpTitle[title].insert(id);
        getline(cin, author);
        mpAuthor[author].insert(id);
        while(cin >> key) {
            mpKey[key].insert(id);
            c = getchar();
            if (c == '\n')  break;
        }
        getline(cin, publisher);
        mpPub[publisher].insert(id);
        getline(cin, year);
        mpYear[year].insert(id);
    }

    int M;
    cin >> M;
    int type;
    for(int i = 1; i <= M; ++i) {
        cin >> type >> c;
		c = getchar();
		cout << type << ": ";
        switch (type) {
            case 1: {
                getline(cin, title);
                cout << title << endl;
                query(mpTitle, title);
                break;
            }
            case 2: {
                getline(cin, author);
                cout << author << endl;
                query(mpAuthor, author);
                break;
            }
            case 3: {
                getline(cin, key);
                cout << key << endl;
                query(mpKey, key);
                break;
            }
            case 4: {
                getline(cin, publisher);
                cout << publisher << endl;
                query(mpPub, publisher);
                break;
            }
            case 5: {
                getline(cin, year);
                cout << year << endl;
                query(mpYear, year);
                break;
            }
            default: break;
        }
    }

    return 0;
}
