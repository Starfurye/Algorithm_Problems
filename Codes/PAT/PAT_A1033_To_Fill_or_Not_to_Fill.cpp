#include<cstdio>
#include<algorithm>

const int INF = 0x7fffffff;

using namespace std;

struct GasStation {
    double price;
    double dis;
}gasta[502];

double curGas = 0;
double curDest = 0;
double allCost = 0;

bool cmp(GasStation a, GasStation b) {
    return a.dis < b.dis;
}

int main()
{
    double tankCap, cityDis, avgD;
    int gastaNum;
    scanf("%lf%lf%lf%d", &tankCap, &cityDis, &avgD, &gastaNum);
    for (int i = 0; i < gastaNum; ++i) {
        scanf("%lf%lf", &gasta[i].price, &gasta[i].dis);
    }
    // treat the destination city as the last gas station that price is the lowest(0)
    gasta[gastaNum].dis = cityDis;
    gasta[gastaNum].price = 0;
    sort(gasta, gasta + gastaNum, cmp);

    if (gasta[0].dis != 0) printf("The maximum travel distance = 0.00\n");
    else {
        int i;
        double longestDest = tankCap * avgD;
        for (i = 0; i < gastaNum;) {
            int j, minPriceStation = i;
            double minPrice = INF;
            bool cheap = false;
            for (j = i + 1; j <= gastaNum; ++j) {            // �ҵ��������ܵ�����Զ�����ڵ�����˵ļ���վ
                if (longestDest >= gasta[j].dis - gasta[i].dis) {
                    if (gasta[i].price > gasta[j].price) {
                        minPrice = gasta[j].price;
                        minPriceStation = j;
                        cheap = true;
                        break;
                    }
                    else if (minPrice > gasta[j].price) {
                        minPrice = gasta[j].price;
                        minPriceStation = j;
                    }

                }
                else break;
            }

            if (i == minPriceStation && i < gastaNum) {              // ������Ҳ�Ҳ�������վ
                printf("The maximum travel distance = %.2lf\n", curDest + longestDest);
                break;
            }

            double togo = gasta[minPriceStation].dis - gasta[i].dis;
            if (cheap && curGas <= togo / avgD) {                                             // �ȵ�ǰ����վ������
                allCost += (togo / avgD - curGas) * gasta[i].price;
                curGas = togo / avgD;
            }
            else if (cheap == false) {                                      // �Ҳ���������
                allCost += (tankCap - curGas) * gasta[i].price;
                curGas = tankCap;
            }
            i = minPriceStation;
            curDest = gasta[i].dis;
            curGas -= togo / avgD;
        }
        if (i == gastaNum) printf("%.2lf\n", allCost);
    }

    return 0;
}
