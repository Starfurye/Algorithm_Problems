#include<cstdio>
#include<cstring>

int main() {
    char str[100010];

    scanf("%s", str);
    int len = strlen(str);
    int leftP[100010] = {0};
    for (int i = 0; i < len - 1; ++i)   {
        leftP[i + 1] = leftP[i];
        if (str[i] == 'P')  ++leftP[i + 1];
    }

    int counter = 0;
    int rightT = 0;
    for (int i = len - 1; i > 0; --i)   {
        if (str[i] == 'T')  ++rightT;
        else if (str[i] == 'A') counter += leftP[i] * rightT;
        counter %= 1000000007;
    }

    printf("%d\n", counter);

    return 0;
}
