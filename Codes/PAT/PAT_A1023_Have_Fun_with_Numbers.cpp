#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int number[25], number2[25];
int p = 0;

void doubling() {
	bool flag = false;
	for (int i = p - 1; i >= 0; --i) {
		int temp = flag == true ? 1 : 0;
		temp += number[i] * 2;
		flag = temp >= 10 ? true : false;
		temp %= 10;	number2[p - 1 - i] = temp;
	}
	number2[p] = flag == true ? 1 : 0;
}
void print() {
	if (number2[p] == 1) printf("1");
	for (int i = p - 1; i >= 0; --i) {
		printf("%d", number2[i]);
	}
}
bool judge() {
	if (number2[p] == 1)	return false;
	else {
		int p1, p2;
		bool check[25] = { false };
		for (p1 = 0; p1 < p; ++p1) {
			for (p2 = 0; p2 < p; ++p2) {
				if (number[p1] == number2[p2] && check[p2] == false) {
					check[p2] = true;
					break;
				}
			}
			if (p2 == p) {return false;}
		}
		return true;
	}	
}

int main()
{
	char c[25];
	memset(number, 0, sizeof(number));
	memset(number, 0, sizeof(number2));
	scanf("%s", c);
	int len = strlen(c);
	for (int i = 0; i < len; ++i)
	{
		number[p++] = c[i] - '0';
	}
	doubling();
	if (judge()) {
		printf("Yes\n");
	}
	else printf("No\n");
	print();
	
	return 0;
}
