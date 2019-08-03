#include<iostream>
#include<string>

using namespace std;

string numstr;
int nums[1000];
string words[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main()
{
	cin >> numstr;
	int result = 0;
	for (int i = 0; i < numstr.size(); ++i) {
		result += numstr[i] - '0';
	}
	if (result == 0) {
		cout << "zero";
		return 0;
	}
	int p = 0;
	while (result != 0) {
		nums[p++] = result % 10;
		result /= 10;
	}
	for (int j = p - 1; j >= 0; --j) {
		cout << words[nums[j]];
		if (j > 0) cout <<" ";
	}
	
	return 0;
}
