#include<cstdio>
#include<algorithm>

using namespace std;

struct Mooncake {
    double stock;
    double sell;
    double price;
}cake[1010];

bool cmp(Mooncake a, Mooncake b) {
    return a.price > b.price;
}

int main()
{
    int cakeNum;
    double demand;

    scanf("%d%lf", &cakeNum, &demand);
    for (int i = 0; i < cakeNum; ++i) {
        scanf("%lf", &cake[i].stock);
    }
    for (int i = 0; i < cakeNum; ++i) {
        scanf("%lf", &cake[i].sell);
        cake[i].price = cake[i].sell / cake[i].stock;
    }
    sort(cake, cake + cakeNum, cmp);

    double result = 0;
    int j;
    for (j = 0; j < cakeNum; ++j) {
        if (demand > cake[j].stock) {
            demand -= cake[j].stock;
            result += cake[j].sell;
        }
        else break;
    }
    result += demand * cake[j].price;
    printf("%.2lf\n", result);

    return 0;
}
