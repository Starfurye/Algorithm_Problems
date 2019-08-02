#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 10010;
int arr[maxn];
int dp[maxn];
int K;

int main()
{
    scanf("%d", &K);
    bool flag = false;
    for (int i = 0; i < K; ++i) {
        scanf("%d", &arr[i]);
        if (arr[i] >= 0)    flag = true;
    }
    if (flag == false) {
        printf("0 %d %d\n", arr[0], arr[K - 1]);
        return 0;
    }
    dp[0] = arr[0];
    int maxdp = dp[0];  int right = 0;
    for (int i = 1; i < K; ++i) {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        if (dp[i] > maxdp) {
            maxdp = dp[i]; right = i;
        }
    }
    int left = right;
    for (int i = right; i > 0; --i) {
        if (dp[i - 1] + arr[i] == dp[i]) {
            left = i - 1;
        }
        else break;
    }
    printf("%d %d %d\n", maxdp, arr[left], arr[right]);

    return 0;
}
