#include<cstdio>

using namespace std;

int nums[10];

void print(int start, int ending) {
    for (int i = start; i <= ending; ++i) {
            int j;
            for (j = 1; j <= nums[i]; ++j) {
                printf("%d", i);
            }
        }
}

int main()
{

    for (int i = 0; i < 10; ++i) {
        scanf("%d", &nums[i]);
    }
    if (nums[0] == 0) {
        print(1, 9);
    }
    else {
        for (int i = 1; i < 10; ++i) {
            if (nums[i] != 0) {
                printf("%d", i);
                --nums[i];
                break;
            }
        }
        print(0, 9);
    }

    return 0;
}
