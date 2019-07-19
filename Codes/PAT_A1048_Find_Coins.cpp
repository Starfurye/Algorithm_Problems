#include<cstdio>
#include<algorithm>
using namespace std;

int arr[100010];

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);

    int i = 0, j = N - 1;
    while (i < j) {
        if (arr[i] + arr[j] > M) --j;
        else if (arr[i] + arr[j] < M)   ++i;
        else {
            printf("%d %d\n", arr[i], arr[j]);
            break;
        }
    }
    if (i == j) printf("No Solution\n");

    return 0;
}
