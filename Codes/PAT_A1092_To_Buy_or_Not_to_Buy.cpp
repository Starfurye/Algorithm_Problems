#include<cstdio>
int hashTable[256] = {0};
int num = 0, counter1 = 0, counter2 = 0;
int main()
{
	char c = getchar();
	while (c != '\n') {
		++hashTable[c];
		++counter1;
		c = getchar();
	}
	c = getchar();
	while (c != '\n') {
		++counter2;
		if (hashTable[c] == 0) ++num;
		else --hashTable[c]; 
		c = getchar();
	}
	if (num == 0) printf("Yes %d\n", counter1 - counter2);
	else printf("No %d\n", num);
	
	return 0;
}
