#include<cstdio>
#include<cstring>

using namespace std;

int main() {
    char str1[100], str2[100];
    scanf("%s", str1);
    scanf("%s", str2);

    int str1len = strlen(str1);
    int str2len = strlen(str2);
    bool hashTable[256] = {false};
    for (int i = 0; i < str1len; ++i)  {
        int j;
        char c1 = str1[i];
        if (c1 >= 'a' && c1 <= 'z') c1 -= 32;
        if (hashTable[c1])  continue;
        char c2;
        for (j = 0; j < str2len; ++j)  {
            c2 = str2[j];
            if (c2 >= 'a' && c2 <= 'z') c2 -= 32;
            if (c1 == c2)   {
                hashTable[c1] = true;
                break;
            }
        }
        if (j == str2len) {
            hashTable[c1] = true;
            printf("%c", c1);
        }
    }

    return 0;
}
