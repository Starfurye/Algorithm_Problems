#include<cstdio>
#include<set>

using namespace std;

int N, M;
set<int> sets[50];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &M);
        int elem;
        for (int j = 0; j < M; ++j) {
            scanf("%d", &elem);
            sets[i].insert(elem);
        }
    }

    int setn, set1, set2;
    scanf("%d", &setn);
    for (int i = 1; i <= setn; ++i) {
        scanf("%d%d", &set1, &set2);
        int same = 0, all = sets[set2 - 1].size();
        for (set<int>::iterator it = sets[set1 - 1].begin(); it != sets[set1 - 1].end(); ++it) {
            if (sets[set2 - 1].find(*it) == sets[set2 - 1].end()) {
                // no find in set2
                ++all;
            }
            else ++same;
        }
        double result = (double)same / all;
        printf("%.1lf%%\n", result * 100);
    }

    return 0;
}
