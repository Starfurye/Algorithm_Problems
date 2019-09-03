#include<iostream>
#include<string>

using namespace std;

string signin, signout, intime, outime;

int main()
{
	int num;
	string person, in, out;
	cin >> num;
	cin >> person >> in >> out;
	signin = person;	signout = person;
	intime = in;	outime = out;
	for (int i = 1; i < num; ++i) {
		cin >> person >> in >> out;
		if (in < intime) {
			intime = in;
			signin = person;
		}
		if (out > outime) {
			outime = out;
			signout = person;
		}
	}
	cout << signin << " " << signout;
	
	return 0;
}
