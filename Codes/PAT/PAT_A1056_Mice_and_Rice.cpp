#include<cstdio>
#include<queue>

using namespace std;

int NP, NG;

struct Mouse {
    int weight;
    int ranking;
}mice[1002];

int main()
{
    scanf("%d%d", &NP, &NG);
    for (int i = 0; i < NP; ++i) {
        scanf("%d", &mice[i].weight);
    }
    int order;
    queue<int> q;
    for (int i = 0; i < NP; ++i) {
        scanf("%d", &order);
        q.push(order);
    }

    int temp = NP, group;
    while (q.size() != 1) {
        if (temp % NG == 0) group = temp / NG;
        else group = temp / NG + 1;
        for (int i = 0; i < group; ++i) {
            int k = q.front();
            for (int j = 0; j < NG; ++j) {
                if (i * NG + j >= temp) break;
                int front = q.front();
                if (mice[front].weight > mice[k].weight) {
                    k = front;
                }
                mice[front].ranking = group + 1;
                q.pop();
            }
            q.push(k);
        }
        temp = group;
    }
    mice[q.front()].ranking = 1;

    for (int i = 0; i < NP; ++i) {
        printf("%d", mice[i].ranking);
        if (i < NP -1)  printf(" ");
    }

    return 0;
}
