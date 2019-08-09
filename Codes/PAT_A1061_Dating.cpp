#include<iostream>
#include<cstring>

char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
	char str1[64], str2[64];
	scanf("%s", str1);	scanf("%s", str2);
	int len1 = strlen(str1), len2 = strlen(str2), counter = 0;
	for (int i = 0; i < len1 && i < len2; ++i) {
		if (counter == 0 && str1[i] == str2[i] && str1[i] <= 'G' && str1[i] >= 'A') {
			printf("%s ", week[str1[i] - 'A']);
			++counter; 
		}
		else if (counter == 1 && str1[i] == str2[i]) {
			if (str1[i] <= 'N' && str1[i] >= 'A') {
				printf("%02d:", str1[i] - 'A' + 10);
				break;
			}
			else if (str1[i] <= '9' && str1[i] >= '0') {
				printf("%02d:", str1[i] - '0');
				break;
			}
		}
	}
	char str3[64], str4[64];
	scanf("%s", str3);	scanf("%s", str4);
	int len3 = strlen(str3), len4 = strlen(str4);
	for (int i = 0; i < len3 && i < len4; ++i) {
		if (str3[i] == str4[i] && ((str3[i] <= 'Z' && str3[i] >= 'A') || (str3[i] <= 'z' && str3[i] >= 'a'))) {
			printf("%02d", i);
			break;
		}
	}
	
	return 0;
}
