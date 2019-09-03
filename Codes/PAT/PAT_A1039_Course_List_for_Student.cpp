#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N, K;

const int M = 26 * 26 * 26 * 10 + 1;
vector<int> seleCourse[M];

int hashFunc(char S[], int len) {
    int id = 0;
    for (int i = 0; i < len - 1; ++i) {
        id = id * 26 + (S[i] - 'A');
    }
    id = id * 10 + (S[len - 1] - '0');
    return id;
}

int main()
{
    scanf("%d%d", &N, &K);
    int i, j;
    char person[5];
    int id;
    for (i = 1; i <= K; ++i) {
        int course, x;
        scanf("%d%d", &course, &x);
        for (j = 1; j <= x; ++j) {
            scanf("%s", person);
            id = hashFunc(person, 4);
            seleCourse[id].push_back(course);
        }
    }

    for (int i = 0; i < N; ++i) {
        scanf("%s", person);
        id = hashFunc(person, 4);
        sort(seleCourse[id].begin(), seleCourse[id].end());
        printf("%s %d", person, seleCourse[id].size());
        int k;
        for (k = 0; k < seleCourse[id].size(); ++k) {
            printf(" %d", seleCourse[id][k]);
        }
        printf("\n");
    }

    return 0;
}
