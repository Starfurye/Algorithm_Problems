#include<cstdio>
#include<string>
#include<iostream>

using namespace std;
int N;
string a, b;

int main()
{
	cin >> a;
	scanf("%d", &N);
	for (int i = 1; i < N; ++i) {
		int j;
		for (j = 0; j < a.size();) {
			char c = a[j]; int num = 1, k;
			for (k = j + 1; k < a.size(); ++k) {
				if (a[k] == c) {
					++num;
				}
				else break;
			}
			j += num;
			b += c; b += to_string(num); 
		}
		a = b;
		b.clear();
	}
	cout << a;
	
	return 0;
}
