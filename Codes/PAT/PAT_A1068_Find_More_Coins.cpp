#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 10010;
const int maxv = 107;

int N, M;
int w[maxn], dp[maxv] = {0};
bool choice[maxn][maxv], flag[maxn] = {false};
bool cmp(int a, int b) {return a > b;}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &w[i]);
    }
    sort(w + 1, w + N + 1, cmp);
    for (int i = 1; i <= N; ++i) {
        for (int v = M; v >= w[i]; --v) {
            if (dp[v] <= dp[v - w[i]] + w[i]) {
                dp[v] = dp[v - w[i]] + w[i];
                choice[i][v] = 1;
            }
            else choice[i][v] = 0;
        }
    }
    if (dp[M] != M) printf("No Solution");
    else {
        int k = N, num = 0, v = M;
        while (k >= 0) {
            if (choice[k][v] == 1) {
                flag[k] = true;
                v -= w[k];
                ++num;
            }
            else flag[k] = false;
            --k;
        }
        for (int i = N; i >= 1; --i) {
            if (flag[i]) {
                printf("%d", w[i]);
                --num;
                if (num > 0)    printf(" ");
            }
        }
    }


    return 0;
}
