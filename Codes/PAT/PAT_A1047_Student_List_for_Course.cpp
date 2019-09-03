#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int N, K;
const int maxn = 40010;
const int maxc = 2510;
char name[maxn][5];
vector<int> course[maxc];

bool cmp(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}

int main()
{
    scanf("%d%d", &N, &K);
    int courseNum, courseID, j;

    for (int i = 0; i < N; ++i) {
        scanf("%s", &name[i]);
        scanf("%d", &courseNum);
        for (j = 0; j < courseNum; ++j) {
            scanf("%d", &courseID);
            course[courseID].push_back(i);
        }
    }

    for (int i = 1; i <= K; ++i) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);
        for(j = 0; j < course[i].size(); ++j) {
            printf("%s\n", name[course[i][j]]);
        }
    }

    return 0;
}
