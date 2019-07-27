#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int N, K, P, maxFacSum = -1;
vector<int> fac, ans, temp;

int power(int x) {
    int ans = 1;
    for (int i = 0; i < P; ++i) {
        ans *= x;
    }
    return ans;
}

void init() {           // 打表，制作幂表
    int i = 0, temp = 0;
    while(temp <= N)  {
        fac.push_back(temp);
        temp = power(++i);
    }
}

void DFS(int index, int nowK, int sum, int facSum) {
    if (sum == N && nowK == K) {
        if (facSum > maxFacSum) {
            ans = temp;
            maxFacSum = facSum;
        }
        return;
    }
    if (sum > N || nowK > K) return;
    if (index - 1 >= 0) {
        temp.push_back(index);
        DFS(index, nowK + 1, sum + fac[index], facSum + index);
        temp.pop_back();
        DFS(index - 1, nowK, sum, facSum);
    }
}

int main()
{
    scanf("%d%d%d", &N, &K, &P);
    init();
    DFS(fac.size() - 1, 0, 0, 0);
    if (maxFacSum == -1) printf("Impossible\n");
    else {
        printf("%d = %d^%d", N, ans[0], P);
        for (int i = 1; i < ans.size(); ++i) {
            printf(" + %d^%d", ans[i], P);
        }
    }

    return 0;
}
