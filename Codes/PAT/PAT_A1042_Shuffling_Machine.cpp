#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int K;
int place[54];
string cards[54] = {"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", "J1", "J2"};
string tcards[54];

int main()
{
	scanf("%d", &K);
	for (int i = 0; i < 54; ++i) {
		scanf("%d", &place[i]);
	}
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < 54; ++j) {
			tcards[place[j] - 1] = cards[j];
		}
		for (int j = 0; j < 54; ++j) { cards[j] = tcards[j]; }
	}
	for (int i = 0; i < 54; ++i) {
		cout << cards[i];
		if (i < 53)	printf(" ");
	}
		
	return 0;
}
