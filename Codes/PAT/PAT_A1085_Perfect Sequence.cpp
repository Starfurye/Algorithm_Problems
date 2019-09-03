#include<cstdio>
#include<algorithm>

using namespace std;

long long arr[100010];
int N;
long long p;

int bin_search(int i, long long x) {
    if (arr[N - 1] < x) return N;       // low = i
    int low, high, mid;
    for (low = i + 1, high = N - 1; low < high;) {
        mid = (low + high) / 2;
        if (arr[mid] <= x)   low = mid + 1;             // maxlen > mid - low
        else high = mid;         // maxlen <= mid - low
    }
    return low;
}

int main()
{
    scanf("%d%lld", &N, &p);
    for(int i = 0; i < N; ++i)  scanf("%lld", &arr[i]);
    sort(arr, arr + N);

    int j, right, maxlen = 1;
    for (j = 0; j < N; ++j) {
        if (maxlen > N - j) break;
        right = bin_search(j, (long long)arr[j] * p);
        if (right - j > maxlen)  maxlen = right - j;
    }
    printf("%d\n", maxlen);

    return 0;
}
